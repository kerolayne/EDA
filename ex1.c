#include<stdlib.h>
#include<stdio.h>

int int main(int argc, char const *argv[]) {

	int n, i;

	printf("digite o numero de notas:\n");
	scanf("%d", &n );

	float *notas = malloc(sizeof(float)*n);

	for (i = 0; i < n; i++) {
		printf("digite a nota %d\n",n + 1 );
		scanf("%f\n", n + i);

	}
	return 0;
}
