/** ****************************************************************************************
* \mainpage <Files4>
*
* @brief <Programma che conta i caratteri, le parole e le righe presenti in un file di testo>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <Luca Campion 4H>
* @date <data> 
* @version 1.0 <14/11/2022> Versione iniziale
*/

//Inclusione delle librerie utili
#include <stdio.h>




//Inizio main
int main()
{
	char nomeFile[]={"Prova_File\\Input.txt"};//Percorso del file di testo scelto
	int cont1=0, cont2=0, cont3=0;
	char c;
	FILE *puntaFile;//puntatore al file 
	puntaFile=fopen(nomeFile,"r"); //chiamata della funzione fopen per l'apertura del file in modalità append
	if(puntaFile!=0)//Controllo che il file possa essere aperto
	{
		while(!feof(puntaFile))//ciclo while che si chiude alla fine del file
		{
			c=fgetc(puntaFile);  //prende il carattere	
			if(c!=32&&c!='\0'&& c!='\n')
			{
			cont1++;
			}
				if(c==32||c=='\0'||c=='\n')// controllo se il carattere è uno spazio 
			{
				cont2++;
			}
			if(c=='\n')
			{
				cont3++;
			}
		}
		printf("I caratteri sono:%d\n Le parole sono:%d\n Le righe sono:%d\n",cont1,cont2,cont3);
		fclose(puntaFile);//dopo il ciclo chiusura del file con la funzione fclose
	}
	else//In questo caso il file non può essere aperto
	{
		printf("\nIl file non puo' essere aperto!");//Stampa a video dell' errore nella apertura
		printf("\n");
	}	
	return 0;//Fine programma
} 
