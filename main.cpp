#include <iostream>
#include "musica.hpp"
#include "teste.cpp"
#include "buscaeordenacao.cpp"
#include "teste.cpp"
using namespace std;
#include <fstream>
#include <sstream>

// Carregar o arquivo TXT
No* carregarMusicas(const string& nomeArquivo, No* raiz, int& quantidade) {
    ifstream arquivo(nomeArquivo);
    string linha;
    quantidade = 0;

    if (!arquivo.is_open()) {
        return raiz;
    }

    while (getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }
        stringstream ss(linha);
        string campo;
        Musica m;

        getline(ss, campo, ';');  m.id = stoi(campo);
        getline(ss, m.titulo, ';');
        getline(ss, m.artista, ';');
        getline(ss, campo, ';');  m.duracaoSegundos = stoi(campo);
        getline(ss, campo, ';');  m.reproducoes = stoi(campo);

        raiz = inserirNaABB(raiz, m);
        quantidade++;
    }
    return raiz;
}

int main() {
    int opcao;
    int quantidade = 0;
    
    raiz = carregarMusicas("musicas.txt", raiz, quantidade);
    if (quantidade == 0) {
        cout << "Erro: nenhuma musica carregada. Confira o arquivo musicas.txt." << endl;
        return 1;
    }
    cout << quantidade << " musicas carregadas." << endl;
    do { 
        cout << "\n------------- SPOTIPY -------------" << endl;
        cout << "\n--- PLAYLIST ---" << endl;
        cout << " 1 - Adicionar musica (pelo ID)" << endl;
        cout << " 2 - Remover musica" << endl;
        cout << " 3 - Mover musica" << endl;
        cout << " 4 - Listar a playlist" << endl;
        cout << "\n--- FILA DE REPRODUCAO ---" << endl;
        cout << " 5 - Adicionar na fila" << endl;
        cout << " 6 - Tocar proxima" << endl;
        cout << " 7 - Ver proxima" << endl;
        cout << " 8 - Ver tamanho da fila" << endl;
        cout << "\n--- CATALOGO (ABB) ---" << endl;
        cout << " 9 - Inserir musica" << endl;
        cout << "10 - Buscar por ID" << endl;
        cout << "11 - Remover musica" << endl;
        cout << "12 - Listar em ordem de ID" << endl;
        cout << "13 - Altura da arvore" << endl;
        cout << "14 - Quantidade de nos" << endl;
        cout << "\n 0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Playlist: pedir ID, buscar na ABB, adicionar na playlist
                break;
            case 2:
                // Playlist: pedir ID, remover da playlist
                break;
            case 3:
                // Playlist: pedir ID a mover e ID de referencia, chamar moverMusica
                break;
            case 4:
                // Playlist: listar
                break;
            case 5:
                // Fila: pedir ID, checar se existe na ABB, dar push
                break;
            case 6:
                // Fila: checar se esta vazia, tirar ID, buscar na ABB, reproducoes++
                break;
            case 7:
                // Fila: checar se esta vazia, mostrar front()
                break;
            case 8:
                // Fila: mostrar size()
                break;
            case 9:
                // Catalogo: pedir dados da musica, inserirNaABB
                break;
            case 10:
                // Catalogo: pedir ID, buscarNaABB, mostrar (checar nullptr)
                break;
            case 11:
                // Catalogo: pedir ID, removerDaABB
                break;
            case 12:
                // Catalogo: percorrerEmOrdem
                break;
            case 13:
                // Catalogo: alturaABB
                break;
            case 14:
                // Catalogo: contarNos
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opcao != 0);
    return 0;
}
