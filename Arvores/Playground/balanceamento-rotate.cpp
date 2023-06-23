#include <iostream>

using namespace std;

class No {
public:
    int info;
    int altura;
    No *esquerdo;
    No *direito;
};

int max(int a, int b);

// retorna a altura do nó informado
int altura(No *no) {
    if (no == NULL)
        return 0;
    
    return no->altura;
}

// ?????????????
int max(int a, int b) {
    return (a > b) ? a : b;
}

// retorna um nó com o valor informado
No *novo_no(int info) {
    No *node = new No();

    node->info = info;
    node->altura = 1;
    node->esquerdo = NULL;
    node->direito = NULL;

    return (node);
}

No *rightRotate(No *y) {
    No *x = y->esquerdo;
    No *t2 = x->direito;

    x->direito = y;
    y->esquerdo = t2;

    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;
    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;

    return x;
}

No *leftRotate(No *x) {
    No *y = x->direito;
    No *T2 = y->esquerdo;

    y->esquerdo = x;
    x->direito = T2;

    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;
    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;
    
    return y;
}

// retorna o fator de balanceamento do nó informado
int getBalanceFactor(No *N) {
    if (N == NULL)
        return 0;
    
    // subtrai a altura do nó da esquerda pela do nó da direita
    return altura(N->esquerdo) - altura(N->direito);
}

/*
    Utiliza recursividade para adicionar um novo nó
*/
No *insertNode(No *no, int info) {
    // encontra a posição ideal e insere o nó
    if (no == NULL)
        return (novo_no(info));

    if (info < no->info)
        no->esquerdo = insertNode(no->esquerdo, info);
    else if (info > no->info)
        no->direito = insertNode(no->direito, info);
    else
        return no;

    // atualiza o fator de balanceamento de cada nó e balanceia a árvore
    no->altura = 1 + max(altura(no->esquerdo), altura(no->direito)); // 1 + módulo da subtração da altura dos nós
    int fator_de_balanceamento = getBalanceFactor(no);
    
    if (fator_de_balanceamento > 1) {
        if (info < no->esquerdo->info) {
            return rightRotate(no);
        }
        else if (info > no->esquerdo->info) {
            no->esquerdo = leftRotate(no->esquerdo);
            return rightRotate(no);
        }
    }
    if (fator_de_balanceamento < -1) {
        if (info > no->direito->info) {
            return leftRotate(no);
        }
        else if (info < no->direito->info) {
            no->direito = rightRotate(no->direito);
            return leftRotate(no);
        }
    }
    return no;
}

No *nodeWithMimumValue(No *node) {
    No *current = node;
    while (current->esquerdo != NULL)
        current = current->esquerdo;
    return current;
}

No *deleteNode(No *root, int info) {
    if (root == NULL)
        return root;
    if (info < root->info)
        root->esquerdo = deleteNode(root->esquerdo, info);
    else if (info > root->info)
        root->direito = deleteNode(root->direito, info);
    else {
        if ((root->esquerdo == NULL) ||
            (root->direito == NULL)) {
            No *temp = root->esquerdo ? root->esquerdo : root->direito;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            No *temp = nodeWithMimumValue(root->direito);
            root->info = temp->info;
            root->direito = deleteNode(root->direito,
                                     temp->info);
        }
    }

    if (root == NULL)
        return root;

    // atualiza o fator de balanceamento de cada nó e balanceia a árvore
    root->altura = 1 + max(altura(root->esquerdo), altura(root->direito));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->esquerdo) >= 0) {
            return rightRotate(root);
        }
        else {
            root->esquerdo = leftRotate(root->esquerdo);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(root->direito) <= 0) {
            return leftRotate(root);
        }
        else {
            root->direito = rightRotate(root->direito);
            return leftRotate(root);
        }
    }
    return root;
}

void printTree(No *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        }
        else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->info << endl;
        printTree(root->esquerdo, indent, false);
        printTree(root->direito, indent, true);
    }
}

int main() {
    No *root = NULL;
    root = insertNode(root, 33);
    root = insertNode(root, 13);
    root = insertNode(root, 53);
    root = insertNode(root, 9);
    root = insertNode(root, 21);
    root = insertNode(root, 61);
    root = insertNode(root, 8);
    root = insertNode(root, 11);

    printTree(root, "", true);
    root = deleteNode(root, 13);

    cout << "After deleting " << endl;
    
    printTree(root, "", true);
}