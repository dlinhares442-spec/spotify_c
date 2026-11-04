#include "FilaReproducao.hpp"
#include "abb.hpp"
#include "musica.hpp"
#include <iostream>

void FilaReproducao::adicionar(const Musica &musica) {
    fila.push(musica);
}

void FilaReproducao::tocarProxima(catalogoMusicas &catalogo) {
    if (fila.empty()) {
        cout << "Fila vazia!" << endl;
        return;
    }
    Musica musicatocar = fila.front();
    cout << "Tocando: " << musicatocar.titulo << endl;
    catalogo.incrementarReproducoes(musicatocar.id);
    fila.pop();
}

void FilaReproducao::verProxima() {
    if (!fila.empty()) {
        cout << "Proxima musica: " << fila.front().titulo << endl;
    } else {
        cout << "Fila vazia!" << endl;
    }
}

void FilaReproducao::verTamanho() {
    cout << "Musicas na fila: " << fila.size() << endl;
}
