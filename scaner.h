#define LEX_ERROR 1

//stavy KA
typedef enum
{
	S_START = 100,	//00
	S_EOF,			//01
	S_ID_CROSS,		//02 ROZCESTI PRO IDENTIFIKATORY
	S_BOOLEAN, 		//03
	S_D_TYPE, 		//04
	S_KEY_WORD,		//05
	S_IDENTIF,		//06
	S_COMMENT_BEGIN,//07 ZAČÁTEK KOMENTU
	S_COMMENT,		//08 {}
	S_SEMICOL,		//09 ;
	S_PLUS,			//10 +
	S_MINUS,		//11 -
	S_MULTI,		//12 *
	S_DIV,			//13 /
	S_LESS_CROSS,	//14 ZAČÁTEK <
	S_NOT_EQUAL,	//15 <> 
	S_LESS_EQUAL,	//16 <=
	S_LESS, 		//17 <
	S_BIG_CROSS,	//18 ZAČÁTEK >
	S_BIG_EQUAL,	//19 >=
	S_BIG,			//20 >
	S_COLON_CROSS,	//21 ZAČÁTEK :
	S_ASSIGMENT,	//22 :=
	S_COLON,		//23 :
	S_L_BRACKET,	//24 (
	S_R_BRACKET,	//25 )
	S_COMMA,		//26 ,
	S_DOT,			//27 .
	S_NUMBER_CROSS,	//28 ROZCESTNIK PRO CISLA
	S_INTEGER,		//29
	S_DOUBLE,		//30
	S_STRING,		//31
	S_APOST_CROSS	//32 '
}tStav;

typedef struct
{
	int stav;
	string data;
}tToken;

extern tToken token;


void setSourceFile(FILE *f);
int getNextToken();
void initToken(void);   
