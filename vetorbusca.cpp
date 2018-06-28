/*
 1-faça um programa que crie um vewtor com N elementos e inicialize com valores aleatorios entre 0 e 100.
 2- incremente o programa anterior. IMplemente neles a busca de elementos. O usuario devera ser capaz de realizar quantas buscas desejar, 
 encerrando com um valor negativo ou zero. Caso o elemento seja encontrado mostrar sua posição, caso contrario informar que não existe. 
 Implemente em C.
 */

#include <stdio.h>
#include <time.h>
#define N 50

int main() {	
	int vet[N], i, val, achou;
	srand(time(NULL));
	for (i=0; i<N; i++)
		vet[i] = rand() % 100;
		
	for (i=0; i<N; i++){
		printf("%d ", vet[i]);
	}
	printf("\nInforme um valor a ser buscado: ");
	scanf("%d", &val);	
	while (val>=0){ 
		achou = 0;
		for (i=0; i<N; i++){
			if(val==vet[i]) {
			    achou = 1;
			    printf ("%d encontrado na posicao %d\n", val, i);
			}
			if (!achou)	
				printf("%d nao encontrado \n", val); 
			}
			printf("\nInforme o valor da busca negativo encerra: ");
			scanf("%d", &val);
			}
	return 0;
}

