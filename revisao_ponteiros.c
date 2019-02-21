int *p;
int n = 5;

p = &n; 

printf("%d\n", n);

*p = 10;// n= 10;

printf("%d\n", n);//printf("%d/*%p*/\n", *p);
