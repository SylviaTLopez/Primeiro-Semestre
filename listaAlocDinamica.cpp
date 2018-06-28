#include <stdio.h>

struct no{
	int dado;
	struct no *prox;
};

struct no *lista = NULL;

void insereLista(int valor){
	struct no *atual;
	struct no *anterior = NULL;
	struct no *aux;
	atual = lista;

	while(atual != NULL && atual->dado < valor){
		anterior = atual;
    	atual = atual->prox;
  	}

  	aux = new(struct no);
  	aux->dado = valor;
  	aux->prox=atual;

	if(atual==lista){
		lista=aux;
	} else{
		anterior->prox=aux;
	}
	printf("Valor %d inserido na lista.\n", valor);
}

void removeLista(int posicao){
	int i = 0;
	struct no *anterior = lista;
	struct no *aux = lista;

	if(aux == NULL){
		printf("Lista Vazia.\n");
		return;
	}

	if(posicao < 0){
		printf("Posicao %d invalida (1).\n", posicao);
		return;
	}

	if(posicao == 0){
		lista = lista->prox;
	} else {
		while(aux != NULL){
			if(i == posicao){
				anterior->prox = aux->prox;
			}

			anterior=aux;
			aux = aux->prox;
			i++;
		}
		if(posicao >= i){
			printf("Posicao %d invalida (2).\n", posicao);
			return;
		}
	}

	printf("Elemento %d removido.\n", posicao);
	delete(aux);
}

void buscaLista(int valor){
	int posicao, j;
	struct no *aux = lista;
	while(aux != NULL){
		if(aux->dado == valor){
			printf("Valor: %d posicao: %d \n", valor, posicao);
			i++;
		}
		aux=aux->prox;
	}

	if(j > 0)
		printf("O valor %d aparece %d vez(es) na lista\n", valor, i);
	 else
		printf("O valor %d nao esta na lista.\n", valor);
}

void imprime(){
	struct no *aux;
	aux = lista;
	if (aux == NULL) {
		printf("Lista vazia.\n");
	} else {
		printf("Lista:\n");
		do{
			printf("%d ", aux->dado);
			aux = aux->prox;
		}while(aux != NULL);
	}
	printf("\n\n");
}

void recuperaLista(int posicao){
	struct no *aux = lista;
	int i = 0;

	if(lista == NULL){
		printf("Lista vazia.\n");
		return;
	}

	if(posicao < 0){
		printf("Posicao invalida.\n");
		return;
	}

	while(aux != NULL && i < posicao){
		aux=aux->prox;
		i++;
	}

	if(posicao > i){
		printf("Posicao %d invalida (2).\n", posicao);
		return;
	}

	printf("O valor na posicao %d eh: %d \n", posicao, aux->dado);
}

/*int tamanhoLista(){
	int i;
	struct no *aux = lista;
	while(aux != NULL){
		aux=aux->prox;
		i++;
	}
	return i;
}*/

int main(){
	insereLista(10);
	insereLista(9);
	insereLista(8);
	imprime();
	recuperaLista(0);
	recuperaLista(5);


	removeLista(2);
	imprime();
	removeLista(1);
	imprime();
	removeLista(0);
	imprime();
	recuperaLista(2);



	return 0;

}
