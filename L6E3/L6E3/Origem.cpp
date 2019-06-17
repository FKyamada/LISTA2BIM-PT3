#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define clrscr();system("cls");
using namespace std;

const int LIMITE = 3;

//BUSCA BINARIA 
int buscaBinaria(int codigo[], int limite, int varProcura, int *cont) {

	int i = 0;
	int f = limite;
	int meio;
	
	while (i <= f) {
		meio = (i + f) / 2;
		if (codigo[meio] == varProcura)
			return meio;
		else
		{
			if (varProcura > codigo[meio])
				i = meio + 1;
			else
				f = meio - 1;

			*cont = *cont + 1;
		}
	}
	return -1;
}
//BUSCA SEQUENCIAL
int buscaSequencial(int codigo[], int limite, int varProcura, int *cont) {

	int i;
	int f = limite;

	for (i = 1; i <= limite; i++) {
		*cont = *cont + 1;
		if (codigo[i] == varProcura)
		{
			return i;
		}
	}
	return -1;
}

void main() {
	// Em ordem crescente de salário
	char descricao[LIMITE][50];
	int cod[LIMITE], preco[LIMITE]; //codigo de 6 digitos 
	int j, i, aux, n, cont=0;
	int p, res, res2; //parametros para as funcoes de busca
	clrscr();


	//carregando os numeros do vetor
	for (i = 0; i < LIMITE; i++)
	{
		cout << "\nDIGITE O " << i + 1 << "o CODIGO DO PRODUTO: ";
		cin >> cod[i];
		cout << "DIGITE O PRECO: ";
		cin >> preco[i];
		cout << "DECRICAO: ";
		cin >> descricao[i];
	}
	clrscr();
	cout << "\nMOSTRANDO OS USUARIOS CADASTRADOS\n";
	//mostrando o vetor ordenado 
	for (i = 0; i < LIMITE; i++)
	{
		cout << i + 1 << "o CODIGO: " << cod[i] << " |O PRECO: " << preco[i] << " |DESCRICAO: " << descricao[i] << "\n";
	}

	//ordenando de forma crescente
	//laco com a quantidade de elementos do vetor -1
	for (j = 0; j < LIMITE; j++)
	{
		//laco que percorre da ultima posicao ah
		//posicao j do vetor
		for (i = LIMITE; i >= j; i--)
		{
			if (cod[i] < cod[i - 1])
			{
				aux = cod[i];
				cod[i] = cod[i - 1];
				cod[i - 1] = aux;

			}
		}
	}
	cout << "\nMostrando o codigo em ordem crescente...\n";
	//mostrando o vetor ordenado 
	for (i = 1; i <= LIMITE; i++)
	{
		cout << i << "o CODIGO: " << cod[i] << "\n";
	}
	getchar();

	//PROCURA VALOR BINARIO
	cout << "\n\nQual codigo gostaria de ser procurado?\n";
	cin >> p;
	res = buscaBinaria(cod, LIMITE, p, &cont);
	cout << "\n-------------- BUSCA BINARIA ------------\n";
	if (res == -1) {
		cout << "\no valor procurado n foi encontrado\n";
	}
	else
	{
		cout << "O VALOR PROCURADO SE ENCONTRA NA POSICAO: " << res  << "\n\n";
		cout << "Numero de comparacoes: " << cont << "\n\n";
	}
	cout << "\n-------------- BUSCA SEQUENCIAL ------------\n";
	//PROCURA VALOR SEQUENCIAL
	cont = 0;
	res2 = buscaSequencial(cod, LIMITE, p, &cont);

	if (res2 == -1) {
		cout << "\nO VALOR PROCURADO N FOI ENCONTRADO\n";
	}
	else
	{
		cout << "O VALOR PROCURADO SE ENCONTRA NA POSICAO: " << res2  << "\n\n";
		cout << "Numero de comparacoes: " << cont  << "\n\n";
	}
	system("pause");
}
