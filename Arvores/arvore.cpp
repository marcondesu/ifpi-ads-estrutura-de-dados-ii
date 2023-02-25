#include "./arvore.h"

int main() {
    NoArv* a1 = arv_cria('d', arv_criavazia(), arv_criavazia());
    NoArv* a2 = arv_cria('b', arv_criavazia(), a1);
    NoArv* a3 = arv_cria('e', arv_criavazia(), arv_criavazia());
    NoArv* a4 = arv_cria('f', arv_criavazia(), arv_criavazia());
    NoArv* a5 = arv_cria('c', a3, a4);
    NoArv* a = arv_cria('a', a2, a5);

    arv_imprime(a);
}
