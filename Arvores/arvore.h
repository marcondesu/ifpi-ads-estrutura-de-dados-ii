#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct noArv {
    int info;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv NoArv;

NoArv* arv_criavazia(void) {
    return NULL;
}

NoArv* arv_cria(int c, NoArv* sae, NoArv* sad) {
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    
    if (p == NULL) exit(1);

    p->info = c;
    p->esq = sae;
    p->dir = sad;

    return p;
}

int arv_vazia(NoArv* a) {
    return a == NULL;
}

NoArv* arv_libera(NoArv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }

    return NULL;
}

void arv_imprime(NoArv* a) {
    if (!arv_vazia(a)) {
        cout << a->info;

        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

int arv_pertence(NoArv* a, int c) {
    if (arv_vazia(a)) {
        return 0;
    } else {
        return a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
    }
}
