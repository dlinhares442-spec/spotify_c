#include <iostream>
#include "fila_reproducao.hpp"
// Os demais includes já vem do hpp
using namespace std;

void FilaReproducao::adicionar(const Musica &musica)
{ // Adiciona uma música à fila de reprodução
    fila.push(musica);
}

void FilaReproducao::tocarProxima(catalogoMusicas &catalogo)
{ // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
    int acessos = 0;
    if (fila.empty())
    {
        cout << "Fila vazia!" << endl;
        return;
    }

    Musica musicatocar = fila.front();
    if (!catalogo.incrementarReproducoes(musicatocar.id, acessos))
    {
        cout << "(aviso: musica nao esta mais no catalogo)" << endl;
    }
    cout << "Tocando: " << musicatocar.titulo << endl;
    fila.pop();
}

void FilaReproducao::verProxima()
{ // Mostra a próxima música da fila de reprodução sem removê-la
    if (!fila.empty())
    {
        cout << "Proxima musica: " << fila.front().titulo << endl;
    }
    else
    {
        cout << "Fila vazia!" << endl;
    }
}

void FilaReproducao::verTamanho()
{ // Mostra a quantidade de músicas na fila de reprodução
    cout << "Musicas na fila: " << fila.size() << endl;
}

void FilaReproducao::removerPorId(int id)
{
    queue<Musica> nova;
    while (!fila.empty())
    {
        if (fila.front().id != id)
            nova.push(fila.front());
        fila.pop();
    }
    fila = nova;
}
// Identação com shift + alt + f, atalho do VS Code.