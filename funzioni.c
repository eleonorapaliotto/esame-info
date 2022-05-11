#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

void acquista(Oggetto merce [],float *budget,int n) /*Questa procedura permette di acquistare merci, passando sempre la struct, il budget ed un intero n*/
{
    int x;  /* rappresentà il codice dell'oggetto da acquistare*/

    printf("Inserisci il codice del prodotto che vuoi acquistare (0-19)");
    scanf("%d",&x);

    if (x>=0 && x<20)    /*Se il numero inserito è compreso tra 0 e 20, verranno svolte le funzioni seguenti*/
    {

    if ((*budget-=merce[x].prezzo)>0)   /*Viene sottratto al budget il prezzo dell'oggetto con codice X, e se il budget
                                        è positivo, si procede con la transizione*/
    {
    merce[x].quantita++;                /*Viene incrementata la quantita dell'oggetto x*/

    printf("Hai acquistato 1 %s",merce[x].nome);    /*Viene visualizzata la merce acquistata e il budget rimanente*/
    printf("Budget: %.2f",*budget);
    }

    else            /*Se la sottrazione tra budget e prezzo della merce x è minore di 0, allora viene visualizzato un messaggio*/
    {
    printf("Non hai abbastanza fondi");

    /*Riaggiungiamo alla variabile budget il prezzo della merce x sottratto all'inizio dell'if*/
    *budget+=merce[x].prezzo;
    }
    }
    else
    printf("Codice non abbinato a nessun oggetto");
}

/*funzione che permette la vendita degli oggetti*/

void vendi(Oggetto merce [],float *budget,int n)
{
    int x;
    printf("Inserisci il codice del prodotto che vuoi vendere (0-19)");
    scanf("%d",&x);
    if(x>=0 && x<20)
    {
    if ((merce[x].quantita)>0)  /*, viene controllata la disponibilità degli oggetti,
                                che deve essere > di 0 per essere venduti*/
    {
    merce[x].quantita--;        /*Viene decrementata la quantita degli oggetti di tipo x in */
    *budget+=merce[x].prezzo;   /*Viene aggiunto al budget il prezzo dell'oggetto di tipo x*/

    printf("Hai venduto 1 %s",merce[x].nome);
    printf("Budget:%.2f",*budget);
    }
    else
    {
    printf("Non hai abbastanza pezzi");
    }
    }
    else
    printf("Codice non abbinato a nessun oggetto");
}
void ord_sel_min (Oggetto merce[],int n)    /*Passiamo la struct merce e l'intero n*/
{
     int i, indice_min;
     double min_merce;

     /*Cominciamo il ciclo for i da 0 a 20*/
     for(i=0;i<n-1;i++)
     {
         min_val_ind(&merce[i], n-i, &min_merce, &indice_min); /*Attiviamo la funzione "min_val_ind", passando l'indirizzo dell'i-esima
                                                                merce, l'intero N - i, e gli indirizzi di "min_merce" e "indice_min"*/
         scambiare_c(&merce[i], &merce[indice_min+i]);      /*Attiviamo la funzione di scambio, passando l'i-esima merce sempre per indirizzo
                                                            e l'indirizzo della merce che si trova nella posizione "indice_min+i"*/
     }
     printf("Ecco i 5 prodotti sotto scorta\n");        /*Alla fine di tutte le operazioni, verranno visualizzati i 5 prodotti sotto scorta
                                                      */
     visualizza_ss(merce,5);
}

void min_val_ind (Oggetto merce[], int n, double *min_array, int *i_min) /*Ora ricaviamo il valore minimo */
{
     int i;
     *min_array = merce[0].quantita;    /*Assegniamo a min_array il primo elemento della struct merce secondo la quantità*/
     *i_min = 0;
     for (i=1;i<n;i++)

     if( *min_array > merce[i].quantita)
      {
*min_array = merce[i].quantita;
             *i_min =i;
      }
                                                /*Se il predicato della if non viene soddisfatto, non accade nulla e si esce dalla prodcedura*/
}

void scambiare_c(Oggetto c1[], Oggetto c2[])    /*Questa function ci permette di scambiare i valori della prima struttura con la seconda
                                                spostandoli dapprima in delle variabili d' "appoggio"*/

{
    float temp_prezzo; /*Vengono inizializzate delle variabili uguali a quelle presenti nella struct, solo che con nome temp_*/
    char *temp_nome;
    char *temp_tipo;
    int temp_quantita;

    /*Questa serie di operazioni sposteranno i valori in questo modo:
    Da "c1" i valori passano nella variabile "temp" (specifica per ogni tipo di dato);
    Da "c2" i valori passano a "c2";
    Da "temp" i valori vanno a "c2";
    Se non utilizzasimo la variabile temp, ci sarebbe la perdita dei valori,
    più esattamente, passando da "c1" a "c2", perderemmo i valori che si trovavano in "c2"*/

     temp_nome= c1->nome;
     temp_tipo=c1->tipo;
     temp_prezzo= c1->prezzo;
     temp_quantita=c1->quantita;

     c1->nome = c2->nome;
     c1->prezzo = c2->prezzo;
     c1->tipo = c2->tipo;
     c1->quantita = c2->quantita;

     c2->nome = temp_nome;
     c2->prezzo = temp_prezzo;
     c2->tipo = temp_tipo;
     c2->quantita = temp_quantita;
}

void settore (Oggetto merce [], int n)  /*Ecco la funzione che dato un settore visualizza gli oggetti nel magazzino*/
{
    int i;

    char chiave[15];    /*Dichiariamo una variabile di char di lunghezza 15 che conterrà il tipo degli oggetti da visualizzare*/

    printf("Scrivi la chiave ");
    fflush(stdin);  /*La funzione fflush forza la scrittura dei dati,evitando che il valore sia NULL*/
    gets(chiave);   /*Acquisiamo la chiave*/
    strupr(chiave); /*Questa funzione all'interno della libreria "String.h" trasforma tutti i caratteri della stringa in maiuscoli*/

    for (i=0;i<n;i++)
    if (strcmp(merce[i].tipo,chiave) == 0)/*Vengono comparate le stringhe all'interno della struct merce di nome tipo con la stringa chiave,
                                        il comando "strcmp" e ci darà come valore di
                                        ritorno 0 se le due stringhe saranno identiche*/
    {
    printf("Codice:%2d Merce: %s Prezzo: %2.2f \tNr.: %d\n",merce[i].codice,merce[i].nome,merce[i].prezzo,merce[i].quantita);

    }
}
void visualizza(Oggetto merce [],float *budget,int n)
{
    int i;
    for (i=0;i<n;i++)
    printf("Codice:%2d Merce: %s Tipo: %s Prezzo: %2.2f \tNr.: %d\n",merce[i].codice,merce[i].nome,merce[i].tipo,merce[i].prezzo,merce[i].quantita);
    /*Con la scrittura merce[i].codice, indichiamo l'i-esimo elemento di tipo codice nella struct, e così via per gli altri tipi
    di variabili contenuti nella struct*/
    printf("Budget a disposizione:> %.f Euro",*budget);

}

void visualizza_ss(Oggetto merce [],int n)  /*Questa funzione visualizza le merci sotto scorta, gli vengono passate la struct ed un intero n*/
{
    int i;
    for (i=0;i<n;i++)
    printf("Codice:%2d Merce: %s Tipo: %s Prezzo: %2.2f \tNr.: %d\n",merce[i].codice,merce[i].nome,merce[i].tipo,merce[i].prezzo,merce[i].quantita);
}


