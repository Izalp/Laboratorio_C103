#include<iostream>
#include<cmath>
using namespace std;

struct dado
{
	int k; // tamanho da tabela
	int status; // chaves da tabela (0-vazio, 1-ocupado, 2-removido)
};
int hash_aux(int k, int m) // Sintaxe da fun��o hashing
{
	int total;

	total = k % m;

	// retornando posi��es
	if(total >= 0)
		return total;
	else
		return total + m;
}
int hash1(int k, int i, int m) // Sintaxe da fun��o hashing - sondagem linear
{
	return (hash_aux(k, m) + i) % m;
}
int hash_insert(dado T[], int m, int k) // sintaxe da fun��o de inser��o de elementos
{
	int j; // contador
	int i = 0; // contador
	do
	{
		j = hash1(k, i, m); // atribuindo a funcao hash1 para o contador
		if (T[j].status != 1) // verificando o status da posicao
		{
			T[j].k = k;
			T[j].status = 1;
			return j; // retornando a posicao da chave
		}
		else
			i++;
	}
	while (i != m);

	return -1; // retornando -1 se a chave n�o for possivel inserir
}
int hash_search(dado t[], int m, int k) // sintaxe da fun��o hash_search
{
	int i = 0;
	int j;
	do
	{
		j = hash1(k, i, m); //atribuindo a funcao hash1 para o contador
		if (t[j].k == k) // se a chave no vetor for a chave procurada
			return j; // retorna sua posi��o
		else
			i++;
	}
	while (t[j].status != 0 && i < m);

	return -1; // se n�o achar a chave, retorna -1
}
int hash_remove(dado t[], int m, int k) // sintaxe da fun��o hash_remove
{
	int j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;

		return 0; // consegui remover
	}
	else
		return -1; // k nao esta na tabela
}
int main()
{
	dado t[30]; // struct para armazenar tamanho e chaves da tabela
	int i = 0; // contador
	int k; // chaves a serem inseridas e dps do while ser� a chave procurada
	int total; // variavel para armazenar o retorno da fun��o hash_insert
	int tamanho; // tamanho da tabela
	int chave_pos; // valor da chave procurada

	cin >> tamanho; // fazendo leitura do tamanho da tabela

	// acresentando -1 em todas as posi��es de k dentro da struct
	for (i = 0; i < tamanho; i++)
	{
		t[i].k = -1;
		t[i].status = -1;
	}

	// fazendo a leitura das chaves e comparando se n�o � zero
	cin >> k;
	i = 0;
	while (k != 0)
	{
		total = hash_insert(t, tamanho, k); // chamando a fun��o hash_insert
		i++;

		cin >> k;
	}

	cin >> k; // lendo a chave procurada

	chave_pos = hash_remove(t, tamanho, k); // chamando a fun��o hash_remove

	// apresentando o vetor resultado:
	for(i = 0; i < tamanho; i++)
	{
		cout << t[i].k;

		if(i != tamanho - 1)
			cout << " ";
	}

	cout << endl;

	return 0;
}
