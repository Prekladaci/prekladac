#include <stdio.h>
#include "str.h"
#include "scaner.h"

#define INTERN_ERROR 99

int main(int argc, char** argv)
{
	FILE *f;
	if (argc != 2)
	{
		fprintf(stderr, "Spatny pocet parametru\n");
		return INTERN_ERROR;
	}
	if (argc == 1)
   {
      fprintf(stderr, "Neni zadan vstupni soubor\n");
      return INTERN_ERROR;
   }
   if ((f = fopen(argv[1], "r")) == NULL)
   {
      fprintf(stderr, "Soubor se nepodarilo otevrit\n");
      return INTERN_ERROR;
   }   
   setSourceFile(f);
   int tokenn=0;
   do
   {
      tokenn = getNextToken();  //TOHLE SE VOLA V PARSERU
      printf("token je: %d\n",tokenn);
   } while(tokenn != 101);


   /////////////////////////////////////////////////
   ////////////TADY PO SOBĚ UKLÍZÍME////////////////
   ////////////////////////////////////////////////
   strFree(&token.data); //uvolním řetezec
   fclose(f); //zavřeme soubor
	
   return 0;
}
