#include "FilaReproducao.hpp"

void FilaReproducao::adicionar(string musica) {
    fila.push(musica);
}

void FilaReproducao::tocarProxima() {
    if (!fila.empty()) {
        cout << "Tocando: " << fila.front() << endl;
        fila.pop();
    } else {
        cout << "Fila vazia!" << endl;
    }
}

void FilaReproducao::verProxima() {
    if (!fila.empty()) {
        cout << "Proxima musica: " << fila.front() << endl;
    } else {
        cout << "Fila vazia!" << endl;
    }
}

void FilaReproducao::verTamanho() {
    cout << "Musicas na fila: " << fila.size() << endl;
}
