#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct arv {
	int info;
    struct arv *esq;
	struct arv *dir;
} Arv;

Arv *arvore(int x, Arv *d, Arv *e){
	Arv *novo = (Arv *)malloc(sizeof(Arv));
	novo->esq = e;
	novo->dir = d;
	return novo;
}

main(){
	
}
