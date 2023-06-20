#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int valor) {
        this->valor = valor;
        esquerda = nullptr;
        direita = nullptr;
    }
};

class Arvore {
private:
    No* raiz;

    No* inserirRecursivo(No* no, int valor) {
        if (no == nullptr) {
            return new No(valor);
        }

        if (valor < no->valor) {
            no->esquerda = inserirRecursivo(no->esquerda, valor);
        } else if (valor > no->valor) {
            no->direita = inserirRecursivo(no->direita, valor);
        }

        return no;
    }

public:
    Arvore() {
        raiz = nullptr;
    }

    void inserir(int valor) {
        raiz = inserirRecursivo(raiz, valor);
    }

    void imprimirInOrdem(No* no) {
        if (no != nullptr) {
            imprimirInOrdem(no->esquerda);
            std::cout << no->valor << " ";
            imprimirInOrdem(no->direita);
        }
    }

    void imprimirArvore() {
        imprimirInOrdem(raiz);
        std::cout << std::endl;
    }

    No* buscarRecursivo(No* no, int valor) {
        if (no == nullptr || no->valor == valor) {
            return no;
        }

        if (valor < no->valor) {
            return buscarRecursivo(no->esquerda, valor);
        }

        return buscarRecursivo(no->direita, valor);
    }

    bool buscar(int valor) {
        No* resultado = buscarRecursivo(raiz, valor);
        return resultado != nullptr;
    }

    No* removerRecursivo(No* no, int valor) {
        if (no == nullptr) {
            return no;
        }

        if (valor < no->valor) {
            no->esquerda = removerRecursivo(no->esquerda, valor);
        } else if (valor > no->valor) {
            no->direita = removerRecursivo(no->direita, valor);
        } else {
            if (no->esquerda == nullptr) {
                No* temp = no->direita;
                delete no;
                return temp;
            } else if (no->direita == nullptr) {
                No* temp = no->esquerda;
                delete no;
                return temp;
            }

            No* temp = minimoValor(no->direita);
            no->valor = temp->valor;
            no->direita = removerRecursivo(no->direita, temp->valor);
        }

        return no;
    }

    void remover(int valor) {
        raiz = removerRecursivo(raiz, valor);
    }

    No* minimoValor(No* no) {
        No* atual = no;
        while (atual->esquerda != nullptr) {
            atual = atual->esquerda;
        }
        return atual;
    }

    void visit(No* no) {
        if (no != nullptr) {
            visit(no->esquerda);
            std::cout << no->valor << " ";
            visit(no->direita);
        }
    }

    void MorrisInOrder() {

    }
};

int main() {
    Arvore arvore;
    arvore.inserir(50);
    arvore.inserir(30);
    arvore.inserir(70);
    arvore.inserir(20);
    arvore.inserir(40);
}
