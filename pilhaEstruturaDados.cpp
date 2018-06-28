#include <stdio.h>

#define TAM 5

using namespace std;

int pilha[TAM];
int topo = -1;

void push(int valor){
		if(topo == TAM - 1){
			printf("pilha cheia\n");
			return;
		}
		topo++;
		pilha[topo] = valor;
		printf("Sucesso\n");

}

bool vazia(){
	if(topo == -1)
		return true;
	else
		return false;
}

int pop(){
	if(!vazia())
		return topo--;
	else
		return -1;
	}

void mostra(){
	int i;
	for(i=0; i <= topo; i++){
		printf("%d\t", pilha[i]);
	}
	printf("\n");
}

int topoPilha(){
	if(!vazia())
		return pilha[topo];
	else
		return -1;
}

int main(){
	int valor, i, fimPilha;
	for(i = 0; i < TAM; i++){
		printf("Escreva o %d valor para inserir na pilha: ", i);
		scanf("%d", &valor);
		push(valor);
	}

	fimPilha = topo;
	for(i = -1; i <= fimPilha; i++){
		mostra();
		printf("O topo da pilha eh %d\n", topoPilha());
		if(pop() == -1){
			printf("Pilha vazia!\n");
		}
	}
	return 0;
}
