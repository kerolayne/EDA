#include<math.h>

//eq. do segundo grau

int raizes(float a, float b, float c, float *p1, float *p2 ){
    float = d pow(b, 2) -4 *a*c;
    
    if( d < 0){
        return 0;
    }else{
        *p1 = (-b + sqrt(d))/(2*a);
        *p2 = (-b - sqrt(d))/(2*a);
        return 1;
}

int main(){
    float a,b,c,x1,x2;
    printf("digite os coeficientes:\n");
    scanf("%f %f %f", &a, &b, &c);
    
    if(a == 0){
       printf("Nao é uma eq do segundo grau...\n");
       }else if(raizes(a, b, c, &x1, &x2))
           printf("As raizes sao %.2f e %.2f\n", x1, x2);
       else{
           printf("nao ha raizes reais!\n");
       }

return 0;
}
