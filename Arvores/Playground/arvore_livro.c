#include <stdlib.h>
#include <stdio.h>
#define fmt "%d"
#define MAX 100
#define avanca(i) (i = (i + 1) % F->max)

typedef int Item; // o tipo de Item deve ser compatível com "fmt" (int Item, fmt = "%d")
typedef struct arv {
    struct arv *esq; // ponteiro para a subárvore da esquerda
    Item item; // item do tipo Item
    struct arv *dir; // ponteiro para a subárvore da direita
} *Arv;
// declarando uma variável do tipo "Arv": Arv minha_arvore;

typedef int Itemf;
typedef struct fila {
    int max;
    int total; // posição do topo
    int inicio; // posição do início
    int final; // posição do final
    Itemf *item; // itens da fila
} *Fila;

// Criar nó de árvore binária
Arv arv(Arv e, Item x, Arv d) {
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;

    return n;
}

// Criar fila
Fila fila(int m) {
    Fila F = malloc(sizeof(struct fila));
    F->max = m;
    F->total = 0;
    F->inicio = 0;
    F->final = 0;
    F->item = malloc(sizeof(Itemf));

    return F;
}

// Teste de fila vazia
int vaziaf(Fila F) {
    return (F->total == 0);
}

// Teste de fila cheia
int cheiaf(Fila F) {
    return (F->total == F->max);
}

// Adiciona um item ao final da fila
void enfileira(Itemf x, Fila F) {
    if (cheiaf(F)) {puts("Fila cheia!\n"); abort();}

    F->item[F->final] = x;
    avanca(F->final);
    F->total++;
}

// Retira um item ao início da fila
Itemf desenfileira(Fila F) {
    if (vaziaf(F)) {puts("Fila cheia!\n"); abort();}

    Itemf x = F->item[F->inicio];
    avanca(F->inicio);
    F->total--;

    return x;
}

void emnivel(Arv A) {
    if (A == NULL) return;

    Fila F = fila(MAX); // fila de Arv
    enfileira(A, F);

    while (!vaziaf(F)) {
        Arv A = desenfileira(F);

        printf(fmt, A->item);

        if (A->esq != NULL) enfileira(A->esq, F);
        if (A->dir != NULL) enfileira(A->dir, F);
    }
}

int main() {
    // árvore da figura 13.5
    Arv R = arv(arv(arv(NULL,
                        4,
                        NULL),
                    2,
                    arv(NULL,
                        5,
                        NULL)),
                1,
                arv(NULL,
                    3,
                    arv(NULL,
                        6,
                        NULL)));

    emnivel(R);
}
