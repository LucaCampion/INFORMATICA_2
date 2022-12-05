/** ****************************************************************************************
* \mainpage <Files5>
*
* @brief <>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <Luca Campion 4H>
* @date <data> 
* @version 1.0 <17/11/2022> Versione iniziale
*/

//Inclusione delle librerie utili
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main()
{
	char nomeFile[]={"Prova_File\\numeri.txt"};
	char nomeFilePari[]={"Prova_File\\pari.txt"};
	char nomeFileDispari[]={"Prova_File\\dispari.txt"};
	char c;
	FILE *file, *filePari, *fileDispari;
	/*printf("Inserire in nome del file da leggere : ");
	scanf("%s", nomeFileIN);
	printf("\nInserire il nome del file destinazione : " );
	scanf("%s", nomeFileOUT);*/
	file=fopen(nomeFile,"r");
	filePari=fopen(nomeFilePari,"a");
	fileDispari=fopen(nomeFileDispari,"a");
	if(file!=0 && filePari!=0&&fileDispari!=0)
	{
		while(!feof(file))
		{
			c=fgetc(file);
			if(c!=32&&c%2==0)
			fputc(c,filePari);
			else
			fputc(c,fileDispari);
		}
		fclose(file);
		fclose(filePari);
		flclose(fileDispari);
	}
	else
	{
		printf("\nErrore in apertura file!");
		printf("\n");
		system("pause");
	}
}

