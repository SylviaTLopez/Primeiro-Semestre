#include<stdio.h>

struct no{
	int dado;
	struct no *prox;
	struct no *ant;
};

struct no *lista = NULL;

void insere(int valor){
	struct no *atual;
	struct no *anterior;
	struct no *aux;

	atual=lista;
	anterior=NULL;

	aux=new(struct no);
	aux->dado=valor;

	while(atual != NULL && atual->dado < valor){
		anterior = atual;
		atual=atual->prox;
	}

	aux->prox=atual;
	if(atual != NULL){
		atual->ant=aux;
	}

	aux->ant=anterior;
	if(anterior != NULL){
		anterior->prox=aux;
	} else {
		lista = aux;
	}
}

void removePosicao(int posicao){
	struct no *atual;
	struct no* auxiliar;
	int cont = 0;

	atual = lista;
	while(atual != NULL && cont < posicao){
		cont++;
		atual=atual->prox;
	}

	if(atual == NULL || posicao < 0){
		printf("Erro\n");
		return;
	}

	if(atual->prox != NULL){
		auxiliar = atual->prox;
		auxiliar->ant=atual->ant;
	}

	if(atual->ant != NULL){
		auxiliar=atual->ant;
		auxiliar->prox=atual->prox;
	} else {
		lista = lista->prox;
	}
	delete(atual);
}

int main(){

	return 0;
}
