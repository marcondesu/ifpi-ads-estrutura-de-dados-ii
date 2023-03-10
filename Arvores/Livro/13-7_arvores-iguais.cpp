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

// função da questão 13.6
int eb(NoArv* A) {
    return qtd_nos(A) == (2 * (altura(A) + 1) - 1);
}

int elementos_iguais(NoArv* A, NoArv* B) {
    if (A->info == B->info) { // percorre a árvore inteira
        // caso houver filhos, percorre mais um nível
        if (A->esq && B->esq) {
            return elementos_iguais(A->esq, B->esq);
        }
        if (A->dir && B->dir) {
            return elementos_iguais(A->dir, B->dir);
        }
    } else { // se uma comparação der diferente, retorna 0
        return 0;
    }

    return 1;
}

int iguais(NoArv* A, NoArv* B) {
    int atributos_a[] = {altura(A), qtd_nos(A)};
    int atributos_b[] = {altura(B), qtd_nos(B)};

    // verifica se as duas possue mesma altura e quantidadede nós
    for (int i = 0; i < (sizeof(atributos_a) / sizeof(atributos_a[0])); i++) {
        if (atributos_a[i] != atributos_b[i]) {
            return 0;
        }
    }

    if (!elementos_iguais(A, B)) return 0; // se houver elementos diferentes retorna 0

    return 1;
}

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* a3 = arv_cria(3, a2, arv_criavazia());
    NoArv* a5 = arv_cria(1, arv_criavazia(), arv_criavazia());
    NoArv* a = arv_cria(5, a2, a5);
    NoArv* b = arv_cria(5, a2, a5);

    if (iguais(a, b)) {
        printf("Arvores iguais\n");
    } else {
        printf("Arvores diferentes\n");
    }
}
