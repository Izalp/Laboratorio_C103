#include <iostream>

using namespace std;

int fatorial(int n)
{
	if(n == 0) // condi��o de parada
		return 1;
	else // chamada recursiva
		return n * fatorial(n - 1);
}

int main()
{
	int n; //variavel para coletar o numero fornecido pelo usuario
	int res; //recebe resultado da fun��o fib
	
	cin >> n; //entrada de dados
	
	res = fatorial(n); //chamar a fun��o
	
	cout << res; // Apresentar o resultado
	
	return 0;
}
