#include <stdio.h>
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
	token.stav = S_START;
}


tToken getNextToken(void)
{
	//tStav stav = S_START;
	int i = 0;
	int c;
	bool stop = false;
	initToken();
	while(!stop)
	{
		   printf("aa\n");
		c = getc(&source);
		   printf("aa\n");
		strAddChar(token.data, c);
		//c = getc(source);
		//strAddChar(token.data, c);
		//int a = strGetLength(token.data);
		printf("delka %d\n", i);
		stop = true;
	}
	return token;
}
