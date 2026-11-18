#include <iostream>
#include <vector>
#include <cstdlib> // Para usar srand() e rand()
#include "teste.hpp"
#include "catalogo.hpp"
#include "busca.hpp"
#include "ordenacao.hpp"
using namespace std;

void modoTeste()
{
        srand(12345); // semente fixa: mesmos numeros a cada execucao
        int tamanhos[3] = {50, 500, 5000};

        for (int x = 0; x < 3; x++)
        {
                int n = tamanhos[x];

                // Vetor aleatorio: id = reproducoes, ordem embaralhada
                vector<Musica> v(n);
                for (int i = 0; i < n; i++)
                {
                        v[i].id = i + 1;
                        v[i].reproducoes = i + 1;
                }
                for (int i = n - 1; i > 0; i--)
                {
                        int j = rand() % (i + 1); // gera um indice aleatorio entre 0 e i
                        Musica temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                }

                cout << "\n===== " << n << " ORDENACAO =====" << endl;

                // ---- Ordenacao ----
                vector<Musica> a = v, b = v, q = v;
                int comp, trocas;

                bubbleSort(a.data(), n, comp, trocas);
                cout << "bubbleSort    - comparacoes: " << comp << " | trocas: " << trocas << endl;

                selectionSort(b.data(), n, comp, trocas);
                cout << "selectionSort - comparacoes: " << comp << " | trocas: " << trocas << endl;

                comp = 0;
                trocas = 0; // o quickSort nao zera sozinho
                quickSort(q.data(), n, comp, trocas, 0, n - 1);
                cout << "quickSort     - comparacoes: " << comp << " | trocas: " << trocas << endl;

                // ---- Busca: mesmas chaves nos 3 metodos ----
                catalogoMusicas abb; 
                for (int i = 0; i < n; i++)
                        abb.inserir(v[i]);
                cout << "\nABB: altura " << abb.altura() << endl;

                int chaves[4] = {v[0].id, v[n / 2].id, v[n - 1].id, -1}; // 3 existentes + 1 inexistente
                for (int i = 0; i < 4; i++)
                {
                        int acSeq = 0, acBin = 0, acAbb = 0; // zera contadores de acessos
                        buscaSequencialvetor(v.data(), n, chaves[i], acSeq);
                        buscaBinaria(q.data(), n, chaves[i], acBin); // q ordenado; reproducoes == id
                        abb.buscarPorID(chaves[i], acAbb);
                        cout << "chave " << chaves[i] << " - acessos | sequencial: " << acSeq
                             << " | binaria: " << acBin << " | ABB: " << acAbb << endl;
                }
        }
}
// Identação com shift + alt + f, atalho do VS Code.