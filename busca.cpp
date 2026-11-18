#include <iostream>
#include "busca.hpp"
using namespace std;

    int buscaBinaria(Musica v[], int n, int chave, int &acessos) {
        int inicio = 0;
        int fim = n - 1;
        while (inicio <= fim) {
            int meio = (inicio + fim) / 2;
            acessos++;
            if (v[meio].reproducoes == chave) {
                return meio;
            }
            if (chave < v[meio].reproducoes) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
        return -1;
    }

    int buscaSequencialvetor(Musica v[], int n, int chave, int &acessos) {
        for (int i = 0; i < n; i++) {
            acessos++;
            if (v[i].id == chave) {
                return i;
            }
        }
        return -1;
    }

    int buscaSequencialNome(Musica v[], int n, string chave, int &acessos) { // Usado nas playlists
        for (int i = 0; i < n; i++) {
            acessos++;
            if (v[i].titulo == chave) {
                return i;
            }
        }
        return -1;
    }