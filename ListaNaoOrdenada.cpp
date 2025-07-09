#include "ListaNaoOrdenada.h"
#include <iostream>
#include <stdexcept>
#include <locale.h>

/**
 * @brief Construtor padrão
 * @param capacidadeInicial Capacidade inicial da lista
 * 
 * Complexidade: O(1) - alocação de memória constante
 */
ListaNaoOrdenada::ListaNaoOrdenada(int capacidadeInicial) 
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
ListaNaoOrdenada::~ListaNaoOrdenada() {
    delete[] elementos;
}

/**
 * @brief Construtor de cópia
 * 
 * Complexidade: O(n) - copia todos os elementos
 */
ListaNaoOrdenada::ListaNaoOrdenada(const ListaNaoOrdenada& outra) 
    : capacidade(outra.capacidade), tamanho(outra.tamanho) {
    elementos = new std::unique_ptr<Elemento>[capacidade];
    
    for (int i = 0; i < tamanho; i++) {
        elementos[i] = std::move(const_cast<ListaNaoOrdenada&>(outra).elementos[i]);
    }
}

/**
 * @brief Operador de atribuição
 * 
 * Complexidade: O(n) - copia todos os elementos
 */
ListaNaoOrdenada& ListaNaoOrdenada::operator=(const ListaNaoOrdenada& outra) {
    if (this != &outra) {
        delete[] elementos;
        
        capacidade = outra.capacidade;
        tamanho = outra.tamanho;
        elementos = new std::unique_ptr<Elemento>[capacidade];
        
        for (int i = 0; i < tamanho; i++) {
            elementos[i] = std::move(const_cast<ListaNaoOrdenada&>(outra).elementos[i]);
        }
    }
    return *this;
}

/**
 * @brief Redimensiona o array quando necessário
 * 
 * Complexidade: O(n) - precisa copiar todos os elementos
 */
void ListaNaoOrdenada::redimensionar() {
    int novaCapacidade = capacidade * 2;
    std::unique_ptr<Elemento>* novosElementos = new std::unique_ptr<Elemento>[novaCapacidade];
    
    for (int i = 0; i < tamanho; i++) {
        novosElementos[i] = std::move(elementos[i]);
    }
    
    delete[] elementos;
    elementos = novosElementos;
    capacidade = novaCapacidade;
    
    std::cout << "Lista redimensionada para capacidade: " << capacidade << std::endl;
}

/**
 * @brief Insere elemento no início da lista
 * @param elemento Ponteiro único para o elemento a ser inserido
 * 
 * Complexidade: O(n) - precisa deslocar todos os elementos uma posição à direita
 */
void ListaNaoOrdenada::InserirNoInicio(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        throw std::invalid_argument("Elemento não pode ser nulo");
    }
    
    // Verifica se precisa redimensionar
    if (tamanho >= capacidade) {
        redimensionar();
    }
    
    // Desloca todos os elementos uma posição à direita
    for (int i = tamanho; i > 0; i--) {
        elementos[i] = std::move(elementos[i-1]);
    }
    
    // Insere o novo elemento na primeira posição
    elementos[0] = std::move(elemento);
    tamanho++;
}

/**
 * @brief Insere elemento no final da lista
 * @param elemento Ponteiro único para o elemento a ser inserido
 * 
 * Complexidade: O(1) amortizado - inserção direta na última posição
 *               O(n) no pior caso quando precisa redimensionar
 */
void ListaNaoOrdenada::InserirNoFinal(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        throw std::invalid_argument("Elemento não pode ser nulo");
    }
    
    // Verifica se precisa redimensionar
    if (tamanho >= capacidade) {
        redimensionar();
    }
    
    // Insere o elemento na última posição
    elementos[tamanho] = std::move(elemento);
    tamanho++;
}

/**
 * @brief Remove o primeiro elemento da lista
 * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
 * 
 * Complexidade: O(n) - precisa deslocar todos os elementos uma posição à esquerda
 */
