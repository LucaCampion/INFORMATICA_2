/* * * * * * * * * * * * * * * * * *
* 	Luca Campion 	4^H			   *
*   04/10/2022					   *
*	Gestione array di struct	   *
* * * * * * * * * * * * * * * * * */ 
#include <stdio.h>
#include <stdlib.h>		//
#include <time.h>		//libreria per la generazione di numeri casuali

#define N 5
#define V 8
#define C 100

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

void carica2(alunno []);
void inserimento(alunno *);
void stampa(alunno []);
void media(alunno *);
void M_cog(alunno []);

int main()
{
	srand(time(NULL));
	alunno studenti [N];
	carica2(studenti);
	M_cog(studenti);
	stampa(studenti);
	
	return 0;
}


void stampa(alunno st[])		//funzione di stampa di alcuni campi dello struct
{
	for(int i=0;i<N;i++)
	{
		printf("\nMatricola: %d", st[i].matricola);
		printf("\nCognome: %s", st[i].cognome);
		printf("\nVoti:\t");
		for(int j=0;j<V;j++)
			printf("%d\t", st[i].voti[j]);
		media(&st[i]);
	}
}

void inserimento(alunno *st)		//funzione che carica uno struct
{
	printf("Inserisci numero matricola:\n");
	scanf("%d", &st->matricola);
	printf("Inserisci cognome della matricola:\n");
	scanf("%s", st->cognome);
	for(int i=0;i<V;i++)
	st->voti[i]=rand()%10+1;
}

void carica2(alunno st[])		//funzione di carica di un array di struct
{
	for(int i=0;i<N;i++)
	{
		inserimento(&st[i]);
	}
}

void media(alunno *st)		//funzione di calcolo per la media
{
	float tot, r;
	for(int i=0;i<V;i++)
	{
		tot+=st->voti[i];
	}
	r=tot/V;
	printf("\nMedia: %.1f", r);
}

void M_cog(alunno st[])
{
	int i, j=1;
	for(i=0;i<N;i++)
	{
		if(st[i].cognome[0]>'a' && st[i].cognome[0]<'z')
		st[i].cognome[0]-=32;
		while(st[i].cognome[j]!='\0')
		{
			if(st[i].cognome[j]>'A' && st[i].cognome[j]<'Z')
			st[i].cognome[j]+=32;
		}
		j++;
	}
}


