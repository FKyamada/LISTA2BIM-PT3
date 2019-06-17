#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define clrscr(); system("cls");
using namespace std;
#pragma warning(disable : 4996)

void main() {
// Em ordem crescente de salário
	char nome[5][30], pAux[30];
	int x[5], j, i, aux, n;
	clrscr();
	//carregando os numeros do vetor
	for (i = 0; i <= 4; i++)
	{
		cout << "\nDIGITE O " << i + 1 << "o SALARIO\n";
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
	//ordenando em ordem alfabetica 
	for (n = 0; n <=4; n++) {
			cout << "\nENTRE COM O " << n + 1 << "NOME\n";
		cin >> nome[n];
	}

	int k;
	for (k = 1; k <=4; k++)
	{
		strcpy_s(pAux, nome[k]);
		n = k - 1;
		while (n >= 0 && strcmp(nome[n], pAux) > 0)
		{
			strcpy_s(nome[n + 1], nome[n]);
			n--;
		}
		strcpy_s(nome[n + 1], pAux);
	}

	cout << "\nMostrando o salario em ordem crescente...\n";
	//mostrando o vetor ordenado 
	for (i = 0; i <= 4; i++)
	{
		cout << i + 1 << "o SALARIO: " << x[i] << "\n";
	}
	getchar();
	
	for (j = 1; j <= 4; j++)
	{
		//laco que percorre da ultima posicao ah
		//posicao j do vetor
		for (i = 4; i >= j; i--)
		{
			if (x[i] > x[i - 1])
			{
				aux = x[i];
				x[i] = x[i - 1];
				x[i - 1] = aux;
			}
		}
	}
	cout << "\nMostrando o salario em ordem decrescente...\n";
	//mostrando o vetor ordenado 
	for (i = 0; i <= 4; i++)
	{
		cout << i + 1 << "o SALARIO: " << x[i] << "\n";
	}
	cout << "\nMostrando o nome dos funcionarios em ordem alfabetica...\n";
	for (n = 0; n <= 4; n++)
	{		
		cout << n + 1 << "o NOME: " << nome[n] << "\n";
	}
	getchar();
	
}
