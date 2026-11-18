#ifndef FILA_REPRODUCAO_HPP
#define FILA_REPRODUCAO_HPP

#include <queue>
#include "catalogo.hpp" // catalogoMusicas (tocarProxima) e Musica

using namespace std;

class FilaReproducao
{
private:
    queue<Musica> fila;

public:
    void adicionar(const Musica &musica);         // Adiciona uma música à fila de reprodução
    void tocarProxima(catalogoMusicas &catalogo); // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
    void verProxima();                            // Mostra a próxima música da fila de reprodução sem removê-la
    void verTamanho();                            // Mostra a quantidade de músicas na fila de reprodução
    void removerPorId(int id);                    // Remove uma música da fila de reprodução pelo ID
};

#endif
// Identação com shift + alt + f, atalho do VS Code.