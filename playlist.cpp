// Matheus Viana R. Pereira - Playlist com lista duplamente encadeada
#include <iostream>
#include "playlist.hpp"
using namespace std;

Playlist::Playlist() : atual(musicas.end()) {} // Construtor para inicializar a playlist vazia

void Playlist::adicionar(const Musica &m)
{ // Adiciona uma música no fim da playlist
    musicas.push_back(m);
    if (musicas.size() == 1)
    {
        atual = musicas.begin(); // A primeira música adicionada vira a atual
    }
}

bool Playlist::remover(int id)
{ // Remove uma música pelo ID
    for (list<Musica>::iterator it = musicas.begin(); it != musicas.end(); ++it)
    {
        if (it->id == id)
        {
            if (it == atual)
            {                              // Evita deixar o iterador "atual" invalidado
                atual = musicas.erase(it); // erase devolve o iterador do próximo elemento
                if (atual == musicas.end() && !musicas.empty())
                {
                    atual = musicas.begin(); // Era a última: volta para o início (circular)
                }
            }
            else
            {
                musicas.erase(it);
            }

            return true;
        }
    }

    return false; // ID não encontrado
}

Musica *Playlist::proxima()
{ // Avança para a próxima música (circular)
    if (musicas.empty())
    {
        return nullptr;
    }
    ++atual;
    if (atual == musicas.end())
    {
        atual = musicas.begin(); // Passou da última: volta para a primeira
    }

    return &(*atual);
}

Musica *Playlist::anterior()
{ // Volta para a música anterior (circular)
    if (musicas.empty())
    {
        return nullptr;
    }
    if (atual == musicas.begin())
    {
        atual = musicas.end(); // Estava na primeira: vai para depois da última...
    }
    --atual; // ...e recua para a última
    return &(*atual);
}

Musica *Playlist::musicaAtual()
{ // Retorna a música atual
    if (musicas.empty())
    {
        return nullptr;
    }

    return &(*atual);
}

list<Musica>::iterator Playlist::encontrar(int id)
{ // Procura uma música pelo ID na playlist
    for (list<Musica>::iterator it = musicas.begin(); it != musicas.end(); ++it)
    {
        if (it->id == id)
        {
            return it;
        }
    }

    return musicas.end(); // Não encontrada
}

bool Playlist::moverMusica(int idMover, int idReferencia)
{ // Função de maior dificuldade para mim(Matheus), objetivo é mover a música com idMover para antes da música com idReferencia
    if (idMover == idReferencia)
    {
        return false; // Não faz sentido mover para o mesmo ID
    }

    list<Musica>::iterator itMover = encontrar(idMover);
    list<Musica>::iterator itReferencia = encontrar(idReferencia);

    if (itMover == musicas.end() || itReferencia == musicas.end())
    {
        return false; // Pelo menos um dos IDs não existe
    }

    musicas.splice(itReferencia, musicas, itMover); // Religa o nó antes da referência
    return true;
}

bool Playlist::contem(int id) const
{ // Verifica se o ID já está na playlist
    for (list<Musica>::const_iterator it = musicas.begin(); it != musicas.end(); ++it)
    {
        if (it->id == id)
        {
            return true;
        }
    }

    return false;
}

int Playlist::getTamanho() const
{ // Retorna a quantidade de músicas na playlist
    return (int)musicas.size();
}

void Playlist::listar() const
{ // Lista as músicas da playlist, marcando a atual com ">"
    if (musicas.empty())
    {
        cout << "Playlist vazia." << endl;
        return;
    }

    for (list<Musica>::const_iterator it = musicas.begin(); it != musicas.end(); ++it)
    {
        cout << (it == atual ? "> " : "  ")
             << "ID: " << it->id << ", Título: " << it->titulo << ", Artista: " << it->artista
             << ", Duração: " << it->duracaoSegundos << "s" << endl;
    }
}
// Identação com shift + alt + f, atalho do VS Code.