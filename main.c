#include "funzioni.h"

void main()
{
    float budget=50; /*Questo sarà il budget iniziale del magazzino per gli acquisti*/
    int x;      /*Questa variabile utilizzata nella switch */

    /*Ora verranno definiti i 20 tipi di dato Oggetto,codice,nome,tipo,prezzo e quantità*/

    Oggetto merce [20] ={{0,"Tubo        ","IDRAULICA",10,4},
                         {1,"Pompa    ","IDRAULICA",0.5,20},
                         {2,"Pinza       ","IDRAULICA",12,8},
                         {3,"Rubinetto    ","IDRAULICA",4,6},
                         {4,"Guarnizione ","IDRAULICA",1,25},
                         {5,"Doccino      ","IDRAULICA",3,10},
                         {6,"Cazzuola    ","MURATURA",8,3},
                         {7,"Calce       ","MURATURA",3,40},
                         {8,"Cacciaviti  ","MURATURA",3,12},
                         {9,"Martello    ","MECCANICA",6.5,4},
                         {10,"Brugola   ","MECCANICA",2,2},
                         {11,"Chiave      ","MECCANICA",10,12},
                         {12,"Rondelle    ","MECCANICA",0.2,35},
                         {13,"Colla       ","CHIMICA",14,1},
                         {14,"Provetta    ","CHIMICA",1,25},
                         {15,"Guanti      ","CHIMICA",12,10},
                         {16,"Ago         ","TESSILE",1,24},
                         {17,"Spago       ","TESSILE",3,14},
                         {18,"Seta        ","TESSILE",3,23},
                         {19,"Forbici     ","TESSILE",4,4},

    };


    printf("Benvenuti nel magazzino \n");
    printf("Ecco i prodotti \n");
    system("Pause");
    visualizza(merce,&budget,20);   /*Vengono passati la struct merce, l'indirizzo del budget e il numero di oggetti*/
/*Parte il ciclo  che terminerà solo con inserimento di 5 alla domanda di cosa si voglia fare*/
    do
    {

    printf("\nChe cosa vuoi fare?");
    printf("\n0.Visualizza le Scorte\n1.Acquistare\n2.Vendere\n3.Dati Sotto Scorta\n4.Visualizza Settori\n5.Esci\nScelta Nr:");

    scanf("%d",&x);     /*Viene inserito in X il numero inserito e di conseguenza inserito nel ciclo Switch*/
    switch (x)
    {
        /*Ad ogni caso da 0 a 5 verrà assegnata una funzione che svolgerà l'operazione desiderata*/
        case 0:visualizza(merce,&budget,20);break;
        case 1:acquista(merce,&budget,20);break;
        case 2:vendi(merce,&budget,20);break;
        case 3:ord_sel_min(merce,20);break;
        case 4:settore(merce,20);break;
        case 5:printf("Arrivederci e a presto!!");break;
        default:printf("Inserimento Errato");break;
    }
    }
    while (x!=5);   /*Questo comando fa terminare il ciclo swicth quando viene inserito il valore 5 alla domanda "Che cosa vuoi fare?",
                    */
                    system("Pause");
}
