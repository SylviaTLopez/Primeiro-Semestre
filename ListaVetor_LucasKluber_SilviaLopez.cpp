/*
Exercicio de estrutura de dados: Lista utilizando vetores
Alunos: Lucas Kluber e Silvia Tatyara Lopez
Prof: Marcio Souza
*/

#include <stdio.h>
#define TAM 5

int lista[TAM];
int tamanho = 0;

void insereLista(int valor){
	int i;
	if(tamanho == TAM) printf("Lista cheia.\n");
	else{
		for(i = tamanho; (i > 0 && valor < lista[i-1]); i--){
			lista[i]=lista[i-1];
		}
		lista[i] = valor;
		printf("Valor %d inserido em lista\n", valor);
		tamanho++;
	}
}

void imprime(){
	int i;
	printf("valores na lista:\n");
	for(i = 0; i < tamanho; i++)
		printf("%d ", lista[i]);
	printf("\n");
}

void recuperaLista(int posicao){
	if(posicao >= tamanho || posicao < 0)
		printf("Posicao Invalida ou vazia\n");
	else
		printf("O valor na posicao %d eh: %d \n", posicao, lista[posicao]);
}

void buscaLista(int valor){
	int posicao, i, j = 0;

	for (i = 0; i < tamanho-1; i++){
		if(lista[i] == valor){
			posicao = i;
			printf("Valor: %d posicao: %d \n", valor, posicao);
			j++;
		}
	}

	if(j > 0)
		printf("O valor %d aparece %d vez(es) na lista\n", valor, j);
	 else
		printf("O valor %d nao esta na lista.\n", valor);
}

void  removeLista(int posicao){
	int i;
	if(posicao >= tamanho || posicao < 0){
		printf("Posicao Invalida\n");
	}
	else{
		for(i = posicao; i < tamanho-1; i++){
			lista[i] = lista[i+1];
	}
	tamanho--;
	printf("Valor removido com sucesso.\n");
	}
}

void removeValor(int valor, int removeTodos){
	int i, tamanhoTmp = tamanho;
	for (i = 0; i < tamanhoTmp; i++){
			if(lista[i] == valor){
				if(removeTodos == 1){
					removeLista(i);
			} else {
					removeLista(i);
					return;
			}
		}
	}
	printf("Valor informado não existe na lista.\n");
}

void existeLista(int valor){
	int i;
	if(tamanho == 0)
		printf("A lista nao tem nenhum elemento.\n");
	for (i = 0; i < tamanho; i++){
		if(lista[i] == valor){
			printf("O valor %d existe na lista na posicao %d.\n", valor, i);
			return;
		}
	}
}

int main(){

	return 0;
}
