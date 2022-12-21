/** ****************************************************************************************
* \mainpage file_binari
*
* @brief Scrivere un programma in c che dal main, tramite menu, richiami le seguenti funzioni per gestire un file di record con i campi cognome, data di nascita, e 8 voti.
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Luca Campion
* @date 1/12/2022 
* @version 1.0 <data> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

//Inclusione delle librerie utili

#include <stdio.h>
#include <stdlib.h>		
#include <string.h>

//Definizione dell costanti

#define N 5
#define V 8
#define C 100

//Definizione degli struct

struct s_data
{
	int giorno;
	char mese [C];
	int anno;
}typedef data;

struct s_alunno
{
	int matricola;
	char cognome [C];
	data nascita;
	int voti [V];
}typedef alunno;

//Definizione delle varie funzioni

int menuu(void);
void inserisciRecord(char [], int);
void stampaFile(char []);
int ricercaRecord(char [], char []);
int stampaRecord(char [], int );
int correggiRecord(char [], int );
int numeroRecord(char []);

int main()
{
	char nomeFile[]={"test.dat"};		//percorso del file
	int a, r, s; char cog[C];
	do
    {
		s=menuu();
		switch(s)
		{
			case 1:
				printf("Quanti record si desidera? Inserire un intero\n");
				scanf("%d", &a);
				inserisciRecord(nomeFile, a);
				break;
			case 2:
				stampaFile(nomeFile);
				break;
			case 3:
				printf("Inserire un cognome da ricercare\n");
				scanf("%s", cog);
				r=ricercaRecord(nomeFile, cog);
				if(r==-1)
				{
					printf("Record non trovato\n");
				}
				break;
			case 4:
				printf("\nDi quale record si vuole visualizzare le informazioni? Inserire la posizione\n");
				scanf("%d", &a);
				r=stampaRecord(nomeFile, a);
				if(r==-1)
				{
					printf("Record non trovato\n");
				}
				break;
			case 5:
				printf("\nDi quale record si vuole correggere le informazioni? Inserire la posizione\n");
				scanf("%d", &a);
				r=correggiRecord(nomeFile, a);
				if(r==-1)
				{
					printf("Record non trovato\n");
				}
				break;
			case 6:
				r=numeroRecord(nomeFile);
				if(r==-1)
				{
					printf("Nessun record non trovato\n");
				}
				printf("Nel file sono presenti %d record\n", r);
				break;
			case 0:
				printf("\nArrivederci!");				
				break;
			default:
				printf("Errore, inserire uno dei numeri dati!");	
				break;			
		}	
	}while(s!=0);
	return 0;
}

/** ****************************************************************************************
* @brief inserisce in coda n record con i dati richiesti all�utente. Se il file non esiste va creato e quindi effettuare l�inserimento.
* @param  char fileName[]: percorso del file, int numRecord: numero di struct
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 1/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int menuu(void)
{
	int x;
	printf("\n___________________________________________\n");
	printf("(1)	inserisciRecord\n");
	printf("(2)	stampaFile\n");
	printf("(3)	ricercaRecord\n");
	printf("(4)	stampaRecord\n");
	printf("(5)	correggiRecord\n");
	printf("(6)	numeroRecord\n");
	printf("(0)	Exit\n");
	printf("___________________________________________\n");
	scanf("%d",&x);
	return x;
}


/** ****************************************************************************************
* @brief inserisce in coda n record con i dati richiesti all�utente. Se il file non esiste va creato e quindi effettuare l�inserimento.
* @param  char fileName[]: percorso del file, int numRecord: numero di struct
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 1/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

void inserisciRecord(char fileName[], int numRecord)
{
	FILE *fp;	//puntatore al file
	alunno buffer;		//varaibile di tipo alunno(struct definito sopra) d'appoggio
	fp=fopen(fileName,"wb"); //apertura del file passato come parametro in modalit� write binary
	if(fp!=NULL) //controllo che il file possa essere aperto
	{
		for(int i=0;i<numRecord;i++) //inserimento dei dati che avviene numRecord volte
		{
			printf("\nInserire il cognome: ");
			scanf("%s", buffer.cognome);
			printf("\nInserire il numero matricola: ");
			scanf("%d", &buffer.matricola);
			printf("\nInserire il giorno di nascita: ");
			scanf("%d", &buffer.nascita.giorno);
			printf("\nInserire il mese di nascita: ");
			scanf("%s", buffer.nascita.mese);
			printf("\nInserire l'anno di nascita: ");
			scanf("%d", &buffer.nascita.anno);
			for(int j=0;j<V;j++)
			buffer.voti[j]=rand()%10+1;
			fwrite(&buffer, sizeof(buffer),1,fp);	//scrittura dei dati letti nel file passato come parametro
		}
	}
	fclose(fp);
}

/** ****************************************************************************************
* @brief Funzione che esegue la visualizzazione a schermo dei dati degli struct letti dal file passato come parametro
* @param  char fileName[]: percorso del file
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 1/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

void stampaFile(char fileName[])
{
	FILE *fp;		//puntatore al file
	alunno buffer;	//variabile di tipo alunno(struct definito sopra) d'appoggio
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in modalit� read binary
	if(fp!=NULL)//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finch� il file non � finito
		{
			int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
			if(n>0) //controllo che il record venga letto e evita che l'ultimo record venga stampato due volte
			{
				printf("Numero matricola: %d\t", buffer.matricola);
				printf("Cognome: %s\t", buffer.cognome);			
				printf("Giorno di nascita: %d\t", buffer.nascita.giorno);
				printf("Mese di nascita: %s\t", buffer.nascita.mese);
				printf("Anno di nascita: %d\t", buffer.nascita.anno);
				printf("\nVoti: ");
				for(int i=0;i<V;i++)
					printf("%d ", buffer.voti[i]);
				printf("\n");
			}
		}
		fclose(fp);	//chiusura del file
	}
	else//stampa messaggio di errore in caso iln file non viene trovato
	printf("Errore in apertura file");
}

/** ****************************************************************************************
* @brief per ogni record che ha il contenuto del campo cognome uguale al parametro, stampa cognome, et� e media dei voti. 
* @param  char fileName[]: percorso del file, char cognome[]: cognome da ricercare
* @retval La funzione restituisce la posizione del primo record trovato.
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 19/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int ricercaRecord(char fileName[], char cognome[])
{
	FILE *fp;
	alunno buffer;
	float media;
	fp=fopen(fileName,"rb");
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finch� il file non � finito
		{
			int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
			if(n>0)//controllo che il record venga letto e evita che l'ultimo record venga stampato due volte
			{
				int k=strcmp(buffer.cognome, cognome); //funzione per il confronto di due stringhe che restituisce 0 in caso le due stringhe siano uguali
				if(k==0) //controllo che le due stringhe siano uguali
				{
					int age=2022-buffer.nascita.anno; //calcolo dell'et�
					printf("Cognome: %s\t", buffer.cognome); 
					printf("Eta': %d\t", age);
					for(int i=0;i<V;i++)	//calcolo della media
					{
						media+=buffer.voti[i];
					}
					media/=V;
					printf("Media: %.2f", media);					
				}
			}
		}
		fclose(fp);	//chiusura del file
		return 1;	//si presume che la posizione del primo record sia 1
	}
	else //stampa messaggio di errore in caso il file non viene trovato
	{
		printf("Errore in apertura file");
		return -1;
	}
}

/** ****************************************************************************************
* @brief stampa le informazioni presenti nel record specificato dal parametro posizione. 
* @param char fileName[]: percorso del file, int posizione: indica la posizione di un record
* @retval Restituisce 0 se il record � presente -1 altrimenti
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 19/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int stampaRecord(char fileName[], int posizione)
{
	FILE *fp;		//puntatore al file
	alunno buffer;	//variabile di tipo alunno(struct definito sopra) d'appoggio
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in modalit� read binary
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		fseek(fp,posizione*sizeof(buffer),SEEK_SET);	
		int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
		if(n>0)//controllo che il record venga letto 
		{
			printf("Numero matricola: %d\t", buffer.matricola);
			printf("Cognome: %s\t", buffer.cognome);			
			printf("Giorno di nascita: %d\t", buffer.nascita.giorno);
			printf("Mese di nascita: %s\t", buffer.nascita.mese);
			printf("Anno di nascita: %d\t", buffer.nascita.anno);
			printf("\nVoti: ");
			for(int i=0;i<V;i++)
				printf("%d ", buffer.voti[i]);
			printf("\n");
			fclose(fp);
			return 0;
		}
		else
	{
		return -1;
	}			
	}
	else
	{
		printf("Errore in apertura file");
		return -1;
	}	
}

/** ****************************************************************************************
* @brief visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l�intero record, con i nuovi dati richiesti all�utente.
* @param char fileName[]: percorso del file, int posizione: indica la posizione di un record
* @retval Restituisce 0 se il record � presente -1 altrimenti
* @see See Also: viene richiamata la funzione stampaRecord
*
* @author Luca Campion
* @version 1.0 21/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int correggiRecord(char fileName[], int posizione)
{
	FILE *fp;		//puntatore al file
	alunno buffer;	//variabile di tipo alunno(struct definito sopra) d'appoggio
	fp=fopen(fileName,"rb+");	//apertura del file passato come parametro in modalit� read binary
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		fseek(fp,posizione*sizeof(buffer),SEEK_SET);	
		int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
		int r=stampaRecord(fileName, posizione);
		if(n>0)//controllo che il record venga letto
		{
			printf("\nInserire il cognome: ");
			scanf("%s", buffer.cognome);
			printf("\nInserire il numero matricola: ");
			scanf("%d", &buffer.matricola);
			printf("\nInserire il giorno di nascita: ");
			scanf("%d", &buffer.nascita.giorno);
			printf("\nInserire il mese di nascita: ");
			scanf("%s", buffer.nascita.mese);
			printf("\nInserire l'anno di nascita: ");
			scanf("%d", &buffer.nascita.anno);
			for(int j=0;j<V;j++)
			buffer.voti[j]=rand()%10+1;
			fwrite(&buffer, sizeof(buffer),1,fp);	//scrittura dei dati letti nel file passato come parametro
			fclose(fp);
			
			return 0;
	    }
	    else
	    return -1;		 		
	}
	else
	{
		printf("Errore in apertura file");
		return -1;
	}	
}

/** ****************************************************************************************
* @brief Funzione che restituisce il numero di record presenti nel file.
* @param char fileName[]: percorso del file
* @retval numero di record presenti nel file.
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 21/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int numeroRecord(char fileName[])
{
	FILE *fp;		//puntatore al file
	int cont=0;
	alunno buffer;	//variabile di tipo alunno(struct definito sopra) d'appoggio
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in modalit� read binary
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finch� il file non � finito
		{
			int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
			if(n>0)//controllo che il record venga letto
			{
				cont++;
			}			
		}
		fclose(fp);	//chiusura del file
		return cont;	//restituisce il numero di record presenti nel file
	}
	else
	{
		printf("Errore in apertura file");
		return -1;
	}
}