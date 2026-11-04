#ifndef FILA_REPRODUCAO_HPP
#define FILA_REPRODUCAO_HPP

#include <iostream>
#include <queue>
#include <string>
#include "abb.hpp" 

using namespace std;

class FilaReproducao {
private:
    queue<string> fila;

public:
    void adicionar(const Musica &musica);
    void tocarProxima(catalogoMusicas &catalogo);
    void verProxima();
    void verTamanho();
};

#endif
