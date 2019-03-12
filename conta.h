#define SALDO_INSUFICIENTE -1

typedef struct{
	int numero;
	float saldo;
}Conta;
void inicializaConta( Conta *p, int n , float s);
void mostraConta(Conta c);
int saque(Conta *p, float v);
void deposito(Conta *p, float v);
