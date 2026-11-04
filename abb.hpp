// Matheus Viana R. Pereira - Catálogo de Músicas com ABB
#ifndef ABB_HPP
#define ABB_HPP

#include "musica.hpp"
using namespace std;

struct No
{                  // Estrutura para representar um nó da árvore binária de busca
    Musica musica; // música armazenada no nó
    No *direito;   // Ponteiro para o nó direito
    No *esquerdo;  // Ponteiro para o nó esquerdo

    No(Musica m) : musica(m), direito(nullptr), esquerdo(nullptr) {} // Construtor para inicializar o nó com uma música e ponteiros nulos
};

class catalogoMusicas
{
private:
    No *raiz;
    // Funções auxiliares recursivas
    No *inserirRecursivo(No *no, const Musica &m, bool &ok); // "ok" indica se a inserção foi bem-sucedida
    No *removerRecursivo(No *no, int id, bool &ok);          // "ok" indica se a remoção foi bem-sucedida
    No *minimoRecursivo(No *no);
    Musica *buscarRecursivo(No *no, int id);
    void emOrdemRecursivo(No *no);
    int alturaRecursivo(No *no);
    int contarRecursivo(No *no);
    void destruir(No *no);

public:
    catalogoMusicas();           // Construtor para inicializar a árvore vazia
    ~catalogoMusicas();          // Destrutor para liberar a memória alocada para os nós da árvore
    bool inserir(Musica musica); // Insere uma música na árvore, retorna true se inserido com sucesso
    Musica *buscarPorID(int id); // Busca uma música na árvore pelo ID, retorna ponteiro para a música se encontrada, nullptr caso contrário
    bool remover(int id);        // Remove uma música da árvore pelo ID, retorna true se removido com sucesso
    void listarEmOrdem();        // Lista todas as músicas da árvore em ordem crescente de ID
    int altura();                // Retorna a altura da árvore
    int contagemDeNos();         // Retorna a quantidade de nós na árvore
};

#endif
// Identação com shift + alt + f, atalho do VS Code.