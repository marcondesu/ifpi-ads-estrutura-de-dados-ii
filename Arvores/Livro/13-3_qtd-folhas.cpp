#include "./../arvore.h"

int qtd_folhas(NoArv* A) {
    if (arv_vazia(A)) return 0;
    else if (A->esq == NULL && A->dir == NULL) return 1;
    else return qtd_folhas(A->esq) + qtd_folhas(A->dir);
}

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), a1);
    NoArv* a3 = arv_cria(6, arv_criavazia(), arv_criavazia());
    NoArv* a4 = arv_cria(9, arv_criavazia(), arv_criavazia());
    NoArv* a5 = arv_cria(8, a3, a4);
    NoArv* a = arv_cria(5, a2, a5);

    printf("A arvore tem %d folhas\n", qtd_folhas(a));
}
