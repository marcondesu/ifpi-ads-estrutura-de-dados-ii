#include <iostream>

using namespace std;

template <class T>
class No {
public:
    T info;
    No* esquerdo;
    No* direito;

    No(T value) {
        info = value;
        esquerdo = nullptr;
        direito = nullptr;
    }
};

template <class T>
class Arvore {
public:
    No<T>* raiz;
    
    Arvore() {
        raiz = nullptr;
    }

    void insere(T valor) {
        No<T>* novo_no = new No<T>(valor);

        if (raiz == nullptr) {
            raiz = novo_no;
        } else {
            No<T>* percorre = raiz;
            
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

    void imprimir(No<T>* no) {
        if (no != nullptr) {
            imprimir(no->esquerdo);
            cout << no->info << " ";
            imprimir(no->direito);
        }
    }

    int altura(No<T>* no) {
        if (no == nullptr) {
            return 0;
        }

        int altura_esquerda = altura(no->esquerdo);
        int altura_direita = altura(no->direito);

        return 1 + max(altura_esquerda, altura_direita);
    }

    int qtd_nos(No<T>* no) {
        if (no == nullptr) {
            return 0;
        }

        return 1 + qtd_nos(no->esquerdo) + qtd_nos(no->direito);
    }

    void criar_backbone() {
        No<T>* current = raiz;
        No<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->esquerdo != nullptr) {
                rotacionar_direita(current, prev);

                current = prev->direito;
            } else {
                prev = current;
                current = current->direito;
            }
        }
    }

    void rotacionar_direita(No<T>*& no, No<T>*& prev) {
        No<T>* filho_esquerdo = no->esquerdo;
        no->esquerdo = filho_esquerdo->direito;
        filho_esquerdo->direito = no;

        if (prev != nullptr) {
            prev->direito = filho_esquerdo;
        } else {
            raiz = filho_esquerdo;
        }
    }
};

int main() {
    Arvore<int> arv;

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
    
    arv.criar_backbone();
    cout << "\n\n1.5) ";
    arv.imprimir(arv.raiz);

    cout << "(" << arv.altura(arv.raiz) << " de altura e ";
    cout << arv.qtd_nos(arv.raiz) << " nos)";
    
    return 0;
}

/*

Perguntas e respostas:

1) Inclua os seguintes valores na seguinte ordem em uma árvore binária: 7, 22, 14, 40, 63, 80.
1.1) Qual a altura da árvore resultante?
    A árvore possui 5 de altura.

1.2) Mostre a árvore resultante.
    Utilizando o método imprimir, obtemos o seguinte resultado: "7 14 22 30 40 63 80".

1.3) A árvore resultante está balanceada ou não?
    Não está.

1.4) Implemente a 1ª parte do algoritmo DSW, onde a resultante da árvore após as rotações deve ser uma árvore somente com filhos a esquerda.
    Método criar_backbone() na classe Arvore.

1.5) Mostre a árvore resultante.
    Linha 129. 

*/
