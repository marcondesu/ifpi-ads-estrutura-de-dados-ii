#include <iostream>
using namespace std;

class No {
public:
    int info;
    No* esquerdo;
    No* direito;

    No(int value) {
        info = value;
        esquerdo = nullptr;
        direito = nullptr;
    }
};

class ArvoreBinaria {
public:
    No* raiz;
    
    ArvoreBinaria() {
        raiz = nullptr;
    }

    void insere(int valor) {
        No* novo_no = new No(valor);

        if (raiz == nullptr) {
            raiz = novo_no;
        } else {
            No* percorre = raiz;
            
            while (percorre != nullptr) {
                if (percorre->info < novo_no->info) {
                    if (percorre->direito == nullptr) {
                        percorre->direito = novo_no;
                        break;
                    } else {
                        percorre = percorre->direito;
                    }
                } else {
                    if (percorre->esquerdo == nullptr) {
                        percorre->esquerdo = novo_no;
                        break;
                    } else {
                        percorre = percorre->esquerdo;
                    }
                }
            }
        }
    }

    void rotacionar_direita(No** p) {
        No* q = (*p)->esquerdo;
        No* temp = q->direito;
        cout << "teste" << endl;

        q->direito = (*p);
        (*p)->esquerdo = temp;
        (*p) = q;
    }

    
    void rotacionar_esquerda(No* p) {
        cout << "teste" << endl;
        No* q = p->direito;
        No* temp = q->esquerdo;

        q->esquerdo = p;
        p->direito = temp;
        p = q;
    }

    void imprimir(No* no) {
        if (no != nullptr) {
            imprimir(no->esquerdo);
            cout << no->info << " ";
            imprimir(no->direito);
        }
    }
};

int main() {
    ArvoreBinaria arv;

    arv.insere(2);
    arv.insere(3);
    arv.insere(4);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);

    arv.rotacionar_direita(&(arv.raiz->direito));
    
    arv.imprimir(arv.raiz);
    // cout << arvore.altura(arvore.raiz) << endl;

    return 0;
}

/*

Atividade Balanceamento 1:

1) Inclua os seguintes valores na seguinte ordem em uma árvore binária: 7, 6, 22, 14, 40, 63.
1.1) Qual a altura da árvore resultante?
    A árvore possui 5 de altura.

1.2) Mostre a árvore resultante.
    Utilizando o método imprimir, obtemos o seguinte resultado: 6 7 14 22 40 63

1.3) A árvore resultante está balanceada ou não?
    Não está.

1.4) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de reordenação dos dados para balancear a árvore.
OBS: Use um método sort para ordenar o vetor resultante.
    

1.5) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de reordenação dos dados para balancear a árvore.
OBS: Aplique o percurso in-order para montar o vetor resultante.


1.6) Compare os resultados em 1.4 e 1.5. As árvores resultantes estão balanceadas? Elas são
iguais?

*/
