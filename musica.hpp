#ifndef MUSICA_HPP
#define  MUSICA_HPP

#include <string>
using namespace std; 
struct Musica {
        int id; // Identificador único da música
        string titulo; // Título da música
        string artista; // Artista da música
        int duracaoSegundos; // Duração da música em segundos
        int reproducoes; // Número de reproduções da música
};

#endif
