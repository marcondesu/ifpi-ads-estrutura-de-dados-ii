// questão 13.9 - busca binária em ordem decrescente

#include "atividade1.cpp"
#include <queue>
#include <algorithm>
#include <iostream>

queue<int> aux;

NoArv* exibe_dec(NoArv* raiz) {
    // caso base
    if (arv_vazia(raiz)) return raiz;
    else {
        while (!arv_vazia(raiz)){
            aux.push(raiz->info);
            aux.push(raiz->esq->info);
            aux.push(raiz->dir->info);
        }

        int tamanho = aux.size();
        int* vetor = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = aux.front();
            aux.pop();
        }

        // Ordena o vetor em ordem decrescente
        sort(vetor, vetor + tamanho, greater<int>());

        // Imprime os elementos do vetor em ordem decrescente
        for (int i = tamanho - 1; i >= 0; i--) {
            cout << vetor[i] << " ";
        }

        delete[] vetor;
        return 0;
    }
    }

    /*void percorrerEmOrdemDecrescente(NoArv* raiz) {
    if (!arv_vazia(raiz)) {
        percorrerEmOrdemDecrescente(raiz->dir); // Visita o filho direito
        cout << raiz->info << " "; // Visita o nó atual
        percorrerEmOrdemDecrescente(raiz->esq); // Visita o filho esquerdo
}
    }*/

    /*void reverse_inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    reverse_inorder(node->right);
    std::cout << node->value << " ";
    reverse_inorder(node->left);
}*/



int main(){
    NoArv* NoArv2 = arv_cria(2, nullptr, nullptr);
    NoArv* NoArv4 = arv_cria(4, nullptr, nullptr);
    NoArv* NoArv9 = arv_cria(9, nullptr, nullptr);
    NoArv* NoArv3 = arv_cria(3, NoArv2, NoArv4);
    NoArv* NoArv8 = arv_cria(8, nullptr, NoArv9);
    NoArv* root = arv_cria(5, NoArv3, NoArv8);
    exibe_dec(root);
}
