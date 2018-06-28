#include <stdio.h>

struct no {
	int dado;
	struct no *dir;
	struct no *esq;
};

struct no *raiz = NULL;

void busca(int valor){
		Struct no *atual;
	Struct no *anterior;
	Struct no *aux;

	aux = new(struct no);
	aux->dado = valor;
	aux->esq = NULL;
	aux->dir = NULL;
	if(raiz == NULL){
		raiz = aux;
		return;
	}
	
	atual = raiz;
	
	while (atual != NULL){
		if(atual->dado < valor){
			atual = atual->dir;
			if(atual->dado == valor){
				return;
			}
					
		}
		if(atual->dado > valor){
			atual = atual->esq;
			if(atual->dado == valor){
				return;
			}
			
		}
	}
	
	if(valor < anterior->dado){
		anterior->esq = aux;
	} else anterior->dir = aux;	
	

}

void insereArvoreSemRepetirNumero(int valor){
	Struct no *atual;
	Struct no *anterior;
	Struct no *aux;

	aux = new(struct no);
	aux->dado = valor;
	aux->esq = NULL;
	aux->dir = NULL;
	if(raiz == NULL){
		raiz = aux;
		return;
	}
	
	atual = raiz;
	while (atual != raiz){
		anterior = atual;
		if(valor <= atual->dado){
			if(atual->dado == valor){
				printf("Valor ja inserido\n");
				delete(aux);
				return;
			}
			atual = atual->esq;
		} else atual = atual->dir;		
	}
	
	if(valor < anterior->dado){
		anterior->esq = aux;
	} else anterior->dir = aux;	
}

void insereArvore(int valor){
	Struct no *atual;
	Struct no *anterior;
	Struct no *aux;

	aux = new(struct no);
	aux->dado = valor;
	aux->esq = NULL;
	aux->dir = NULL;
	if(raiz == NULL){
		raiz = aux;
		return;
	}
	
	atual = raiz;
	while (atual != raiz){
		anterior = atual;
		if(valor < atual->dado){
			atual = atual->esq;
		} else atual = atual->dir;		
	}
	
	if(valor < anterior->dado){
		anterior->esq = aux;
	} else anterior->dir = aux;
}

void emOrdem(){
	if(atual != NULL){
		emOrdem(atual->esq);
		printf("%d", atual->dir);
		emOrdem(atual->dir);
	}
}
