#include <iostream>
#include <cmath>

using namespace std;

/*
    Grupo: Cibelle Maciel
           Gabriel Oliver
           Marcos Vinícius    
*/

template <class T>
class No {
public:
    T info;
    No<T>* esquerdo;
    No<T>* direito;

    No(T valor) {
        info = valor;
        esquerdo = nullptr;
        direito = nullptr;
    }
};

template <class T>
class DSW {
public:
    No<T>* raiz;

    DSW() {
        raiz = nullptr;
    }

    void inserir(T valor) {
        raiz = inserirNo(raiz, valor);
    }

    No<T>* inserirNo(No<T>* no, T valor) {
        if (no == nullptr) {
            return new No<T>(valor);
        }

        if (valor < no->info) {
            no->esquerdo = inserirNo(no->esquerdo, valor);
        } else {
            no->direito = inserirNo(no->direito, valor);
        }

        return no;
    }

    void createBackbone() {
        No<T>* current = raiz;
        No<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->esquerdo != nullptr) {
                rotateRight(current, prev);
                current = prev->direito;
            } else {
                prev = current;
                current = current->direito;
            }
        }
    }

    void rotateRight(No<T>*& no, No<T>*& prev) {
        No<T>* filho_esquerdo = no->esquerdo;
        no->esquerdo = filho_esquerdo->direito;
        filho_esquerdo->direito = no;

        if (prev != nullptr) {
            prev->direito = filho_esquerdo;
        } else {
            raiz = filho_esquerdo;
        }
    }

    void balance() {
        int n = qtd_nos(raiz);
        int m = pow(2, floor(log(n + 1) / log(2))) - 1;

        createBackbone();

        for (int i = n - m; i > 0; i--) {
            rotateLeft(raiz);
        }
        
        while (m > 1) {
            m /= 2;
            rotateLeft(raiz);
        }
    }

    void rotateLeft(No<T>*& no) {
        No<T>* filho_direita = no->direito;
        no->direito = filho_direita->esquerdo;
        filho_direita->esquerdo = no;
        no = filho_direita;
    }


    int qtd_nos(No<T>* no) {
        if (no == nullptr) {
            return 0;
        }

        return 1 + qtd_nos(no->esquerdo) + qtd_nos(no->direito);
    }

    void inOrder(No<T>* no) {
        if (no != nullptr) {
            inOrder(no->esquerdo);
            cout << no->info << " ";
            inOrder(no->direito);
        }
    }

    void printInOrder() {
        inOrder(raiz);
        cout << endl;
    }
};

int main() {
    DSW<int> arv;

    arv.inserir(4);
    arv.inserir(2);
    arv.inserir(6);
    arv.inserir(1);
    arv.inserir(3);
    arv.inserir(5);
    arv.inserir(7);

    std::cout << "In-order antes de balancear: ";
    arv.printInOrder();
    
    arv.createBackbone();

    std::cout << "In-order depois de balancear: ";
    arv.printInOrder();

    return 0;
}

