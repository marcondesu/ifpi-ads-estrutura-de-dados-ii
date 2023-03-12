#include <iostream>

using namespace std;

class No {
    public:
        char nome;
        No *left;
        No *right;

        No(char n) {
            nome = n;
            left = NULL;
            right = NULL;
        }
};

class Arvore {
    public:
        No *raiz;
    
    Arvore() {
        raiz = NULL;
    }

    int isEmpty() {
        return raiz == NULL;
    }

    int isBinariaCheia(No *no) {
        if (qtd_nos(raiz) <= 3) return qtd_nos(no) == (2 * (altura(no)) - 1);
        else return qtd_nos(no) == (2 * (altura(no) + 1) - 1);
    }

    int altura(No *no) {
        if (no == NULL) return 0;
        else {
            int esq = altura(no->left);
            int dir = altura(no->right);

            if (esq > dir) {
                return esq + 1;
            } else {
                return dir + 1;
            }
        }
    }

    int qtd_nos(No *no) {
        if (no == NULL) return 0;
        else return 1 + qtd_nos(no->left) + qtd_nos(no->right);
    }

    void cria_no(char nov) {
        No *novo = new No(nov);
        raiz = novo;
    }

    void cria_no(char nov, int lado, char pai) {
        No *novo = new No(nov);
        insere(raiz, novo, lado, pai);
    }

    void insere(No *arv, No *novo, int lado, char pai) {
        if (arv->nome == pai) { // se o nó atual é o nó pai
            if (lado == 1) { // lado 1 = esquerda
                if (arv->left == NULL) arv->left = novo; // se o nó da esquerda estiver vazio, insere o filho
                else cout << "\nErro - Ja existe um no nessa posicao"; // caso contrário, não faz nada
            } else if (lado == 2) { // lado 2 = direita
                if (arv->right == NULL) arv->right = novo; // se o nó da direita estiver vazio, insere o filho
                else cout << "\nErro - Ja existe um no nessa posicao";
            }
        } else {
            // se houver mais nós, desce um nível
            if (arv->left) insere(arv->left, novo, lado, pai);
            if (arv->right) insere(arv->right, novo, lado, pai);
        }
    }
};

int main() {
    Arvore *arv = new Arvore();
    arv->cria_no('A');
    arv->cria_no('B', 1, 'A');
    arv->cria_no('C', 2, 'A');
    arv->cria_no('D', 1, 'B');
    arv->cria_no('E', 2, 'B');
    arv->cria_no('F', 1, 'C');
    arv->cria_no('G', 2, 'C');

    cout << arv->isBinariaCheia(arv->raiz);
}
