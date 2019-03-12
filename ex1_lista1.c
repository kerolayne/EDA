#include<stdlib.h>
#include<stdio.h>

/*
Escreva um programa que armazena as notas de um aluno em um vetor cujo tamanho
pode variar.(ok) Para isso, deve-se usar um ponteiro que apontará para a área de memória
alocada para o vetor. O programa deve ler o número de notas e alocar a memória
necessária. Em seguida, deve ler as notas e calcular a média do aluno, bem como mostrar
a maior e a menor nota.

*/
void media(float *p, int n);
void maiorNota(float *p, int n);
void menorNota(float *p, int n);

int main(int argc, char const *argv[]) {

	int n, i;

	//recebe o numero de notas
	printf("digite o numero de notas:\n");
	scanf("%d", &n );

	//aloca a memoria
	float *notas = malloc(sizeof(float)*n);

	//for de insersão das notas
	for (i = 0; i < n; i++) {
		printf("digite a nota %d\n",i + 1 );
		scanf("%f", notas[i]);
	}

	media(notas, n);
	//maiorNota(notas, n);
	//menorNota(notas, n);
	return 0;
}

void media(float *p, int n){
	float notas, media;
	int i;

	for (i = 0; i < n; i++) {
		notas += p[i];
	}

	media = notas / n;

	printf("Média: %.2f\n",media );
}
