#include <stdio.h>
#include <stdlib.h>


    //passagem por referencia[ok]
    //vetores ==  ponteiro imutável
    //alocação dinamica
    //ponteiros para ponteiros
void mostra_vetor(int *p, int k){
    int i;
    
    for(i = 0; i < k; i ++){
        printf("%d : %d\n", i, *(p + i));
    }
    
    /*
    int *i;
    for (i = p; i < p + k ; i++) {
        printf("%d: %d\n", i - p, *i );

    }*/
}

int main (){

    //int v[10];
    //int *v;
    int i, n , cont =0;

    printf("quantos numeros? \n");
    scanf("%d", &n );

    int *v = malloc(sizeof(int)*n);

    for(i = 0; i < n; i++){
        //printf("digite o %d n°:\n",i + 1 );
        printf("v[%d](%p)",i, &v[i] );
        scanf("%d0\n", &v[i] );
    }

    for(i = 0; i < n; i++)
        if(v[i]>0)
            cont ++;

    printf("ha %d valores positivos\n", cont);

    free(v);
    
    mostra_vetor(v,n);
    return 0;
}
