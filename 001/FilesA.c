/** ****************************************************************************************
* \mainpage FilesA
*
* @brief programma  che  legge  il  file  nomi.txt e  scrive  un  file  NOMI2.TXT,  dove  tutti  i  nomi  sono stati trasformati in caratteri maiuscoli.
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Luca Campion 4H
* @date <data> 
* @version 1.0 14/11/2022 Versione iniziale
*/

//Inclusione delle librerie utili
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main()
{
	char nomeFileIN[]={"nomi.txt"};//Percorsi dei file
	char nomeFileOUT[]={"NOMI2.txt"};
	char c;		//variabile d'appoggio
	FILE *fileIn, *fileOut;		//puntatori ai file
	fileIn=fopen(nomeFileIN,"r");	//apertura del file input in modalit� read
	fileOut=fopen(nomeFileOUT,"w");	//apertura del file output in modalit� write
	if(fileIn!=0 && fileOut!=0)		//Controllo che i file possano essere aperti
	{
		while(!feof(fileIn))		//ciclo while che esegue le istruzioni fino alla chiusura del file di input
		{
			c=fgetc(fileIn);		//acquisisce il carattere dal file di input
			if(c>='a'&&c<='z')		//controllo che il carattere letto sia una lettare minuscola
			c-=32;		//dimnuisco di 32 per avere la lettera maiuscola
			fputc(c,fileOut);		//inserisco il carattere letto nel file di output
		}
		fclose(fileIn);		//chiusura dei entrambi i file
		fclose(fileOut);
	}
	else	//se la condizione dell'if di sopra non � rispettata stampa un messaggio di errore
	{
		printf("\nErrore in apertura file!");
		printf("\n");
		return 0;	//fine programma
	}
}

