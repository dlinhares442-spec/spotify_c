#include <iostream>
#include "ordenacao.hpp"

using namespace std;

void bubbleSort(Musica v[], int tamanho, int &comparacao, int &trocas)
{

	comparacao = 0;
	trocas = 0;

	for (int i = 0; i < tamanho - 1; i++)
	{

		for (int j = 0; j < tamanho - 1 - i; j++)
		{

			comparacao++;

			if (v[j].reproducoes < v[j + 1].reproducoes) // verifica se o elemento atual é menor que o próximo elemento
			{

				Musica temp; // cria uma variável temporária para armazenar o elemento atual

				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;

				trocas++;
			}
		}
	}
}

void selectionSort(Musica v[], int tamanho, int &comparacao, int &trocas)
{

	comparacao = 0;
	trocas = 0;

	for (int i = 0; i < tamanho - 1; i++) // percorre o vetor até o penúltimo elemento
	{

		int maiorIndice = i;

		for (int j = i + 1; j < tamanho; j++)
		{

			comparacao++;
			if (v[j].reproducoes > v[maiorIndice].reproducoes)
			{
				maiorIndice = j;
			}
		}
		if (maiorIndice != i) // Se o maior índice não for o índice atual, faz a troca
		{
			trocas++;
			Musica temp;

			temp = v[i];
			v[i] = v[maiorIndice];
			v[maiorIndice] = temp;
		}
	}
}

void quickSort(Musica v[], int tamanho, int &comparacao, int &trocas, int inicio, int fim)
{
	if (inicio >= fim)
		return;

	int meio = inicio + (fim - inicio) / 2;
	int pivo = v[meio].reproducoes;

	int i = inicio;
	int j = fim;

	while (i <= j)
	{
		// Avança o ponteiro i enquanto o elemento for maior que o pivô
		while (true) // logica usando true e break para evitar problemas de comparação com o pivô
		{
			comparacao++;
			if (v[i].reproducoes > pivo)
			{
				i++;
			}
			else
			{
				break;
			}
		}

		// Recua o ponteiro 'j' enquanto o elemento for menor que o pivô
		while (true)
		{
			comparacao++;
			if (v[j].reproducoes < pivo)
			{
				j--;
			}
			else
			{
				break;
			}
		}

		// Se os ponteiros não se cruzaram, faz a troca
		if (i <= j)
		{
			if (i < j)
			{
				Musica temp = v[i];
				v[i] = v[j];
				v[j] = temp;
				trocas++;
			}
			i++;
			j--;
		}
	}

	// Chamadas recursivas para ordenar as subpartes
	if (inicio < j)
	{
		quickSort(v, tamanho, comparacao, trocas, inicio, j);
	}
	if (i < fim)
	{
		quickSort(v, tamanho, comparacao, trocas, i, fim);
	}
}
// Identação com shift + alt + f, atalho do VS Code.