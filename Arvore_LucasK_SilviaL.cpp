	#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#include<stdlib.h>

struct no {
	char palavra[50];
	int contador;
	struct no *esq;
	struct no *dir;
};

struct no *raiz = NULL;
struct no *maior = raiz;

void insereArvore(char valor[]){
	struct no *atual;
	struct no *anterior;
	struct no *aux;

	aux = new(struct no);
	aux->contador = 1;
	strcpy(aux->palavra, valor);
	aux->esq = NULL;
	aux->dir = NULL;
	if(raiz == NULL){
		raiz = aux;
		maior = raiz;
		return;
	}
	atual = raiz;
	while (atual != NULL){
		anterior = atual;
		if(strcmp(valor, atual->palavra) == 0){
			atual->contador++;
			delete(aux);
			return;
		}
		if(strcmp(valor, atual->palavra) < 0){
			atual = atual->esq;
		} else atual = atual->dir;
	}
	if(strcmp(valor, anterior->palavra) < 0){
		anterior->esq = aux;
	} else anterior->dir = aux;
}

void emOrdem(struct no *atual){
	if(atual != NULL){
		emOrdem(atual->esq);
		if(atual->contador >= maior->contador){
			maior = atual;
		}
		printf("%s\n", atual->palavra);
		emOrdem(atual->dir);
	}
}

void mostraMaisRepetido(struct no *atual){
	if(atual != NULL){
		mostraMaisRepetido(atual->esq);
		if(maior->contador == atual->contador){
			printf("Palavra que mais repetiu = %s (%d vezes)\n", atual->palavra, atual->contador);
		}
		mostraMaisRepetido(atual->dir);
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	FILE *fp;
	char auxiliar[50], letra;
	int i = -1;

	fp = fopen("arquivo.txt", "r");
	if(fp == NULL){
		printf("ERRO\n");
		return -1;
	}

	while(!feof(fp)){
		fscanf(fp, "%c", &letra);

		letra = tolower(letra);

		if(isalpha(letra)){
			auxiliar[i++] = letra;
		} else {
			auxiliar[i] = '\0';
			if(i > 0){
				insereArvore(auxiliar);
			}
			i = 0;
		}
	}
	fclose(fp)	;

	emOrdem(raiz);
	mostraMaisRepetido(raiz);
	system("pause");
	return 0;
}
