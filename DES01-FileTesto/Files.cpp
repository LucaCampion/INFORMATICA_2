#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main()
{
	char nomeFile[]={"C:\\Users\\luca.campion\\Documents\\C\\Prova_File\\Input.txt"};
	int err;
	char c;
	FILE *puntaFile;
	puntaFile=fopen(nomeFile,"r");
	if(err == 0)
	{
		while(!feof(puntaFile))
		{
			c=fgetc(puntaFile);
			printf("%c", c);
		}
		err=fclose(puntaFile);
	}
	else
	printf("\nIl file non puo' essere aperto!");
	printf("\n");
	system("pause");
}
