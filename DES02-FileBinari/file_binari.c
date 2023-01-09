/** ****************************************************************************************
* \mainpage file_binari
*
* @brief Scrivere un programma in c che dal main, tramite menu, richiami le seguenti 
* funzioni per gestire un file di record con i campi cognome, data di nascita, e 8 voti.
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Luca Campion
* @date 1/12/2022 
* @version 1.0 1/12/2022 Versione iniziale
* @version 1.1 9/01/2023 Correzioni varie
*/

//Inclusione delle librerie utili
#include <stdio.h>
#include <stdlib.h>		
#include <string.h>

//Definizione dell costanti
#define NUM_VOTI 8
#define DIM_COGNOME 100

//Definizione delle struct
struct s_data
{
	int giorno;
	char mese[10];
	int anno;
} typedef data;

struct s_alunno
{
	int matricola;
	char cognome[DIM_COGNOME];
	data nascita;
	int voti [NUM_VOTI];
} typedef alunno;

/******************************************************************************************
//Definizione delle varie funzioni
/******************************************************************************************

/** ****************************************************************************************
* @brief Funzione che stampa a schermo il menù per la scelta delle funzioni
* @param nessuno 
* @retval nessuno
*
* @author Luca Campion
* @version 1.0 21/12/2022
*/
int menuu(void);

/** ****************************************************************************************
* @brief inserisce in coda n record con i dati richiesti all'utente. Se il file non esiste va creato e quindi effettuare l'inserimento.
* @param  char fileName[]: percorso del file, int numRecord: numero di struct
* @retval nessuno
* @see stampaRecord
*
* @author Luca Campion
* @version 1.0 1/12/2022
*/
void inserisciRecord(char [], int);

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
void stampaFile(char []);

