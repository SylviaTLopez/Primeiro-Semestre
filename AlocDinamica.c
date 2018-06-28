#include <stdio.h>
#include <stdlib.h>


struct no {
    int dado;
    struct no *prox;
};

struct no *topo = NULL;

void push(int valor){
    struct no *aux;
    aux = new(struct no);
    aux -> dado = valor;
    aux -> prox = topo;
    topo = aux;
}

int pop(){
    struct no *aux;
    if(topo == NULL) return -1; //pilha vazia
    aux = topo;
    aux = aux -> prox;
    topo = aux;
}

int imprime(){
    struct no *aux;
    if(topo == NULL) return -1; //pilha vazia
    aux = topo;
    while(aux != NULL){
        printf("%d \n", aux -> dado);
        aux = aux -> prox; //vai para o proximo elemento, passo pra frente
    }
}

int main(){
    push(30);
    push(20);
    push(10);
    imprime();
    //pop();
    imprime();
}
