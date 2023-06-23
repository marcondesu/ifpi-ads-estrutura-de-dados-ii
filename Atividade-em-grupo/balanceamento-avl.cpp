#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
class ArvoreBalanceada {
public:
    No<T>* raiz;

    ArvoreBalanceada() {
        raiz = nullptr;
    }

    void inserir(T valor) {
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

    vector<T> getVetor() {
        vector<T> resultado;

        getVetorRecursivo(raiz, resultado);
        return resultado;
    }

    void getVetorRecursivo(No<T>* no, vector<T>& resultado) {
        if (no != nullptr) {
            getVetorRecursivo(no->esquerdo, resultado);
            resultado.push_back(no->info);
            getVetorRecursivo(no->direito, resultado);
        }
    }

    void balancear(vector<T>& vetor, int first, int last) {
        if (first <= last) {
            int middle = (first + last) / 2;

            inserir(vetor[middle]);
            balancear(vetor, first, middle - 1);
            balancear(vetor, middle + 1, last);
        }
    }

    void inOrder(No<T>* no) {
        if (no != nullptr) {
            inOrder(no->esquerdo);
            cout << no->info << " ";
            inOrder(no->direito);
        }
    }

    void apagarArvore(No<T>*& no) {
        if (no != nullptr) {
            apagarArvore(no->esquerdo);
            apagarArvore(no->direito);

            delete no;
            no = nullptr;
        }
    }

    int calcularAltura(No<T>* no) {
        if (no == nullptr) {
            return 0;
        } else {
            int alturaEsquerda = calcularAltura(no->esquerdo);
            int alturaDireita = calcularAltura(no->direito);
            return 1 + max(alturaEsquerda, alturaDireita);
        }
    }
};

int main() {
    ArvoreBalanceada<int> arv;
    arv.inserir(7);
    arv.inserir(8);
    arv.inserir(9);
    arv.inserir(10);
    arv.inserir(11);
    arv.inserir(12);
    arv.inserir(13);
    arv.inserir(14);

    cout << "Arvore: ";
    arv.inOrder(arv.raiz);
    int altura = arv.calcularAltura(arv.raiz);
    cout << "\nAltura da arvore: " << altura << endl;

    vector<int> arvoreVetor = arv.getVetor();

    cout << "\nArvore transformada em vetor: [";
    for (int i = 0; i < arvoreVetor.size(); i++) {
        if (i == arvoreVetor.size() - 1) {
            cout << arvoreVetor[i] << "]";
        } else {
            cout << arvoreVetor[i] << ", ";
        }
    }
    cout << endl;

    arv.apagarArvore(arv.raiz);
    cout << "\nArvore apagada!!";

    cout << "\nReconstruindo a arvore..." << endl;
    arv.balancear(arvoreVetor, 0, arvoreVetor.size() - 1);

    cout << "\nArvore: ";
    arv.inOrder(arv.raiz);
    altura = arv.calcularAltura(arv.raiz);
    cout << "\nAltura da arvore: " << altura;

    return 0;
}
