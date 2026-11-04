// Matheus Viana R. Pereira - Playlist com lista duplamente encadeada (std::list)
#ifndef LISTA_HPP
#define LISTA_HPP

#include <list>
#include "musica.hpp"
using namespace std;

class Playlist
{
private:
    list<Musica> musicas;                     // Lista duplamente encadeada com as músicas
    list<Musica>::iterator atual;             // iterator(que é tipo um ponteiro) para a música atual na playlist
    list<Musica>::iterator encontrar(int id); // Função auxiliar para encontrar a música pelo ID, retorna iterator para a música ou musicas.end() se não encontrada

public:
    Playlist();                                      // Construtor para inicializar a playlist vazia
    void adicionar(const Musica &m);                 // Adiciona uma música no fim da playlist
    bool remover(int id);                            // Remove uma música pelo ID, retorna true se removida
    Musica *proxima();                               // Avança para a próxima música (circular), nullptr se vazia
    Musica *anterior();                              // Volta para a música anterior (circular), nullptr se vazia
    Musica *musicaAtual();                           // Retorna a música atual, nullptr se vazia
    bool moverMusica(int idMover, int idReferencia); // Move a música idMover para antes de idReferencia
    bool contem(int id) const;                       // Verifica se o ID já está na playlist
    int getTamanho() const;                          // Retorna a quantidade de músicas na playlist
    void listar() const;                             // Lista as músicas da playlist, marcando a atual
};

#endif
// Identação com shift + alt + f, atalho do VS Code.