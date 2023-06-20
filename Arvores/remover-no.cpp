#include "./arvore.h"

// função da questão 13.2
int qtd_nos(NoArv* A) {
    if (arv_vazia(A)) return 0;
    else return 1 + qtd_nos(A->esq) + qtd_nos(A->dir);
}

// retorna o nó desejado
NoArv* achar_no(NoArv* A, int no_info) {
    if (A->info == no_info) {
        return A;
    } else {
        if (A->esq) achar_no(A->esq, no_info);
        if (A->dir) achar_no(A->dir, no_info);
    }
}

// remove o nó e seus filhos
void remover_no(NoArv* A, int no_info) {
    NoArv* aux = achar_no(A, no_info);

    arv_libera(aux);
}

int main() {
    NoArv *a2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* a3 = arv_cria(3, arv_criavazia(), arv_criavazia());
    NoArv* a1 = arv_cria(1, a3, arv_criavazia());
    NoArv* a = arv_cria(0, a1, a2);

    cout << qtd_nos(a);
    remover_no(a, 3);
    cout << qtd_nos(a);
}
