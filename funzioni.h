/*Questa struct contiene 5 dati tra int e char */
struct oggetto {
    int codice;
    char *nome;
    char *tipo;
    float prezzo;
    int quantita;
};

typedef struct oggetto Oggetto; /*Definiamo la Struct oggetto col  nome Oggetto*/

void visualizza (Oggetto [],float *,int);
void visualizza_ss(Oggetto [],int);
void acquista (Oggetto [],float *,int);
void vendi (Oggetto [],float *,int);
void sotto_sco (Oggetto [],int);
void ord_sel_min(Oggetto [],int);
void min_val_ind (Oggetto [], int n, double *, int *);
void scambiare_c(Oggetto [], Oggetto []);
void settore(Oggetto [],int);