/** ****************************************************************************************
* @brief per ogni record che ha il contenuto del campo cognome uguale al parametro, stampa cognome, età e media dei voti. 
* @param  char fileName[]: percorso del file, char cognome[]: cognome da ricercare
* @retval La funzione restituisce la posizione del primo record trovato. -1 in caso di errore nell'apertura del file
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 19/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
int ricercaRecord(char [], char []);

/** ****************************************************************************************
* @brief stampa le informazioni presenti nel record specificato dal parametro posizione. 
* @param char fileName[]: percorso del file, int posizione: indica la posizione di un record
* @retval Restituisce 0 se il record è presente -1 altrimenti
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 19/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
int stampaRecord(char [], int );

/** ****************************************************************************************
* @brief visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l'intero record, con i nuovi dati richiesti all'utente.
* @param char fileName[]: percorso del file, int posizione: indica la posizione di un record
* @retval Restituisce 0 se il record è presente -1 altrimenti
* @see See Also: viene richiamata la funzione stampaRecord
*
* @author Luca Campion
* @version 1.0 21/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
int correggiRecord(char [], int );

/** ****************************************************************************************
* @brief Funzione che restituisce il numero di record presenti nel file.
* @param char fileName[]: percorso del file
* @retval Restituisce numero di record presenti nel file. Restiuisce -1 in caso di errore
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 21/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
int numeroRecord(char []);

int main()
{
	char nomeFile[]={"test.dat"};	//percorso del file
	int a, r, s; 					
	char cog[DIM_COGNOME];			

	do
    {
		s=menuu();	//chiamata alla funzione menuu
		switch(s)	//controllo della scelta fatta dall'utente
		{
			case 1:	
				printf("Quanti record si desidera? Inserire un intero\n");
				scanf("%d", &a);
				inserisciRecord(nomeFile, a);	//chiamata della funzione inserisciRecord
				break;
			case 2:
				stampaFile(nomeFile);	//chiamata della funzione stampaFile
				break;
			case 3:
				printf("Inserire un cognome da ricercare\n");
				scanf("%s", cog);
				r=ricercaRecord(nomeFile, cog);		//chiamata della funzione ricercaRecord
				if(r!=1)	//controllo in caso il record non è stato trovato stampa messaggio di errore
				{
					printf("Record non trovato\n");
				}
				break;
			case 4:
				printf("\nDi quale record si vuole visualizzare le informazioni? Inserire la posizione\n");
				scanf("%d", &a);
				r=stampaRecord(nomeFile, a);	//chiamata della funzione stampaRecord
				if(r==-1)	//controllo in caso il record non è stato trovato stampa messaggio di errore
				{
					printf("Record non trovato\n");
				}
				break;
			case 5:
				printf("\nDi quale record si vuole correggere le informazioni? Inserire la posizione\n");
				scanf("%d", &a);
				r=correggiRecord(nomeFile, a);	//chiamata della funzione correggiRecord
				if(r==-1)	//controllo in caso il record non è stato trovato stampa messaggio di errore
				{
					printf("Record non trovato\n");
				}
				break;
			case 6:
				r=numeroRecord(nomeFile);	//chiamata della funzione numeroRecord
				printf("Nel file sono presenti %d record\n", r);
				break;
			case 0:		//chiusura del programma
				printf("\nArrivederci!");				
				break;
			default:	//stampa messaggio di errore in caso venga inserito qualcosa di non adeguato
				printf("Errore, inserire uno dei numeri dati!");	
				break;			
		}	
	}while(s!=0);
	return 0;
}

/** ****************************************************************************************
* @brief Funzione che stampa a schermo il menù per la scelta delle funzioni
* @param  
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 21/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int menuu(void)
{
	int x;
	printf("\n_________________________________________________________________\n");
	printf("Inserire uno dei seguenti numeri per la funzione desiderata: \n");
	printf("(1)	inserisciRecord\n");
	printf("(2)	stampaFile\n");
	printf("(3)	ricercaRecord\n");
	printf("(4)	stampaRecord\n");
	printf("(5)	correggiRecord\n");
	printf("(6)	numeroRecord\n");
	printf("(0)	Exit");
	printf("\n_________________________________________________________________\n");
	scanf("%d",&x);
	return x;
}


/** ****************************************************************************************
* @brief inserisce in coda n record con i dati richiesti all'utente. Se il file non esiste va creato e quindi effettuare l'inserimento.
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
	fp=fopen(fileName,"wb"); //apertura del file passato come parametro in writing binary mode
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
			for(int j=0;j<NUM_VOTI;j++)
			buffer.voti[j]=rand()%10+1;
			fwrite(&buffer, sizeof(buffer),1,fp);	//scrittura dei dati letti nel file passato come parametro
		}
	}
	fclose(fp);		//chiusura del file
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
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in reading binary mode
	if(fp!=NULL)//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finchè il file non è finito
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
				for(int i=0;i<NUM_VOTI;i++)
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
* @brief per ogni record che ha il contenuto del campo cognome uguale al parametro, stampa cognome, età e media dei voti. 
* @param  char fileName[]: percorso del file, char cognome[]: cognome da ricercare
* @retval La funzione restituisce la posizione del primo record trovato. -1 in caso di errore nell'apertura del file
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Luca Campion
* @version 1.0 19/12/2022
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

int ricercaRecord(char fileName[], char cognome[])
{
	FILE *fp;	//puntatore al file
	alunno buffer;	//variabile di tipo alunno(struct definito sopra) d'appoggio
	float media;	//variabile per il calcolo della media
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in reading binary mode
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finchè il file non è finito
		{
			int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
			if(n>0)//controllo che il record venga letto e evita che l'ultimo record venga stampato due volte
			{
				int k=strcmp(buffer.cognome, cognome); //funzione per il confronto di due stringhe che restituisce 0 in caso le due stringhe siano uguali
				if(k==0) //controllo che le due stringhe siano uguali
				{
					int age=2022-buffer.nascita.anno; //calcolo dell'età
					printf("Cognome: %s\t", buffer.cognome); 
					printf("Eta': %d\t", age);
					for(int i=0;i<NUM_VOTI;i++)	//calcolo della media
					{
						media+=buffer.voti[i];
					}
					media/=NUM_VOTI;
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
* @retval Restituisce 0 se il record è presente -1 altrimenti
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
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in reading binary mode
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		fseek(fp,posizione*sizeof(buffer),SEEK_SET);	//posiziono il puntatore sulla posizione desiderata	
		int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
		if(n>0)//controllo che il record venga letto 
		{
			printf("Numero matricola: %d\t", buffer.matricola);
			printf("Cognome: %s\t", buffer.cognome);			
			printf("Giorno di nascita: %d\t", buffer.nascita.giorno);
			printf("Mese di nascita: %s\t", buffer.nascita.mese);
			printf("Anno di nascita: %d\t", buffer.nascita.anno);
			printf("\nVoti: ");
			for(int i=0;i<NUM_VOTI;i++)
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
* @brief visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l'intero record, con i nuovi dati richiesti all'utente.
* @param char fileName[]: percorso del file, int posizione: indica la posizione di un record
* @retval Restituisce 0 se il record è presente -1 altrimenti
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
	fp=fopen(fileName,"rb+");	//apertura del file passato come parametro sia in reading che in writing binary mode
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		fseek(fp,posizione*sizeof(buffer),SEEK_SET);	//posiziono il puntatore sulla posizione desiderata
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
			for(int j=0;j<NUM_VOTI;j++)
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
* @retval Restituisce numero di record presenti nel file. Restiuisce -1 in caso di errore
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
	fp=fopen(fileName,"rb");	//apertura del file passato come parametro in reading binary mode
	if(fp!=NULL)	//controllo che il file possa essere aperto
	{
		while(!feof(fp))	//esegue le istruzioni finchè il file non è finito
		{
			int n=fread(&buffer, sizeof(buffer),1,fp);	//funzione di lettura per leggere i dati nel file
			if(n>0)//controllo che il record venga letto
			{
				cont++;	//incremento il contatore ogni volta che viene letto un record
			}			
		}
		fclose(fp);	//chiusura del file
		return cont;	//restituisce il numero di record presenti nel file
	}
	else
	{
		printf("Errore in apertura file");
		return -1;	//restiuisce -1 in caso di errore
	}
}

