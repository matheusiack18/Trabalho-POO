#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include "../elementos/Elemento.h"
#include "ListaSimplesmenteEncadeada.h"
#include <memory>

/**
 * @brief Adaptador de Pilha usando Lista Simplesmente Encadeada
 * 
 * Implementa uma Pilha (LIFO - Last In, First Out) como um adaptador
 * por composição utilizando ListaSimplesmenteEncadeada.
 * 
 * ESCOLHA DA ESTRUTURA:
 * - ListaSimplesmenteEncadeada é ideal para Pilha pois:
 *   • Push: inserirNoInicio() - O(1)
 *   • Pop: removerPrimeiro() - O(1)
 *   • Top: buscar primeiro elemento - O(1)
 *   • Não precisa de navegação bidirecional
 */
class PilhaEncadeada {
private:
    ListaSimplesmenteEncadeada lista;  // Composição: adaptador da lista

public:
    /**
     * @brief Construtor da pilha
     */
    PilhaEncadeada() = default;
    
    /**
     * @brief Destrutor da pilha
     */
    ~PilhaEncadeada() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    PilhaEncadeada(const PilhaEncadeada& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    PilhaEncadeada& operator=(const PilhaEncadeada& outra) = delete;
    
    /**
     * @brief Empilha um elemento (push)
     * @param elemento Ponteiro único para o elemento a ser empilhado
     * 
     * Complexidade: O(1) - inserção no início da lista
     */
    void empilhar(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Desempilha um elemento (pop)
     * @return Ponteiro único para o elemento desempilhado (nullptr se vazia)
     * 
     * Complexidade: O(1) - remoção do início da lista
     */
    std::unique_ptr<Elemento> desempilhar();
    
    /**
     * @brief Consulta o elemento do topo sem removê-lo (top)
     * @return Ponteiro para o elemento do topo (nullptr se vazia)
     * 
     * Complexidade: O(1) - acesso ao primeiro elemento
     */
    Elemento* topo() const;
    
    /**
     * @brief Verifica se a pilha está vazia
     * @return true se a pilha está vazia
     * 
     * Complexidade: O(1)
     */
    bool estaVazia() const;
    
    /**
     * @brief Retorna o número de elementos na pilha
     * @return Tamanho atual da pilha
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;
    
    /**
     * @brief Limpa todos os elementos da pilha
     * 
     * Complexidade: O(n) - remove todos os elementos
     */
    void limpar();
    
    /**
     * @brief Imprime todos os elementos da pilha (do topo para a base)
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirPilha() const;
};

#endif
