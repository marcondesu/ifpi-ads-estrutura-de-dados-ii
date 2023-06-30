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

    void imprimir(No* no) {
        if (no != nullptr) {
            imprimir(no->esquerdo);
            cout << no->info << " ";
            imprimir(no->direito);
        }
    }

    void rotacionar_direita(No** p) {
        No* q = (*p)->esquerdo;
        No* temp = q->direito;

        q->direito = (*p);
        (*p)->esquerdo = temp;
        (*p) = q;
    }

    
    void rotacionar_esquerda(No* p) {
        No* q = p->direito;
        No* temp = q->esquerdo;

        q->esquerdo = p;
        p->direito = temp;
        p = q;
    }

    int altura(No* no) {
        if (no == nullptr) {
            return 0;
        }

        int altura_esquerda = altura(no->esquerdo);
        int altura_direita = altura(no->direito);

        return 1 + max(altura_esquerda, altura_direita);
    }

    int qtd_nos(No* no) {
        if (no == nullptr) {
            return 0;
        }

        return 1 + qtd_nos(no->esquerdo) + qtd_nos(no->direito);
    }

    int maior_potencia2_menor_que_n(int n) {
        int potencia = 1;

        while (potencia * 2 < n) {
            potencia *= 2;
        }

        return potencia;
    }

    void balancear_dsw() { // rotações à direita até que a árvore fique desbalanceada
        No* atual = raiz;

        while (atual != nullptr) {
            if (atual->esquerdo != nullptr) {
                rotacionar_direita(&atual);
                atual = atual->direito;
            } else {
                atual = atual->direito;
            }
        }

        // rotações à esquerda para balancear a árvore
        int n = qtd_nos(raiz); // total de nós na árvore
        int m = maior_potencia2_menor_que_n(n + 1); // encontrar a maior potência de 2 menor que n + 1
        atual = raiz;

        for (int i = n - m; i > 0; i--) {
            rotacionar_esquerda(atual);

            if (atual->direito != nullptr) {
                atual = atual->direito;
            }
        }
    }
};

int main() {
    ArvoreBinaria arv;

    arv.insere(7);
    arv.insere(22);
    arv.insere(14);
    arv.insere(40);
    arv.insere(30);
    arv.insere(63);
    arv.insere(80);

    cout << "1.1) Altura: " << arv.altura(arv.raiz) << endl;

    cout << "\n1.2) ";
    arv.imprimir(arv.raiz);
    
    arv.balancear_dsw();
    cout << "\n\n1.5) ";
    arv.imprimir(arv.raiz); // altura errada
    
    return 0;
}

/*

Atividade Balanceamento 1:

1) Inclua os seguintes valores na seguinte ordem em uma árvore binária: 7, 22, 14, 40, 63, 80.
1.1) Qual a altura da árvore resultante?
    A árvore possui 5 de altura.

1.2) Mostre a árvore resultante.
    Utilizando o método imprimir, obtemos o seguinte resultado: 6 7 14 22 40 63

1.3) A árvore resultante está balanceada ou não?
    Não está.

1.4) Implemente a 1ª parte do algoritmo DSW, onde a resultante da árvore após as rotações deve ser uma árvore somente com filhos a esquerda.
    

1.5) Mostre a árvore resultante.

*/
