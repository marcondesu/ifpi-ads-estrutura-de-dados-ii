#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct NoArv {
    char info;
    struct NoArv* esq;
    struct NoArv* dir;
};

typedef struct noArv NoArv;

NoArv* arv_criavazia(void) {
    return NULL;
}
// NoArv *root = arv_criavazia()
// NoArv *root = NULL;

NoArv* arv_cria(char c, NoArv* sae, NoArv* sad) {
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));

    if (p == NULL) exit(1);

    p->info = c;
    p->esq = sae;
    p->dir = sad;

    return p;
}

NoArv* arv_libera(NoArv* a);
int arv_vazia(NoArv* a);
int arv_pertence(NoArv* a, char c);
void arv_imprime(NoArv* a);


