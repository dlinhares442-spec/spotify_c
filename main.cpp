#include <iostream>
#include <string>
#include <vector> // Vetor do catálogo (cases 16 a 18)
#include "musica.hpp"
#include "catalogo.hpp"
#include "playlist.hpp"
#include "fila_reproducao.hpp"
#include "busca.hpp"
#include "ordenacao.hpp"
// #include "teste.hpp"           // Ainda não usado: entra quando o modo de teste (19) for feito
using namespace std;

int main()
{
    int opcao;
    int nplaylist = 0;
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
        cout << " 5 - Buscar na playlist (pelo nome)" << endl;
        cout << "\n--- FILA DE REPRODUCAO ---" << endl;
        cout << " 6 - Adicionar na fila" << endl; // Adiciona uma música à fila de reprodução pelo ID
        cout << " 7 - Tocar proxima" << endl; // Toca a próxima música da fila de reprodução e incrementa o contador de reproduções no catálogo
        cout << " 8 - Ver proxima" << endl; // Mostra a próxima música da fila de reprodução sem removê-la
        cout << " 9 - Ver tamanho da fila" << endl; // Mostra a quantidade de músicas na fila de reprodução
        cout << "\n--- CATALOGO (ABB) ---" << endl;
        cout << "10 - Inserir musica" << endl; // Insere uma nova música no catálogo (ABB) com todas as informações
        cout << "11 - Buscar por ID" << endl; // Busca uma música no catálogo (ABB) pelo ID e mostra todas as informações dela
        cout << "12 - Remover musica" << endl; // Remove uma música do catálogo (ABB) pelo ID
        cout << "13 - Listar em ordem de ID" << endl; // Lista todas as músicas do catálogo (ABB) em ordem crescente de ID
        cout << "14 - Altura da arvore" << endl; // Mostra a altura da árvore (ABB)
        cout << "15 - Quantidade de nos" << endl; // Mostra a quantidade de nós na árvore (ABB)
        cout << "\n--- RANKING ---" << endl;
        cout << "16 - Mostrar ranking (mais tocadas primeiro)" << endl; // Mostra o ranking ordenado por repetições das mais tocadas para as menos
        cout << "17 - Musica mais reproduzida" << endl; // Mostra a musica com mais reproducoes
        cout << "18 - Buscar no ranking por reproducoes" << endl; // Busca uma musica pela quantidade de reproduções
        cout << "19 - Modo de teste (50, 500 e 5000 registros)" << endl;
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
            nplaylist++;
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
            nplaylist--;
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
            int acessos=0;
            string nomemusica;
            cout << "Insira o nome da musica que voce quer buscar: ";
            cin.ignore(); // Tira o enter de opcao
            getline(cin, nomemusica); // Lê o nome inteiro, mesmo com espaços
            int tamanho = 0;
            vector<Musica> v = minhaplaylist.TransformarparaVetor(tamanho);
            int pos = buscaSequencialNome(v.data(), tamanho, nomemusica, acessos);
            if (pos == -1) { // Se a posição for -1 é porque ela não existe
                cout << "Musica nao encontrada na playlist." << endl;
                break;
            }
            Musica achada = v[pos];
            cout << "Titulo: " << achada.titulo << endl;
            cout << "Artista: " << achada.artista << endl;
            cout << "Duracao: " << achada.duracaoSegundos << "S" << endl;
            cout << "Reproducoes: " << achada.reproducoes << endl;
            cout << "Comparacoes: " << acessos << endl;
            break;
        }
        case 6:
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
        case 7:
        {
            reproducao.tocarProxima(catalogo);
            break;
        }
        case 8:
        {
            reproducao.verProxima();
            break;
        }
        case 9:
        {
            reproducao.verTamanho();
            break;
        }
        case 10:
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
        case 11:
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
        case 12:
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
                nplaylist--; // Saiu da playlist, então diminui a quantidade de músicas
            }

            cout << "Musica removida com sucesso!" << endl;
            break;
        }
        case 13:
        {
            catalogo.listarEmOrdem(); 
            break;
        }
        case 14:
        {
            int altura = catalogo.altura();
            cout << "A altura e: " << altura << endl;
            break;
        }
        case 15:
        {
            int contagem = catalogo.contagemDeNos();
            cout << "A contagem e: " << contagem << endl;
            break;
        }
        case 16:
        {
            int tamanho = 0;
            int comparacoes = 0;
            int trocas = 0;
            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0) { // Se o tamanho for 0 (não ter musicas no catalogo)
                cout << "Catalogo vazio." << endl;
                break;
            } 
            quickSort (v.data(), tamanho, comparacoes, trocas, 0, tamanho-1); // Naturalmente os vetores passam os endereços da primeira posição como parâmetro, mas não funciona ssim nessa biblioteca e então usamos a função data()
            for (int i=0;i<tamanho;i++) {
                cout << i+1 << " lugar: " << v[i].titulo << " - " << v[i].reproducoes << "repeticoes" << endl;
            }
            break;
        }
        case 17:
        {
            int tamanho = 0;
            int comparacoes = 0;
            int trocas = 0;
            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0) { // Se o tamanho for 0 (não ter musicas no catalogo)
                cout << "Catalogo vazio." << endl;
                break;
            } 
            quickSort (v.data(), tamanho, comparacoes, trocas, 0, tamanho-1); // Naturalmente os vetores passam os endereços da primeira posição como parâmetro, mas não funciona ssim nessa biblioteca e então usamos a função data()
            cout << "A musica mais tocada e: " << v.front().titulo << " - Reproducoes:" << v.front().reproducoes << endl;
            break;
        }
        case 18:
        {
            int tamanho = 0;
            int repetir;
            cout << "Insira a quantidade de repeticoes da música: ";
            cin >> repetir;
            vector<Musica> v = catalogo.TransformarparaVetor(tamanho);
            if (tamanho == 0) { // Se o tamanho for 0 (não ter musicas no catalogo)
                cout << "Catalogo vazio." << endl;
                break;
            } 
            Musica achada;
            achada.id=-1;
            for (int i=0;i<tamanho;i++) {
                if (repetir==v[i].reproducoes) {
                    achada = v[i];
                    break;
                }
            }
            if (achada.id==-1) {
                cout << "Nao existem musicas com essa quantidade de reproducoes" << endl;
            }
            else {
                cout << "Musica encontrada: " << achada.titulo << endl;
            }
            break;
        }
        case 19:
        {
            // A espera do teste
            cout << "Opcao ainda em construcao." << endl;
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
