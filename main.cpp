#include <iostream>
#include "musica.hpp"
#include "teste.hpp"
#include "buscaeordenacao.hpp"
#include "abb.hpp"
#include "lista.hpp"
#include "FilaReproducao.hpp"
using namespace std;
#include <fstream>
#include <sstream>


int main() {
    int opcao;
    catalogoMusicas catalogo; // Crio um catalogo
    Playlist minhaplaylist; //Cria a playlist
    FilaReproducao reproducao;
    int id; // Vai ser usado várias vezes
    
    int quantidade = catalogo.carregarMusicas("musicas.txt", catalogo); // Carrega as músicas dentro do TXT e guarda a quantidade de músicas adicionadas
    if (quantidade == 0) { // Confere se as músicas foram carregadas
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
            case 1: {
                cout << "Insira o ID da musica: ";
                cin >> id;
                Musica *musicainserir = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
                if (musicainserir == nullptr) { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                    cout << "ID não encontrado" << endl;
                    break;
                }
                minhaplaylist.adicionarplaylist(*musicainserir); // Adiciona a música achada
                cout << "Musica adicionada com sucesso!" << endl;
                break;
            }
            case 2: {
                cout << "Insira o ID da musica: ";
                cin >> id;
                bool verificar;
                verificar = minhaplaylist.remover(id); // Tenta retirar a musica respectiva ao ID da playlist
                if (verificar == false) { // Se houve falha ao remover exibe um aviso e finaliza o case
                    cout << "Falha ao remover musica da playlist." << endl;
                    break;
                }
                cout << "Musica removida com sucesso!" << endl;
                break;
            }
            case 3: {
                int idaux;
                cout << "Insira o ID que você quer mover (A musica sera colocado atras da referencia): ";
                cin >> id;
                cin.ignore();
                cout << "Insira o ID que você usar de referência: ";
                cin >> idaux;
                bool verificar;
                verificar = minhaplaylist.moverMusica(id, idaux); // Tenta mover a música de lugar
                if (verificar == false) { // Se houve falha ao mover exibe um aviso e finaliza o case
                    cout << "Falha ao mover a musica da playlist." << endl;
                    break;
                }
                cout << "Musica movida com sucesso!" << endl;
                break;
            }
            case 4: {
                minhaplaylist.listar();
                break;
            }
            case 5: {
                cout << "Insira o ID da musica: ";
                cin >> id;
                Musica *musicainserir = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
                if (musicainserir == nullptr) { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                    cout << "ID não encontrado" << endl;
                    break;
                }
                reproducao.adicionar(*musicainserir); // Adiciona a música achada
                cout << "Musica adicionada com sucesso!" << endl;
                break;
            }
            case 6: {
                Musica tocada;
                if (!reproducao.tocarProxima(tocada)) {
                    cout << "Fila vazia!" << endl;
                    break;
                }
                Musica *original = catalogo.buscarPorID(tocada.id);
                if (original != nullptr) {
                    original->reproducoes++;   // efeito real no catalogo
                }
                cout << "Tocando: " << tocada.titulo << " - " << tocada.artista << endl;
                break;
            {
            case 7: {
                reproducao.verProxima();
                break;
            }
            case 8: {
                reproducao.verTamanho();
                break;
            }
            case 9: {
                Musica novamusica;// Lendo todas as informações da nova musica
                cout << "Insira o ID da musica: ";
                cin >> novamusica.id;
                cin.ignore();
                cout << "Insira o titulo da musica: ";
                cin >> novamusica.titulo;
                cin.ignore();
                cout << "Insira o artista da musica: ";
                cin >> novamusica.artista;
                cin.ignore();
                cout << "Insira a duracao em segundos da musica: ";
                cin >> novamusica.duracaoSegundos;
                cin.ignore();
                cout << "Insira a quantidade de reproducoes da musica: ";
                cin >> novamusica.reproducoes;
                cin.ignore();

                catalogo.inserir(novamusica);
                break;
            }
            case 10: {
                cout << "Insira o ID da musica: ";
                cin >> id;
                Musica *musicaachada = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
                if (musicaachada == nullptr) { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                    cout << "ID não encontrado" << endl;
                    break;
                }
                cout << "Titulo: " << musicaachada->titulo << endl;
                cout << "artista: " << musicaachada->artista  << endl;
                cout << "duracao: " << musicaachada->duracaoSegundos  << "S" << endl;
                cout << "reproducoes: " << musicaachada->reproducoes  << endl;
                break;
            }
            case 11: {
                cout << "Insira o ID da musica: ";
                cin >> id;
                bool verificar = catalogo.remover(id); // Busco a música no  catálogo pelo ID
                if (!verificar) { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                    cout << "ID não encontrado" << endl;
                    break;
                }
                cout << "Musica removida com sucesso!" << endl;
                break;
            }
            case 12: {
                catalogo.listarEmOrdem();
                break;
            }
            case 13: {
                int altura = catalogo.altura();
                cout << "A altura e: "<< altura << endl;
                break;
            }
            case 14: {
                int contagem = catalogo.contagemDeNos();
                cout << "A contagem e: "<< contagem <<  endl;
                break;
            }
            case 0: {
                cout << "Saindo..." << endl;
                break;
            }
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opcao != 0);
    return 0;
}
