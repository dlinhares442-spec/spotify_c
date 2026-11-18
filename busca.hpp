#ifndef BUSCA_HPP
#define BUSCA_HPP

#include "musica.hpp" // Musica (usado pelas declarações abaixo quando forem descomentadas)
using namespace std;

int buscaBinaria(Musica v[], int n, int chave, int &acessos); // vetor precisa estar ordenado
int buscaSequencialvetor(Musica v[], int n, int chave, int &acessos);
int buscaSequencialNome(Musica v[], int n, string chave, int &acessos);

#endif
// Identação com shift + alt + f, atalho do VS Code.