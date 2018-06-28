#include <stdio.h>
#include <stdlib.h>


struct no {
  int dado; //valor do endereço atual da lista/memoria
  struct no *prox; //aponta para o proximo item da memoria/lista
};

// tipo *topo;
struct no *inicio = NULL;
struct no *fim = NULL;

void insereFila(int valor){
  struct no *aux;

  //a seta (->) identifica qual elemento da struct eu vou manipular
  aux = new(struct no);
  aux -> dado = valor;
  aux -> prox = NULL;

  if(inicio == NULL) {
    inicio = aux;
    fim = aux;
  } else {
    fim -> prox = aux;
    fim = aux;
  }

  void imprime(){
    struct no *aux;
    if(inicio == NULL) {
      printf("Fila vazia");
      return;
    }
    aux = inicio;
    while(aux != NULL) {
      printf("%d", aux -> dado);
      aux = aux -> prox;
    }
  }

 void removeFila(){
   struct no *aux;
   if(inicio == NULL){
      printf("fila vazia");
      return;
   }
   aux = inicio;
   inicio = inicio -> prox;
   if(inicio == NULL){
     fim = NULL;
   }
   delete(aux);
 }
}
