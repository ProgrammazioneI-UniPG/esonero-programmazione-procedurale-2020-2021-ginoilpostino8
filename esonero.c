#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int main() 
{
	int scelta, lunghezzam, lunghezzak;
	time_t t;
	char cXOR[129], mXOR[129], plaintextM[129], k[129], app; // mi serve uno carattere in più per lo \0
	printf("inserire una stringa di massimo 128 caratteri:");

	fgets(plaintextM,129,stdin); // fgets legge len-1 e aggiunge \0
	lunghezzam = strlen(plaintextM);
	
	if( plaintextM[lunghezzam-1] == '\n' ) 
		{ //qui lo stream è vuoto
		plaintextM[lunghezzam-1]='\0'; //inserisco il carattere di terminazione \0 al posto dello \n per escludere lo \n dal plaintext
		lunghezzam--;
		}
	else { //qui lo stream è pieno
		while((app=getchar()) != '\n' && app !=EOF)
			; //il corpo del while è vuoto
		}
				
	printf( "la stringa inserita è: %s\n",plaintextM );
	printf("la lunghezza della stringa inserita è: %d caratteri\n", lunghezzam);
	
	printf("\n1)inserire (1) per inserire da tastiera la chiave di cifratura k\n2)inserire (2) per avere una chiave k casuale\n");
	scanf("%d",&scelta);
	getchar(); //tolgo dallo stream lo \n inserito da tastiera
	printf("la sua scelta è:%d\n", scelta);

	switch (scelta) 
	{
	   case 1:
		  do  {
			  printf("\ninserire una chiave k da tastiera di lunghezza maggiore uguale del plaintext e minore uguale di 128 per cifrare il testo plaintext:\n");
			  
			  fgets(k,129,stdin);
			  lunghezzak = strlen(k);
			  if( k[lunghezzak-1] == '\n' ) 
				{ //qui lo stream è vuoto
				k[lunghezzak-1]='\0'; //inserisco il carattere di terminazione \0 al posto dello \n per escludere lo \n dal plaintext
				lunghezzak--;
				}
			  else  { //qui lo stream è pieno
			  	while((app=getchar()) != '\n' && app !=EOF)
			  		;
			  	}
		  	}
		  while ( lunghezzak < lunghezzam );
		  printf("la chiave k scelta è:\n%s\n", k);
		  printf("ed è lunga:%d\n", lunghezzak);
		  break;

	   case 2:
		  
		  srand((unsigned) time(&t));
                  printf("la chiave casuale è:\n");
		  for(int i=0;i < lunghezzam; i++) {
		     k[i]=(rand() % 95)+32; // mi genera solo i caratteri da 32 a 126 (escludendo i caratteri speciali)
		     printf("%c", k[i]); }
		  printf("\n");
		  
		  break;

	   default:
	   printf("\nnon sono ammessi scelte diverse da 1 o 2, il programma termina\n");
	   return 0;
	}
	printf("il testo cifrato è(non tutti i caratteri sono mostrabili a schermo):\n");
	for(int i=0; i < lunghezzam; i++)
	{
		cXOR[i] = plaintextM[i] ^ k[i];
		printf("%c",cXOR[i]);
	}
	printf("\n");
	printf("lo xor del testo cifrato con la chiave k è uguale al plaintext e infatti:\n");
	for(int i=0; i < lunghezzam; i++)
	{
		mXOR[i] = cXOR[i] ^ k[i];
		printf("%c",mXOR[i]);
	}
	printf("\n");
	return 0; 
}

