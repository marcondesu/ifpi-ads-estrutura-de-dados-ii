#include "./../arvore.h"

int busca(int x, NoArv* A) {
    if (arv_vazia(A)) return 0;
    if (x == A->info) return 1;
    if (x <= A->info) return busca(x, A->esq);
    else return busca(x, A->dir);
}

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), a1);
    NoArv* a3 = arv_cria(6, arv_criavazia(), arv_criavazia());
    NoArv* a4 = arv_cria(9, arv_criavazia(), arv_criavazia());
    NoArv* a5 = arv_cria(8, a3, a4);
    NoArv* a = arv_cria(5, a2, a5);

    int valor;

    printf("Valor buscado: ");
    scanf("%d", &valor);

    if (busca(valor, a)) {
        printf("\nValor encontrado\n");
    } else {
        printf("\nValor nao encontrado\n");
    }
}
