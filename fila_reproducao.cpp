#include "fila_reproducao.hpp"
#include "catalogo.hpp"
#include "musica.hpp"
#include <iostream>

void FilaReproducao::adicionar(const Musica &musica) { // Adiciona uma música à fila de reprodução
    fila.push(musica);
}

void FilaReproducao::tocarProxima(catalogoMusicas &catalogo) { // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
    if (fila.empty()) {
        cout << "Fila vazia!" << endl;
        return;
    }
    Musica musicatocar = fila.front();
    cout << "Tocando: " << musicatocar.titulo << endl;
    catalogo.incrementarReproducoes(musicatocar.id);
    fila.pop();
}

void FilaReproducao::verProxima() { // Mostra a próxima música da fila de reprodução sem removê-la
    if (!fila.empty()) {
        cout << "Proxima musica: " << fila.front().titulo << endl;
    } else {
        cout << "Fila vazia!" << endl;
    }
}

void FilaReproducao::verTamanho() { // Mostra a quantidade de músicas na fila de reprodução
    cout << "Musicas na fila: " << fila.size() << endl;
}
