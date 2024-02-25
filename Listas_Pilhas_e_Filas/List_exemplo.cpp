#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int>pilha; // ponteiro para pilha

	//Inserindo elementos na pilha
	pilha.push_front(2);
	pilha.push_front(1);
	pilha.push_front(5);

	// Removendo e mostrando elementos da pilha
	cout << *pilha.begin() << endl; // aponta o primeiro n� da lista
	pilha.pop_front(); // remove o primeiro n� da lista
	cout << *pilha.begin() << endl; // aponta o segundo n� da lista
	pilha.pop_front(); // remove o primeiro n� da lista
	cout << *pilha.begin() << endl; // aponta o terceiro n� da lista
	
	return 0;
}
