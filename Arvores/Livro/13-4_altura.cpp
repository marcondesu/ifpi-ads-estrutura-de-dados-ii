#include "./../arvore.h"

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

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), a1);
    NoArv* a3 = arv_cria(6, arv_criavazia(), arv_criavazia());
    NoArv* a4 = arv_cria(9, arv_criavazia(), arv_criavazia());
    NoArv* a5 = arv_cria(8, a3, a4);
    NoArv* a = arv_cria(5, a2, a5);

    printf("Altura da arvore: %d\n", altura(a));
}
