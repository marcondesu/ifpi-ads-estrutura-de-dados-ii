#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Atividade 1 - Questão 1 (criação de nós)
struct noArv {
    int info;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv NoArv;

int arv_vazia(NoArv* a){
    return a == NULL;
}

NoArv* arv_cria(int c, NoArv* e, NoArv* d){
   // NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    // if(p==NULL) exit(1);
    NoArv* p = new NoArv;
    p->info = c;
    p->esq = e;
    p->dir = d;
    return p;
}

NoArv* arv_criavazia(void){
    return NULL;
}

// Atividade 1 - Questão 2 (impressao dos nós mostrando raiz e os filhos da raiz)
void arv_imprime(NoArv* a){
    if (!arv_vazia(a)){
        cout<<"<" <<a->info;
        arv_imprime(a->esq);
        arv_imprime(a->dir);
        cout<<">";
    }
    else {
        cout<<"<VAZIO>";
    }
}

// Atividade 1 - Questão 3 (percurso em largura - incompleto)
void percuso_largura(NoArv* a){
    if (!arv_vazia(a)){
        cout<<"<" <<a->info;
        cout<<a->esq->info;
        cout<<(a->dir->info);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    else {
        cout<<"<VAZIO>";
    }
}

/*NoArv* arv_libera(NoArv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_pertence(NoArv* a, char c);

int main(){
    NoArv *b = arv_cria(1,arv_cria(2,arv_cria(4,arv_criavazia(),arv_criavazia()),arv_cria(5,arv_criavazia(),arv_criavazia())),arv_cria(3,arv_criavazia(),arv_cria(6,NULL,NULL)));
    //arv_imprime(b);
    percuso_largura(b);
}
*/