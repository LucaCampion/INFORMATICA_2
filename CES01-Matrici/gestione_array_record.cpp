/* * * * * * * * * * * * * * * * * *
* 	Luca Campion 	4^H			   *
*   04/10/2022					   *
*	Gestione array di struct	   *
* * * * * * * * * * * * * * * * * */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define V 10
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

void carica(alunno []);
void stampa(alunno []);

int main()
{
	srand(time(NULL));
	alunno studenti [N];
	carica(studenti);
	stampa(studenti);
	
	return 0;
}

void carica(alunno st[])
{
	for(int i=0;i<N;i++)
	{
		printf("Inserisci numero matricola:\n");
		scanf("%d", &st[i].matricola);
		printf("Inserisci cognome della matricola:\n");
		scanf("%s", &st[i].cognome);
		printf("Inserisci giorno di nascita:\n");
		scanf("%d", &st[i].nascita.giorno);
		printf("Inserisci mese di nascita:\n");
		scanf("%s", &st[i].nascita.mese);
		printf("Inserisci anno di nascita:\n");
		scanf("%d", &st[i].nascita.anno);
		for(int j=0;j<V;j++)
			st[i].voti[j]=rand()%10+1;
	}
}

void stampa(alunno st[])
{
	for(int i=0;i<N;i++)
	{
		printf("\nMatricola %d", st[i].matricola);
		printf("\nCognome: %s", st[i].cognome);
		printf("\nNato il %d", st[i].nascita.giorno);
		printf(" %s", st[i].nascita.mese);
		printf(" %d", st[i].nascita.anno);
		printf("\nVoti:\t");
		for(int j=0;j<V;j++)
			printf("%d\t", st[i].voti[j]);
	}
}


