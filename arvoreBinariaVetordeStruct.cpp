#include<stdio.h>
#define TAM 20

struct no{
	int dado;
	int usado;
};

struct no arvore[TAM];

void inicio(){
	int i;
	for(i = 0; i < TAM; i++){
		arvore[i].usado=0;
	}
}

void insere(int valor){
	int atual = 0;
	while(atual < TAM && arvore[atual].usado!=0){
		if(valor<arvore[atual].dado){
			atual = 2*atual+1;
		} else {
			atual = 2*atual+2;
		}
		if(atual<TAM){
			arvore[atual].dado = valor;
			arvore[atual].usado = 1;
		} else {
			printf("Nao foi possivel inserir\n");
		}
	}
}

void busca(){

}

void insereSemRepetir(){

}

void emOrdem(int atual){
	if(atual < TAM && arvore[atual].usado != 0){
		emOrdem(2*atual+1);
		printf("%d", arvore[atual].dado);
		emOrdem(2*atual+2);
	}
}

int main(){
	inicio();
	insere(2);
	insere(5);
	insere(7);
	insere(2);
	insere(12);
	insere(1);
	emOrdem(0);
	return 0;
}