std::unique_ptr<Elemento> ListaNaoOrdenada::RemoverPrimeiro() {
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
std::unique_ptr<Elemento> ListaNaoOrdenada::RemoverUltimo() {
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
 * Complexidade: O(n) - busca linear + deslocamento dos elementos posteriores
 */
std::unique_ptr<Elemento> ListaNaoOrdenada::RemoverPeloId(long id) {
    // Busca linear pelo elemento
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i] && elementos[i]->getID() == id) {
            // Guarda o elemento para retornar
            std::unique_ptr<Elemento> elementoRemovido = std::move(elementos[i]);
            
            // Desloca elementos posteriores uma posição à esquerda
            for (int j = i; j < tamanho - 1; j++) {
                elementos[j] = std::move(elementos[j+1]);
            }
            
            tamanho--;
            return elementoRemovido;
        }
    }
    
    return nullptr; // Elemento não encontrado
}

/**
 * @brief Busca elemento pelo ID
 * @param id ID do elemento procurado
 * @return Ponteiro para o elemento (nullptr se não encontrado)
 * 
 * Complexidade: O(n) - busca linear sequencial
 */
Elemento* ListaNaoOrdenada::BuscarPeloId(long id) const {
    // Busca linear sequencial
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i] && elementos[i]->getID() == id) {
            return elementos[i].get();
        }
    }
    
    return nullptr; // Elemento não encontrado
}

/**
 * @brief 
 * @param id 
 * @param novoElemento 
 * @return 
 * 
 * Complexidade: O(n) - busca linear para encontrar o elemento
 */
bool ListaNaoOrdenada::AlterarPeloId(long id, std::unique_ptr<Elemento> novoElemento) {
    if (!novoElemento) {
        return false;
    }
    
    // Busca linear pelo elemento
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i] && elementos[i]->getID() == id) {
            // Substitui o elemento
            elementos[i] = std::move(novoElemento);
            return true;
        }
    }
    
    return false; // Elemento não encontrado
}

/**
 * @brief Retorna o número de elementos na lista
 * @return Tamanho atual da lista
 * 
 * Complexidade: O(1) - acesso direto ao atributo
 */
int ListaNaoOrdenada::getTamanho() const {
    return tamanho;
}

/**
 * @brief Verifica se a lista está vazia
 * @return true se a lista está vazia
 * 
 * Complexidade: O(1) - verificação simples
 */
bool ListaNaoOrdenada::estaVazia() const {
    return tamanho == 0;
}

/**
 * @brief Retorna a capacidade atual da lista
 * @return Capacidade máxima atual
 * 
 * Complexidade: O(1) - acesso direto ao atributo
 */
int ListaNaoOrdenada::getCapacidade() const {
    return capacidade;
}

/**
 * @brief Imprime todos os elementos da lista
 * 
 * Complexidade: O(n) - percorre todos os elementos
 */
void ListaNaoOrdenada::imprimirLista() const {
    std::cout << "=== LISTA NÃO ORDENADA ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << " | Capacidade: " << capacidade << std::endl;
    
    if (tamanho == 0) {
        std::cout << "Lista vazia!" << std::endl;
    } else {
        for (int i = 0; i < tamanho; i++) {
            std::cout << "\n[" << i << "] ";
            if (elementos[i]) {
                elementos[i]->imprimirInfo();
            } else {
                std::cout << "Elemento nulo" << std::endl;
            }
        }
    }
    std::cout << "=========================" << std::endl;
}

/**
 * @brief Limpa todos os elementos da lista
 * 
 * Complexidade: O(n) - libera memória de todos os elementos
 */
void ListaNaoOrdenada::limpar() {
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
Elemento* ListaNaoOrdenada::obterElementoPorIndice(int indice) const {
    if (indice < 0 || indice >= tamanho) {
        return nullptr;
    }
    
    return elementos[indice].get();
}
