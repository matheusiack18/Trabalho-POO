#include "ListaOrdenada.h"
#include <iostream>
#include <stdexcept>
#include <locale.h>

/**
 * @brief Construtor padrão
 * @param capacidadeInicial Capacidade inicial da lista
 * 
 * Complexidade: O(1) - alocação de memória constante
 */
ListaOrdenada::ListaOrdenada(int capacidadeInicial) 
    : capacidade(capacidadeInicial), tamanho(0) {
    if (capacidadeInicial <= 0) {
        throw std::invalid_argument("Capacidade deve ser maior que zero");
    }
    elementos = new std::unique_ptr<Elemento>[capacidade];
}

/**
 * @brief Destrutor
 * 
 * Complexidade: O(n) - libera memória de todos os elementos
 */
ListaOrdenada::~ListaOrdenada() {
    delete[] elementos;
}

/**
 * @brief Construtor de cópia
 * 
 * Complexidade: O(n) - copia todos os elementos
 */
ListaOrdenada::ListaOrdenada(const ListaOrdenada& outra) 
    : capacidade(outra.capacidade), tamanho(outra.tamanho) {
    elementos = new std::unique_ptr<Elemento>[capacidade];
    
    for (int i = 0; i < tamanho; i++) {
        elementos[i] = std::move(const_cast<ListaOrdenada&>(outra).elementos[i]);
    }
}

/**
 * @brief Operador de atribuição
 * 
 * Complexidade: O(n) - copia todos os elementos
 */
ListaOrdenada& ListaOrdenada::operator=(const ListaOrdenada& outra) {
    if (this != &outra) {
        delete[] elementos;
        
        capacidade = outra.capacidade;
        tamanho = outra.tamanho;
        elementos = new std::unique_ptr<Elemento>[capacidade];
        
        for (int i = 0; i < tamanho; i++) {
            elementos[i] = std::move(const_cast<ListaOrdenada&>(outra).elementos[i]);
        }
    }
    return *this;
}

/**
 * @brief Redimensiona o array quando necessário
 * 
 * Complexidade: O(n) - precisa copiar todos os elementos
 */
void ListaOrdenada::redimensionar() {
    int novaCapacidade = capacidade * 2;
    std::unique_ptr<Elemento>* novosElementos = new std::unique_ptr<Elemento>[novaCapacidade];
    
    // Move todos os elementos para o novo array
    for (int i = 0; i < tamanho; i++) {
        novosElementos[i] = std::move(elementos[i]);
    }
    
    delete[] elementos;
    elementos = novosElementos;
    capacidade = novaCapacidade;
    
    std::cout << "Lista ordenada redimensionada para capacidade: " << capacidade << std::endl;
}

/**
 * @brief Busca binária por ID
 * @param id ID procurado
 * @return Índice do elemento (ou -1 se não encontrado)
 * 
 * Complexidade: O(log n) - busca binária clássica
 */
int ListaOrdenada::buscaBinaria(long id) const {
    int esquerda = 0;
    int direita = tamanho - 1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (elementos[meio]->getID() == id) {
            return meio; // Encontrado
        }
        
        if (elementos[meio]->getID() < id) {
            esquerda = meio + 1; // Busca na metade direita
        } else {
            direita = meio - 1;  // Busca na metade esquerda
        }
    }
    
    return -1; // Não encontrado
}

/**
 * @brief Encontra a posição correta para inserir um elemento
 * @param id ID do elemento a ser inserido
 * @return Índice onde o elemento deve ser inserido para manter ordenação
 * 
 * Complexidade: O(log n) - busca binária para encontrar posição
 */
int ListaOrdenada::encontrarPosicaoInsercao(long id) const {
    int esquerda = 0;
    int direita = tamanho;
    
    while (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (elementos[meio]->getID() < id) {
            esquerda = meio + 1;
        } else {
            direita = meio;
        }
    }
    
    return esquerda;
}

/**
 * @brief Insere elemento mantendo a ordenação por ID
 * @param elemento Ponteiro único para o elemento a ser inserido
 * 
 * Complexidade: O(n) - busca binária O(log n) + deslocamento O(n)
 */
