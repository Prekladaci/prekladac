#define LEX_ERROR 1

//stavy KA
typedef enum
{
	S_START, 		//00
	S_BOOLEAN, 		//01
	S_D_TYPE, 		//02
	S_KEY_WORD,		//03
	S_IDENTIF,		//04
	S_COMMENT,		//05 {}
	S_SEMICOL,		//06 ;
	S_PLUS,			//07 +
	S_MINUS,		//08 -
	S_STAR,	//09 *
	S_DIV,		//10 /
	S_NOT_EQUAL,	//11 <> 
	S_LESS_EQUAL,	//12 <=
	S_LESS, 		//13 <
	S_BIG_EQUAL,	//14 >=
	S_BIG, 		//15 >
	S_ASSIGMENT,	//16 :=
	S_COLON, 	//17 :
	S_L_BRACKET,	//18 (
	S_R_BRACKET,	//19 )
	S_INTEGER,		//20
	S_DOUBLE,		//21
	S_STRING,		//22
	S_EOF,			//23
	S_DOT,		//24 .
}tStav;

typedef struct
{
	tStav stav;
	string *data;
}tToken;

extern tToken token;


void setSourceFile(FILE *f);
tToken getNextToken(void);
void initToken(void);   
