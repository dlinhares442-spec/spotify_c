#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include "musica.hpp"

void bubbleSort(Musica v[], int tamanho, int &comparacao, int &trocas);

void selectionSort(Musica v[], int tamanho, int &comparacao, int &trocas);

void quickSort(Musica v[], int tamanho, int &comparacao, int &trocas, int inicio, int fim);

#endif
// Identação com shift + alt + f, atalho do VS Code.