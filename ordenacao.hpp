#ifndef ORDENACAO1_HPP
#define ORDENACAO1_HPP

#include "musica.hpp"

void bubbleSort (Musica v[], int tamanho, int &comparacao, int &trocas);
	
void selectionSort (Musica v[], int tamanho, int &comparacao, int &trocas);

void quickSort (Musica v[], int tamanho, int &comparacao, int &trocas, int inicio, int fim);

#endif


