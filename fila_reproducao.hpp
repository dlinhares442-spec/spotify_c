#ifndef FILA_REPRODUCAO_HPP
#define FILA_REPRODUCAO_HPP

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class FilaReproducao {
private:
    queue<string> fila;

public:
    void adicionar(string musica);
    void tocarProxima();
    void verProxima();
    void verTamanho();
};

#endif
