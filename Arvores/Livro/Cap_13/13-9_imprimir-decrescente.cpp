#include "./../arvore.h"
#include <queue>

// insere todos elementos de uma árvore numa fila
void povoar_fila(NoArv* A, queue<int> fila) {
    if (A->info) { // se a árvore A não estiver vazia
        fila.push(A->info);

        // caso houver filhos, percorre mais um nível
        if (A->esq) {
            return povoar_fila(A->esq, fila);
        }
        if (A->dir) {
            return povoar_fila(A->dir, fila);
        }
    }
}

// inserir os elementos da árvore numa fila e imprimi-la em seguida
/* void exibe_dec(NoArv* A) {
    queue<int> fila;
    int novo_elemento = A->info;



    if (fila.empty()) {
        fila.push(novo_elemento);
    } else {
        queue<int> fila_auxiliar;
        fila_auxiliar.push(fila.front()); // adiciona o item do início da fila original na auxiliar
        fila.pop() // remove o item do início da fila original

        while (!fila_auxiliar.empty()) {

        }
    }
} */

// 1, 2, 4, 6, 7, 9, 10
// 1, 

int main() {
    NoArv* a1 = arv_cria(0, arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria(2, arv_criavazia(), arv_criavazia());
    NoArv* a3 = arv_cria(3, a2, arv_criavazia());
    NoArv* a5 = arv_cria(1, arv_criavazia(), arv_criavazia());
    NoArv* a = arv_cria(5, a2, a5); // 5, 2, 1

    queue<int> fila;
    povoar_fila(a, fila);
    printf("%d", fila.empty());
    while (!fila.empty()) {
        printf("%d\n", fila.front());
        fila.pop();
    }
}
