#include<iostream>

using namespace std;

int main()
{
	int n; // quantidade problema
	int i; // contador
	int x; // var aux
	int cont = 0; // n de vezes que x=2*i � executado

	cin >> n;

	for(i = 0; i < n; i++)
	{
		x = 2 * i;
		cont++;
	}


	cout << cont << " vezes" << endl;

	return 0;
}
