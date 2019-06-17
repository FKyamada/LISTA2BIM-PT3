#include "ordenacao.h"
#include <iostream>
#include <conio.h>
#define clrscr(); system("cls");
using namespace std;
#pragma warning(disable : 4996)

void insere() {

	int x[5], j, i, aux;
	clrscr();
	//carregando os numeros do vetor
	for (i = 0; i <= 4; i++)
	{
		cout << "\nDIGITE O " << i + 1 << "o NUMERO\n";
		cin >> x[i];
	}
	//ordenando de forma crescente
	//laco com a quantidade de elementos do vetor -1
	for (j = 1; j <= 4; j++)
	{
		//laco que percorre da ultima posicao ah
		//posicao j do vetor
		for (i = 4; i >= j; i--)
		{
			if (x[i] < x[i - 1])
			{
				aux = x[i];
				x[i] = x[i - 1];
				x[i - 1] = aux;
			}
		}
	}
	//mostrando o vetor ordenado 
	for (i = 0; i <= 4; i++)
	{
		cout << i + 1 << "o numero: " << x[i] << "\n";
	}
	getchar();

}