void ListaOrdenada::InserirOrdenado(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        throw std::invalid_argument("Elemento não pode ser nulo");
    }
    
    // Verifica se precisa redimensionar
    if (tamanho >= capacidade) {
        redimensionar();
    }
    
    // Encontra a posição correta para inserção
    int posicao = encontrarPosicaoInsercao(elemento->getID());
    
    // Desloca elementos para a direita para abrir espaço
    for (int i = tamanho; i > posicao; i--) {
        elementos[i] = std::move(elementos[i-1]);
    }
    
    // Insere o elemento na posição correta
    elementos[posicao] = std::move(elemento);
    tamanho++;
}

/**
 * @brief Insere elemento no início da lista (mantém ordenação)
 * @param elemento Ponteiro único para o elemento a ser inserido
 * 
 * Complexidade: O(n) - busca binária O(log n) + inserção ordenada O(n)
 * Nota: Insere na posição correta, não necessariamente no início
 */
void ListaOrdenada::InserirNoInicio(std::unique_ptr<Elemento> elemento) {
    // Em uma lista ordenada, "inserir no início" significa inserir ordenadamente
    InserirOrdenado(std::move(elemento));
}

/**
 * @brief Insere elemento no final da lista (mantém ordenação)
 * @param elemento Ponteiro único para o elemento a ser inserido
 * 
 * Complexidade: O(n) - busca binária O(log n) + inserção ordenada O(n)
 * Nota: Insere na posição correta, não necessariamente no final
 */
void ListaOrdenada::InserirNoFinal(std::unique_ptr<Elemento> elemento) {
    // Em uma lista ordenada, "inserir no final" significa inserir ordenadamente
    InserirOrdenado(std::move(elemento));
}

/**
 * @brief Remove o primeiro elemento da lista
 * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
 * 
 * Complexidade: O(n) - precisa deslocar todos os elementos uma posição à esquerda
 */
std::unique_ptr<Elemento> ListaOrdenada::RemoverPrimeiro() {
    if (tamanho == 0) {
        return nullptr;
    }
    
    // Guarda o primeiro elemento para retornar
    std::unique_ptr<Elemento> elementoRemovido = std::move(elementos[0]);
    
    // Desloca todos os elementos uma posição à esquerda
    for (int i = 0; i < tamanho - 1; i++) {
        elementos[i] = std::move(elementos[i+1]);
    }
    
    tamanho--;
    return elementoRemovido;
}

/**
 * @brief Remove o último elemento da lista
 * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
 * 
 * Complexidade: O(1) - remoção direta da última posição
 */
std::unique_ptr<Elemento> ListaOrdenada::RemoverUltimo() {
    if (tamanho == 0) {
        return nullptr;
    }
    
    // Remove e retorna o último elemento
    std::unique_ptr<Elemento> elementoRemovido = std::move(elementos[tamanho-1]);
    tamanho--;
    return elementoRemovido;
}

/**
 * @brief Remove elemento com ID específico
 * @param id ID do elemento a ser removido
 * @return Ponteiro único para o elemento removido (nullptr se não encontrado)
 * 
 * Complexidade: O(n) - busca binária O(log n) + deslocamento O(n)
 */
std::unique_ptr<Elemento> ListaOrdenada::RemoverPeloId(long id) {
    // Busca binária pelo elemento
    int indice = buscaBinaria(id);
    
    if (indice == -1) {
        return nullptr; // Elemento não encontrado
    }
    
    // Guarda o elemento para retornar
    std::unique_ptr<Elemento> elementoRemovido = std::move(elementos[indice]);
    
    // Desloca elementos posteriores uma posição à esquerda
    for (int i = indice; i < tamanho - 1; i++) {
        elementos[i] = std::move(elementos[i+1]);
    }
    
    tamanho--;
    return elementoRemovido;
}

/**
 * @brief Busca elemento pelo ID usando busca binária
 * @param id ID do elemento procurado
 * @return Ponteiro para o elemento (nullptr se não encontrado)
 * 
 * Complexidade: O(log n) - busca binária otimizada
 */
Elemento* ListaOrdenada::BuscarPeloId(long id) const {
    int indice = buscaBinaria(id);
    
    if (indice != -1) {
        return elementos[indice].get();
    }
    
    return nullptr; // Elemento não encontrado
}

/**
 * @brief Altera elemento com ID específico
 * @param id ID do elemento a ser alterado
 * @param novoElemento Novo elemento para substituir o existente
 * @return true se a alteração foi bem-sucedida, false se ID não encontrado
 * 
 * Complexidade: O(log n) se o novo elemento tem o mesmo ID
 *               O(n) se precisa remover e inserir em nova posição
 */
