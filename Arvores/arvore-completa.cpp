#include "./arvore.h"
#include <cmath>

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

// 1 = incompleta | 0 = completa
int eh_completa(NoArv* A) {
    return altura(A) <= log(qtd_nos(A)) + 1;
}

int main() {
    NoArv* a1 = arv_cria(1, arv_cria(3, arv_criavazia(), arv_criavazia()), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* a3 = arv_cria(4, arv_cria(5, arv_criavazia(), arv_criavazia()), arv_cria(6, arv_criavazia(), arv_criavazia()));
    NoArv* a = arv_cria(0, a1, a2); // incompleta

    NoArv* b1 = arv_cria(1, arv_cria(3, arv_cria(6, arv_criavazia(), arv_criavazia()), arv_criavazia()), arv_criavazia());
    NoArv* b2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* b3 = arv_cria(4, arv_cria(5, arv_criavazia(), arv_criavazia()), arv_cria(6, arv_criavazia(), arv_criavazia()));
    NoArv* b = arv_cria(0, b1, b2); // completa

    cout << eh_completa(a) << " " << eh_completa(b);
}
