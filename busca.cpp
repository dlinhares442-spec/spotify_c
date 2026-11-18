#include <iostream>
#include "busca.hpp"
using namespace std;

int buscaBinaria(Musica v[], int n, int chave, int &acessos) // vetor precisa estar ordenado
{
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) // enquanto o intervalo não estiver vazio
    {
        int meio = (inicio + fim) / 2; // calcula o índice do elemento do meio
        acessos++;
        if (v[meio].reproducoes == chave) // se o elemento do meio for a chave, retorna o índice
        {
            return meio;
        }
        if (chave > v[meio].reproducoes) // se a chave for maior que o elemento do meio, procura na metade direita
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1; // se não encontrou a chave, retorna -1
}

int buscaSequencialvetor(Musica v[], int n, int chave, int &acessos)
{
    for (int i = 0; i < n; i++)
    {
        acessos++;
        if (v[i].id == chave) // se o elemento do meio for a chave, retorna o índice
        {
            return i;
        }
    }
    return -1;
}

int buscaSequencialNome(Musica v[], int n, string chave, int &acessos) // Usado na playlist
{ 
    for (int i = 0; i < n; i++)
    {
        acessos++;
        if (v[i].titulo == chave)
        {
            return i; // se o elemento do meio for a chave, retorna o índice
        }
    }
    return -1;
}

// Identação feita com o atalho alt + shift + f do VS code.