bool ListaOrdenada::AlterarPeloId(long id, std::unique_ptr<Elemento> novoElemento) {
    if (!novoElemento) {
        return false;
    }
    
    int indice = buscaBinaria(id);
    
    if (indice == -1) {
        return false; // Elemento não encontrado
    }
    
    // Se o novo elemento tem o mesmo ID, substitui diretamente
    if (novoElemento->getID() == id) {
        elementos[indice] = std::move(novoElemento);
        return true;
    }
    
    // Se o ID mudou, precisa remover e inserir na posição correta
    // Remove o elemento atual
    for (int i = indice; i < tamanho - 1; i++) {
        elementos[i] = std::move(elementos[i+1]);
    }
    tamanho--;
    
    // Insere o novo elemento na posição correta
    InserirOrdenado(std::move(novoElemento));
    return true;
}

/**
 * @brief Retorna o número de elementos na lista
 * @return Tamanho atual da lista
 * 
 * Complexidade: O(1) - acesso direto ao atributo
 */
int ListaOrdenada::getTamanho() const {
    return tamanho;
}

/**
 * @brief Verifica se a lista está vazia
 * @return true se a lista está vazia
 * 
 * Complexidade: O(1) - verificação simples
 */
bool ListaOrdenada::estaVazia() const {
    return tamanho == 0;
}

/**
 * @brief Retorna a capacidade atual da lista
 * @return Capacidade máxima atual
 * 
 * Complexidade: O(1) - acesso direto ao atributo
 */
int ListaOrdenada::getCapacidade() const {
    return capacidade;
}

/**
 * @brief Imprime todos os elementos da lista (já ordenados)
 * 
 * Complexidade: O(n) - percorre todos os elementos
 */
void ListaOrdenada::imprimirLista() const {
    std::cout << "=== LISTA ORDENADA ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << " | Capacidade: " << capacidade << std::endl;
    
    if (tamanho == 0) {
        std::cout << "Lista vazia!" << std::endl;
    } else {
        for (int i = 0; i < tamanho; i++) {
            std::cout << "\n[" << i << "] ID: " << elementos[i]->getID() << " ";
            if (elementos[i]) {
                elementos[i]->imprimirInfo();
            } else {
                std::cout << "Elemento nulo" << std::endl;
            }
        }
    }
    std::cout << "======================" << std::endl;
}

/**
 * @brief Limpa todos os elementos da lista
 * 
 * Complexidade: O(n) - libera memória de todos os elementos
 */
void ListaOrdenada::limpar() {
    for (int i = 0; i < tamanho; i++) {
        elementos[i].reset();
    }
    tamanho = 0;
}

/**
 * @brief Obtém elemento por índice (para acesso direto)
 * @param indice Índice do elemento (0-based)
 * @return Ponteiro para o elemento (nullptr se índice inválido)
 * 
 * Complexidade: O(1) - acesso direto por índice
 */
Elemento* ListaOrdenada::obterElementoPorIndice(int indice) const {
    if (indice < 0 || indice >= tamanho) {
        return nullptr;
    }
    
    return elementos[indice].get();
}

/**
 * @brief Verifica se a lista está ordenada (método de teste)
 * @return true se a lista está corretamente ordenada por ID
 * 
 * Complexidade: O(n) - verifica ordenação sequencial
 */
bool ListaOrdenada::verificarOrdenacao() const {
    for (int i = 1; i < tamanho; i++) {
        if (elementos[i-1]->getID() > elementos[i]->getID()) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Busca o menor ID na lista
 * @return Ponteiro para o elemento com menor ID (nullptr se lista vazia)
 * 
 * Complexidade: O(1) - primeiro elemento em lista ordenada
 */
Elemento* ListaOrdenada::obterMenorElemento() const {
    if (tamanho == 0) {
        return nullptr;
    }
    return elementos[0].get();
}

/**
 * @brief Busca o maior ID na lista
 * @return Ponteiro para o elemento com maior ID (nullptr se lista vazia)
 * 
 * Complexidade: O(1) - último elemento em lista ordenada
 */
Elemento* ListaOrdenada::obterMaiorElemento() const {
    if (tamanho == 0) {
        return nullptr;
    }
    return elementos[tamanho-1].get();
}
