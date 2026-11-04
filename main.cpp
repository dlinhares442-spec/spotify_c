#include <iostream>
#include "musica.hpp"
// #include "teste.hpp"
// #include "buscaeordenacao.hpp"
#include "catalogo.hpp"
#include "playlist.hpp"
#include "fila_reproducao.hpp"
using namespace std;
#include <fstream> // Ler o arquivo TXT
#include <sstream> // Ler o arquivo TXT

int main()
{
    int opcao;
    catalogoMusicas catalogo; // Crio um catalogo
    Playlist minhaplaylist;   // Cria a playlist
    FilaReproducao reproducao;
    int id; // Vai ser usado várias vezes

    int quantidade = catalogo.carregarMusicas("musicas.txt", catalogo); // Carrega as músicas dentro do TXT e guarda a quantidade de músicas adicionadas
    if (quantidade == 0)
    { // Confere se as músicas foram carregadas
        cout << "Erro: nenhuma musica carregada. Confira o arquivo musicas.txt." << endl;
        return 1;
    }
    cout << quantidade << " musicas carregadas." << endl;

    do
    {
        cout << "\n------------- SPOTIPY -------------" << endl;
        cout << "\n--- PLAYLIST ---" << endl; 
        cout << " 1 - Adicionar musica (pelo ID)" << endl; // Adiciona uma música à playlist pelo ID
        cout << " 2 - Remover musica" << endl; // Remove uma música da playlist pelo ID
        cout << " 3 - Mover musica" << endl; // Move uma música para antes de outra música na playlist
        cout << " 4 - Listar a playlist" << endl; // Lista todas as músicas da playlist, marcando a atual
        cout << "\n--- FILA DE REPRODUCAO ---" << endl;
        cout << " 5 - Adicionar na fila" << endl; // Adiciona uma música à fila de reprodução pelo ID
        cout << " 6 - Tocar proxima" << endl; // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
        cout << " 7 - Ver proxima" << endl; // Mostra a próxima música da fila de reprodução sem removê-la
        cout << " 8 - Ver tamanho da fila" << endl; // Mostra a quantidade de músicas na fila de reprodução
        cout << "\n--- CATALOGO (ABB) ---" << endl;
        cout << " 9 - Inserir musica" << endl; // Insere uma nova música no catálogo (ABB) com todas as informações
        cout << "10 - Buscar por ID" << endl; // Busca uma música no catálogo (ABB) pelo ID e mostra todas as informações dela
        cout << "11 - Remover musica" << endl; // Remove uma música do catálogo (ABB) pelo ID
        cout << "12 - Listar em ordem de ID" << endl; // Lista todas as músicas do catálogo (ABB) em ordem crescente de ID
        cout << "13 - Altura da arvore" << endl; // Mostra a altura da árvore (ABB)
        cout << "14 - Quantidade de nos" << endl; // Mostra a quantidade de nós na árvore (ABB)
        cout << "\n 0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;

            Musica *musicainserir = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
            if (musicainserir == nullptr)
            { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                cout << "ID não encontrado" << endl;
                break;
            }

            if (minhaplaylist.contem(id))
            {
                cout << "Musica ja esta na playlist." << endl;
                break;
            }

            minhaplaylist.adicionar(*musicainserir); // Adiciona a música achada
            cout << "Musica adicionada com sucesso!" << endl;
            break;
        }
        case 2:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;
            bool verificar;
            verificar = minhaplaylist.remover(id); // Tenta retirar a musica respectiva ao ID da playlist
            if (verificar == false)
            { // Se houve falha ao remover exibe um aviso e finaliza o case
                cout << "Falha ao remover musica da playlist." << endl;
                break;
            }
            cout << "Musica removida com sucesso!" << endl;
            break;
        }
        case 3:
        {
            int idaux;
            cout << "Insira o ID que você quer mover (A musica sera colocado atras da referencia): ";
            cin >> id;
            cout << "Insira o ID que você usar de referência: ";
            cin >> idaux;
            bool verificar;
            verificar = minhaplaylist.moverMusica(id, idaux); // Tenta mover a música de lugar
            if (verificar == false)
            { // Se houve falha ao mover exibe um aviso e finaliza o case
                cout << "Falha ao mover a musica da playlist." << endl;
                break;
            }
            cout << "Musica movida com sucesso!" << endl;
            break;
        }
        case 4:
        {
            minhaplaylist.listar();
            break;
        }
        case 5:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;
            Musica *musicainserir = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
            if (musicainserir == nullptr)
            { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                cout << "ID não encontrado" << endl;
                break;
            }
            reproducao.adicionar(*musicainserir); // Adiciona a música achada
            cout << "Musica adicionada com sucesso!" << endl;
            break;
        }
        case 6:
        {
            reproducao.tocarProxima(catalogo);
            break;
        }
        case 7:
        {
            reproducao.verProxima();
            break;
        }
        case 8:
        {
            reproducao.verTamanho();
            break;
        }
        case 9:
        {
            Musica novamusica;

            cout << "Insira o ID da musica: "; // Lendo todas as informações da nova musica
            cin >> novamusica.id;
            cout << "Insira a duracao em segundos da musica: ";
            cin >> novamusica.duracaoSegundos;
            cout << "Insira a quantidade de reproducoes da musica: ";
            cin >> novamusica.reproducoes;
            cin.ignore();

            cout << "Insira o titulo da musica: ";
            getline(cin, novamusica.titulo);
            cout << "Insira o artista da musica: ";
            getline(cin, novamusica.artista);

            if (!catalogo.inserir(novamusica))
            {
                cout << "ID ja existente no catalogo!";
            }
            else
            {
                cout << "Musica inserida com sucesso!";
            }

            break;
        }
        case 10:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;
            Musica *musicaachada = catalogo.buscarPorID(id); // Busco a música no  catálogo pelo ID
            if (musicaachada == nullptr)
            { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                cout << "ID não encontrado" << endl;
                break;
            }
            cout << "Titulo: " << musicaachada->titulo << endl;
            cout << "artista: " << musicaachada->artista << endl;
            cout << "duracao: " << musicaachada->duracaoSegundos << "S" << endl;
            cout << "reproducoes: " << musicaachada->reproducoes << endl;
            break;
        }
        case 11:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;

            // Tenta remover do catálogo (ABB). Se o ID não existe, avisa e sai
            if (!catalogo.remover(id))
            {
                cout << "ID não encontrado" << endl;
                break;
            }

            // A música saiu do catálogo, então também sai da playlist (se estiver lá)
            if (minhaplaylist.contem(id))
            {
                minhaplaylist.remover(id);
            }

            cout << "Musica removida com sucesso!" << endl;
            break;
        }
        case 12:
        {
            catalogo.listarEmOrdem(); 
            break;
        }
        case 13:
        {
            int altura = catalogo.altura();
            cout << "A altura e: " << altura << endl;
            break;
        }
        case 14:
        {
            int contagem = catalogo.contagemDeNos();
            cout << "A contagem e: " << contagem << endl;
            break;
        }
        case 0:
        {
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
