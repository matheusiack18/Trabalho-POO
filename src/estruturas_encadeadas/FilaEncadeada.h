#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include "../elementos/Elemento.h"
#include "ListaSimplesmenteEncadeada.h"
#include <memory>

/**
 * @brief Adaptador de Fila usando Lista Simplesmente Encadeada
 * 
 * Implementa uma Fila (FIFO - First In, First Out) como um adaptador
 * por composição utilizando ListaSimplesmenteEncadeada.
 * 
 * ESCOLHA DA ESTRUTURA:
 * - ListaSimplesmenteEncadeada é adequada para Fila pois:
 *   • Enqueue: inserirNoFim() - O(1) - inserção no final
 *   • Dequeue: removerPrimeiro() - O(1) - remoção do início
 *   • Front: getPrimeiro() - O(1) - consulta do início
 *   • Mantém ordem FIFO naturalmente
 */
class FilaEncadeada {
private:
    ListaSimplesmenteEncadeada lista;  // Composição: adaptador da lista

public:
    /**
     * @brief Construtor da fila
     */
    FilaEncadeada() = default;
    
    /**
     * @brief Destrutor da fila
     */
    ~FilaEncadeada() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    FilaEncadeada(const FilaEncadeada& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    FilaEncadeada& operator=(const FilaEncadeada& outra) = delete;
    
    /**
     * @brief Enfileira um elemento (enqueue)
     * @param elemento Ponteiro único para o elemento a ser enfileirado
     * 
     * Complexidade: O(1) - inserção no final da lista
     */
    void enfileirar(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Desenfileira um elemento (dequeue)
     * @return Ponteiro único para o elemento desenfileirado (nullptr se vazia)
     * 
     * Complexidade: O(1) - remoção do início da lista
     */
    std::unique_ptr<Elemento> desenfileirar();
    
    /**
     * @brief Consulta o elemento da frente sem removê-lo (front)
     * @return Ponteiro para o elemento da frente (nullptr se vazia)
     * 
     * Complexidade: O(1) - acesso ao primeiro elemento
     */
    Elemento* frente() const;
    
    /**
     * @brief Verifica se a fila está vazia
     * @return true se a fila está vazia
     * 
     * Complexidade: O(1)
     */
    bool estaVazia() const;
    
    /**
     * @brief Retorna o número de elementos na fila
     * @return Tamanho atual da fila
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;
    
    /**
     * @brief Limpa todos os elementos da fila
     * 
     * Complexidade: O(n) - remove todos os elementos
     */
    void limpar();
    
    /**
     * @brief Imprime todos os elementos da fila (da frente para trás)
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirFila() const;
};

#endif
