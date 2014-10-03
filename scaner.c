#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <malloc.h>
#include "str.h"
#include "scaner.h"

FILE *source;
tToken token;

void setSourceFile(FILE *f)
{
	source = f;
}

void initToken(void)
{
	strInit(&token.data);
	strClear(&token.data); //aby ve stringu nebyl bordel
	token.stav = S_START;
}

int getNextToken()
{
	int c;
	initToken();
	while(1)
	{
		strClear(&token.data); //aby ve stringu nebyl bordel
		switch(token.stav)
		{
			case S_START:
			{
				c = getc(source);
				if(c == EOF)
					token.stav = S_EOF;
				else if ((isalpha(c)) || (c == '_'))
					token.stav = S_ID_CROSS;
				else if (c == '{')
					token.stav = S_COMMENT_BEGIN;
				else if (c == ';')
					return S_SEMICOL;
				else if (c == '+')
					return S_PLUS;
				else if (c == '-')
					return S_MINUS;
				else if (c == '*')
					return S_MULTI;
				else if (c == '/')
					return S_DIV;
				else if (c == '<')
					token.stav = S_LESS_CROSS;
				else if (c == '>')
					token.stav = S_BIG_CROSS;
				else if (c == ':')
					token.stav = S_COLON_CROSS;
				else if (c == '(')
					return S_L_BRACKET;
				else if (c == ')')
					return S_R_BRACKET;
				else if (c == ',')
					return S_COMMA;
				else if (c == '.')
					return S_DOT;
				else if (isdigit(c))
					token.stav = S_NUMBER_CROSS;
				else if (c == '\'')
					token.stav = S_APOST_CROSS;
				else if (isspace(c))
					token.stav = S_START;
				else
					return LEX_ERROR;
				break;
			}
			case S_EOF:
			{
				return S_EOF;
				break;
			}
			//case S_ID_CROSS
			case S_COMMENT_BEGIN:
			{
				while(1)
				{
					c = getc(source);
					if(c == EOF)
						return LEX_ERROR;
					else if (c == '}')
					{
						token.stav = S_START;
						break;
					}
				}
				break;

			}
			case S_LESS_CROSS:
			{
				c = getc(source);
				if(c == '>')
					return S_NOT_EQUAL;
				else if (c == '=')
					return S_LESS_EQUAL;
				else
				{
					ungetc (c, source);
					return S_LESS;
				}
				break;
			}
			case S_BIG_CROSS:
			{
				c = getc(source);
				if (c == '=')
					return S_BIG_EQUAL;
				else
				{
					ungetc (c, source);
					return S_BIG;
				}
				break;
			}
			case S_COLON_CROSS:
			{
				c = getc(source);
				if (c == '=')
					return S_ASSIGMENT;
				else
				{
					ungetc (c, source);
					return S_COLON;
				}
				break;
			}
		}
		/*
		strAddChar(&token.data, c);
		c = getc(source);
		int a = strGetLength(&token.data);
		printf("delka %d\n", a);
		strClear(&token.data);
		a = strGetLength(&token.data);
		printf("delka %d\n", a);*/
	}
	return EXIT_SUCCESS;
}
