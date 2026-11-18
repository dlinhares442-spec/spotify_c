#include <iostream>
#include <string>
#include <vector> // Vetor do catálogo (cases 16 a 18)
#include "musica.hpp"
#include "catalogo.hpp"
#include "playlist.hpp"
#include "fila_reproducao.hpp"
#include "busca.hpp"
#include "ordenacao.hpp"
#include "teste.hpp"
using namespace std;

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
        cout << " 2 - Remover musica" << endl;             // Remove uma música da playlist pelo ID
        cout << " 3 - Mover musica" << endl;               // Move uma música para antes de outra música na playlist
        cout << " 4 - Tocar proxima musica" << endl;       // Toca a próxima música da playlist e incrementa o contador de reproduções no catálogo
        cout << " 5 - Tocar musica anterior" << endl;      // Volta para a música anterior da playlist e incrementa o contador de reproduções no catálogo
        cout << " 6 - Mostrar musica atual" << endl;       // Mostra a música atual da playlist sem removê-la
        cout << " 7 - Listar a playlist" << endl;          // Lista todas as músicas da playlist, marcando a atual
        cout << " 8 - Buscar na playlist (pelo nome)" << endl;
        cout << "\n--- FILA DE REPRODUCAO ---" << endl;
        cout << " 9 - Adicionar na fila" << endl;    // Adiciona uma música à fila de reprodução pelo ID
        cout << " 10 - Tocar proxima" << endl;       // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
        cout << " 11 - Ver proxima" << endl;         // Mostra a próxima música da fila de reprodução sem removê-la
        cout << " 12 - Ver tamanho da fila" << endl; // Mostra a quantidade de músicas na fila de reprodução
        cout << "\n--- CATALOGO (ABB) ---" << endl;
        cout << "13 - Inserir musica" << endl;        // Insere uma nova música no catálogo (ABB) com todas as informações
        cout << "14 - Buscar por ID" << endl;         // Busca uma música no catálogo (ABB) pelo ID e mostra todas as informações dela
        cout << "15 - Remover musica" << endl;        // Remove uma música do catálogo (ABB) pelo ID
        cout << "16 - Listar em ordem de ID" << endl; // Lista todas as músicas do catálogo (ABB) em ordem crescente de ID
        cout << "17 - Altura da arvore" << endl;      // Mostra a altura da árvore (ABB)
        cout << "18 - Quantidade de nos" << endl;     // Mostra a quantidade de nós na árvore (ABB)
        cout << "\n--- RANKING ---" << endl;
        cout << "19 - Mostrar ranking (mais tocadas primeiro)" << endl; // Mostra o ranking ordenado por repetições das mais tocadas para as menos
        cout << "20 - Musica mais reproduzida" << endl;                 // Mostra a musica com mais reproducoes
        cout << "21 - Buscar no ranking por reproducoes" << endl;       // Busca uma musica pela quantidade de reproduções
        cout << "22 - Modo de teste (50, 500 e 5000 registros)" << endl;
        cout << "\n 0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int acessos = 0;
            cout << "Insira o ID da musica: ";
            cin >> id;
            Musica *musicainserir = catalogo.buscarPorID(id, acessos); // Busco a música no  catálogo pelo ID
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
            cout << "Insira o ID que você quer mover (A musica sera colocado antes da referencia): ";
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
            Musica *proxima = minhaplaylist.proxima(); // Avança para a próxima música, nullptr se vazia
            if (proxima == nullptr)
            {
                cout << "Playlist vazia." << endl;
                break;
            }
            int acessos = 0;
            catalogo.incrementarReproducoes(proxima->id, acessos); // Incrementa o contador de reproduções no catálogo
            cout << "Tocando: " << proxima->titulo << " - " << proxima->artista << endl;
            break;
        }
        case 5:
        {
            Musica *anterior = minhaplaylist.anterior(); // Volta para a música anterior, nullptr se vazia
            if (anterior == nullptr)
            {
                cout << "Playlist vazia." << endl;
                break;
            }
            int acessos = 0;
            catalogo.incrementarReproducoes(anterior->id, acessos); // Incrementa o contador de reproduções no catálogo
            cout << "Tocando: " << anterior->titulo << " - " << anterior->artista << endl;
            break;
        }
        case 6:
        {
            Musica *atual = minhaplaylist.musicaAtual(); // Mostra a música atual, nullptr se vazia
            if (atual == nullptr)
            {
                cout << "Playlist vazia." << endl;
                break;
            }
            cout << "Musica atual: " << atual->titulo << " - " << atual->artista << endl;
            break;
        }
        case 7:
        {
            minhaplaylist.listar();
            break;
        }
        case 8:
        {
            int acessos = 0;
            string nomemusica;
            cout << "Insira o nome da musica que voce quer buscar: ";
            cin.ignore();             // Tira o enter de opcao
            getline(cin, nomemusica); // Lê o nome inteiro, mesmo com espaços
            int tamanho = 0;
            vector<Musica> v = minhaplaylist.TransformarparaVetor(tamanho);
            int pos = buscaSequencialNome(v.data(), tamanho, nomemusica, acessos);
            if (pos == -1)
            { // Se a posição for -1 é porque ela não existe
                cout << "Musica nao encontrada na playlist." << endl;
                break;
            }
            Musica achada = v[pos];
            int ac = 0;
            Musica *atualizada = catalogo.buscarPorID(achada.id, ac);
            if (atualizada != nullptr)
                achada = *atualizada;
            cout << "Titulo: " << achada.titulo << endl;
            cout << "Artista: " << achada.artista << endl;
            cout << "Duracao: " << achada.duracaoSegundos << "S" << endl;
            cout << "Reproducoes: " << achada.reproducoes << endl;
            cout << "Comparacoes: " << acessos << endl;
            break;
        }
        case 9:
        {
            int acessos = 0;
            cout << "Insira o ID da musica: ";
            cin >> id;
            Musica *musicainserir = catalogo.buscarPorID(id, acessos); // Busco a música no  catálogo pelo ID
            if (musicainserir == nullptr)
            { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                cout << "ID não encontrado" << endl;
                break;
            }
            reproducao.adicionar(*musicainserir); // Adiciona a música achada
            cout << "Musica adicionada com sucesso!" << endl;
            break;
        }
        case 10:
        {
            reproducao.tocarProxima(catalogo);
            break;
        }
        case 11:
        {
            reproducao.verProxima();
            break;
        }
        case 12:
        {
            reproducao.verTamanho();
            break;
        }
        case 13:
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
        case 14:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;
            int acessos = 0;
            Musica *musicaachada = catalogo.buscarPorID(id, acessos); // Busco a música no  catálogo pelo ID
            if (musicaachada == nullptr)
            { // Se nenhuma música com esse ID foi encontrada, Avisa e sai do case
                cout << "ID não encontrado  (" << acessos << " acessos)" << endl;
                break;
            }
            cout << "Titulo: " << musicaachada->titulo << endl;
            cout << "artista: " << musicaachada->artista << endl;
            cout << "duracao: " << musicaachada->duracaoSegundos << "S" << endl;
            cout << "reproducoes: " << musicaachada->reproducoes << endl;
            break;
        }
        case 15:
        {
            cout << "Insira o ID da musica: ";
            cin >> id;

            // Tenta remover do catálogo (ABB). Se o ID não existe, avisa e sai
            if (!catalogo.remover(id))
            {
                cout << "ID não encontrado" << endl;
                break;
            }

            reproducao.removerPorId(id); // Remove a música da fila de reprodução, se estiver lá

            // A música saiu do catálogo, então também sai da playlist (se estiver lá)
            if (minhaplaylist.contem(id))
            {
                minhaplaylist.remover(id);
            }

            cout << "Musica removida com sucesso!" << endl;
            break;
        }
        case 16:
        {
            catalogo.listarEmOrdem();
            break;
        }
        case 17:
        {
            int altura = catalogo.altura();
            cout << "A altura e: " << altura << endl;
            break;
        }
        case 18:
        {
            int contagem = catalogo.contagemDeNos();
            cout << "A contagem e: " << contagem << endl;
            break;
        }
        case 19:
        {
            int tamanho = 0;
            int comparacoes = 0;
            int trocas = 0;
            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0)
            { // Se o tamanho for 0 (não ter musicas no catalogo)
                cout << "Catalogo vazio." << endl;
                break;
            }
            quickSort(v.data(), tamanho, comparacoes, trocas, 0, tamanho - 1); // Naturalmente os vetores passam os endereços da primeira posição como parâmetro, mas não funciona ssim nessa biblioteca e então usamos a função data()
            for (int i = 0; i < tamanho; i++)
            {
                cout << i + 1 << " lugar: " << v[i].titulo << " - " << v[i].reproducoes << "repeticoes" << endl;
            }
            break;
        }
        case 20:
        {
            int tamanho = 0;
            int comparacoes = 0;
            int trocas = 0;
            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0)
            { // Se o tamanho for 0 (não ter musicas no catalogo)
                cout << "Catalogo vazio." << endl;
                break;
            }
            quickSort(v.data(), tamanho, comparacoes, trocas, 0, tamanho - 1); // Naturalmente os vetores passam os endereços da primeira posição como parâmetro, mas não funciona ssim nessa biblioteca e então usamos a função data()
            cout << "A musica mais tocada e: " << v.front().titulo << " - Reproducoes:" << v.front().reproducoes << endl;
            break;
        }
        case 21:
        {
            int tamanho = 0;
            int comparacoes = 0;
            int trocas = 0;
            int acessos = 0;
            int repetir;

            cout << "Insira a quantidade de reproducoes da musica: ";
            cin >> repetir;

            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0)
            { // Catálogo vazio
                cout << "Catalogo vazio." << endl;
                break;
            }

            // A busca binária exige o vetor ordenado pela mesma chave 
            quickSort(v.data(), tamanho, comparacoes, trocas, 0, tamanho - 1);

            int pos = buscaBinaria(v.data(), tamanho, repetir, acessos);
            if (pos == -1)
            {
                cout << "Nao existem musicas com essa quantidade de reproducoes ("
                     << acessos << " acessos)" << endl;
            }
            else
            {
                cout << "Musica encontrada: " << v[pos].titulo << " - " << v[pos].artista
                     << " (" << v[pos].reproducoes << " reproducoes, "
                     << pos + 1 << "o lugar no ranking, " << acessos << " acessos)" << endl;
            }
            break;
        }
        case 22:
        {
            modoTeste();
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
// Identação com shift + alt + f, atalho do VS Code.