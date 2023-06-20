#include "./../arvore.h"

// função da questão 13.4
int altura(NoArv* A) {
    if (arv_vazia(A)) return -1;
    else {
        int esq = altura(A->esq);
        int dir = altura(A->dir);

        if (esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

// função da questão 13.2
int qtd_nos(NoArv* A) {
    if (arv_vazia(A)) return 0;
    else return 1 + qtd_nos(A->esq) + qtd_nos(A->dir);
}

int eb(NoArv* A) {
    return qtd_nos(A) == (2 * (altura(A) + 1) - 1);
}

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* a5 = arv_cria(8, arv_criavazia(), arv_criavazia());
    NoArv* a = arv_cria(5, a2, a5);

    if (eb(a)) {
        printf("Estritamente binaria\n");
    } else {
        printf("Nao eh stritamente binaria\n");
    }
}
