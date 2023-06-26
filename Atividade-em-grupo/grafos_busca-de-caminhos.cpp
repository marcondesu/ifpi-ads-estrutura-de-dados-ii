#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
    Grupo: Cibelle Maciel
           Gabriel Oliver
           Marcos Vinícius    
*/

template<class T>
class Fila {
private:
    queue<T> elementos;

public:
    void enfileirar(const T& elemento) {
        elementos.push(elemento);
    }

    T desenfileirar() {
        T elemento = elementos.front();
        elementos.pop();

        return elemento;
    }

    bool vazia() const {
        return elementos.empty();
    }

    int tamanho() const {
        return elementos.size();
    }
};

template<class T>
class Grafo {
private:
    vector<vector<T>> adjacencias;

public:
    Grafo(int qtd_vertices) : adjacencias(qtd_vertices) {}

    void add_aresta(T origem, T destino) {
        adjacencias[origem].push_back(destino);
        adjacencias[destino].push_back(origem);
    }

    void bfs(T vertice_inicial) {
        vector<bool> visitados(adjacencias.size(), false);
        Fila<T> fila;

        visitados[vertice_inicial] = true;
        fila.enfileirar(vertice_inicial);

        while (!fila.vazia()) {
            T vertice_atual = fila.desenfileirar();
            cout << vertice_atual << " ";

            for (const T& vizinho : adjacencias[vertice_atual]) {
                if (!visitados[vizinho]) {
                    visitados[vizinho] = true;
                    fila.enfileirar(vizinho);
                }
            }
        }

        cout << endl;
    }

    void dfs(T vertice_inicial) {
        vector<bool> visitados(adjacencias.size(), false);
        stack<T> pilha;

        visitados[vertice_inicial] = true;
        pilha.push(vertice_inicial);

        while (!pilha.empty()) {
            T vertice_atual = pilha.top();
            pilha.pop();
            cout << vertice_atual << " ";

            for (const T& vizinho : adjacencias[vertice_atual]) {
                if (!visitados[vizinho]) {
                    visitados[vizinho] = true;
                    pilha.push(vizinho);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Grafo<int> grafo(6); // 6 vertices

    grafo.add_aresta(0, 1);
    grafo.add_aresta(0, 2);
    grafo.add_aresta(1, 3);
    grafo.add_aresta(1, 4);
    grafo.add_aresta(2, 4);
    grafo.add_aresta(3, 4);
    grafo.add_aresta(3, 5);
    grafo.add_aresta(4, 5);

    cout << "BFS: ";
    grafo.bfs(0);

    cout << "DFS: ";
    grafo.dfs(0);

    return 0;
}
