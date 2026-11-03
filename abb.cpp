//Matheus Viana R. Pereira - Catálogo de Músicas com ABB
#include <iostream> 
#include "abb.hpp"
using namespace std;

catalogoMusicas::catalogoMusicas() : raiz(nullptr) {} // Construtor para inicializar a árvore vazia
catalogoMusicas::~catalogoMusicas() { destruir(raiz); } // Destrutor para liberar a memória alocada para os nós da árvore

No* catalogoMusicas::inserirRecursivo(No* no, const Musica& m, bool& ok) { // Função auxiliar recursiva para inserir uma música na árvore
    if (no == nullptr) {
        ok = true;
        return new No(m);
    }
    if (m.id < no->musica.id) {
        no->esquerdo = inserirRecursivo(no->esquerdo, m, ok);
    } else if (m.id > no->musica.id) {
        no->direito = inserirRecursivo(no->direito, m, ok);
    } else {
        ok = false; // ID já existe na árvore
    }
    return no;
}

No* catalogoMusicas::minimoRecursivo(No* no) { // Função auxiliar para encontrar o nó com o menor ID na subárvore
    if (no == nullptr || no->esquerdo == nullptr) {
        return no;
    }
    return minimoRecursivo(no->esquerdo);
}

No* catalogoMusicas::removerRecursivo(No* no, int id, bool& ok) { // Função auxiliar recursiva para remover uma música da árvore pelo ID
    if (no == nullptr) {
        ok = false; // ID não encontrado
        return nullptr;
    }
    if (id < no->musica.id) {
        no->esquerdo = removerRecursivo(no->esquerdo, id, ok);
    } else if (id > no->musica.id) {
        no->direito = removerRecursivo(no->direito, id, ok);
    } else {
        ok = true; // ID encontrado
        if (no->esquerdo == nullptr) {
            No* temp = no->direito;
            delete no;
            return temp;
        } else if (no->direito == nullptr) {
            No* temp = no->esquerdo;
            delete no;
            return temp;
        } else {
            No* temp = minimoRecursivo(no->direito);
            no->musica = temp->musica;
            no->direito = removerRecursivo(no->direito, temp->musica.id, ok);
        }
    }
    return no;
}

Musica* catalogoMusicas::buscarRecursivo(No* no, int id) { // Função auxiliar recursiva para buscar uma música na árvore pelo ID
    if (no == nullptr) {
        return nullptr; // ID não encontrado
    }
    if (id < no->musica.id) {
        return buscarRecursivo(no->esquerdo, id);
    } else if (id > no->musica.id) {
        return buscarRecursivo(no->direito, id);
    } else {
        return &(no->musica); // ID encontrado
    }
}

void catalogoMusicas::emOrdemRecursivo(No* no) { // Função auxiliar recursiva para listar as músicas em ordem crescente de ID
    if (no != nullptr) {
        emOrdemRecursivo(no->esquerdo);
        cout << "ID: " << no->musica.id << ", Título: " << no->musica.titulo << ", Artista: " << no->musica.artista 
            << ", Duração: " << no->musica.duracaoSegundos << "s, Reproduções: " << no->musica.reproducoes << endl;
        emOrdemRecursivo(no->direito);
    }
}

int catalogoMusicas::alturaRecursivo(No* no) { // Função auxiliar recursiva para calcular a altura da árvore
    if (no == nullptr) {
        return 0;
    }
    int alturaEsquerda = alturaRecursivo(no->esquerdo);
    int alturaDireita = alturaRecursivo(no->direito);
    return 1 + max(alturaEsquerda, alturaDireita);
}

int catalogoMusicas::contarRecursivo(No* no) { // Função auxiliar recursiva para contar o número de nós na árvore
    if (no == nullptr) {
        return 0;
    }
    return 1 + contarRecursivo(no->esquerdo) + contarRecursivo(no->direito); // Retorna 1 (para o nó atual) mais a contagem dos nós na subárvore esquerda e direita
}

void catalogoMusicas::destruir(No* no) { // Função auxiliar para liberar a memória alocada para os nós da árvore
    if (no != nullptr) {
        destruir(no->esquerdo);
        destruir(no->direito);
        delete no;
    }
}

bool catalogoMusicas::inserir(Musica musica) { // Função pública para inserir uma música na árvore
    bool ok = false;
    raiz = inserirRecursivo(raiz, musica, ok);
    return ok; // Retorna true se a inserção foi bem-sucedida, false caso contrário
}

bool catalogoMusicas::remover(int id) { // Função pública para remover uma música da árvore pelo ID
    bool ok = false;
    raiz = removerRecursivo(raiz, id, ok);
    return ok; // Retorna true se a remoção foi bem-sucedida, false caso contrário
}

Musica* catalogoMusicas::buscarPorID(int id) { // Função pública para buscar uma música na árvore pelo ID
    return buscarRecursivo(raiz, id); // Retorna ponteiro para a música se encontrada, nullptr caso contrário
}

void catalogoMusicas::listarEmOrdem() { // Função pública para listar todas as músicas da árvore em ordem crescente de ID
    emOrdemRecursivo(raiz);
}

int catalogoMusicas::altura() { // Função pública para retornar a altura da árvore
    return alturaRecursivo(raiz);
}

int catalogoMusicas::contagemDeNos() { // Função pública para retornar a quantidade de nós na árvore
    return contarRecursivo(raiz);
}