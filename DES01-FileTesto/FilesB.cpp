/** ****************************************************************************************
* \mainpage FilesB
*
* @brief programma che esegue la copia di un file di testo. Il programma legge carattere per carattere il contenuto del file in.txt e lo ricopia nel file out.txt. 

* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Luca Campion 4H
* @date <data> 
* @version 1.0 14/11/2022 Versione iniziale
*/

//inclusione delle librerie utili
#include <stdio.h>



int main()
{
	char nomeFileIN[]={"Input.txt"};	//Percorsi dei file
	char nomeFileOUT[]={"Output.txt"};
	char c;		//variabile d'appoggio
	FILE *fileIn, *fileOut;		//puntatori ai file
	fileIn=fopen(nomeFileIN,"r");	//apertura del file input in modalità read
	fileOut=fopen(nomeFileOUT,"a");		//apertura del file output in modalità append
	if(fileIn!=0 && fileOut!=0)		//Controllo che i file possano essere aperti
	{
		while(!feof(fileIn))		//ciclo while che esegue le istruzioni fino alla chiusura del file di input
		{
			c=fgetc(fileIn);		//legge il carattere dal file di input
			fputc(c,fileOut);		//scrive il carattere letto nel file output
		}
		fclose(fileIn);		//chiusura dei entrambi i file
		fclose(fileOut);
	}
	else	//se la condizione dell'if di sopra non è rispettata stampa un messaggio di errore
	{
		printf("\nErrore in apertura file!");
		printf("\n");
		return 0;	//fine programma
	}
}

