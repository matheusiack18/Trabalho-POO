#ifndef DEQUE_H
#define DEQUE_H

#include "../elementos/Elemento.h"
#include "ListaDuplamenteEncadeada.h"
#include <memory>

/**
 * @brief Adaptador de Deque usando Lista Duplamente Encadeada
 * 
 * Implementa um Deque (Double Ended Queue) como um adaptador
 * por composição utilizando ListaDuplamenteEncadeada.
 * 
 * ESCOLHA DA ESTRUTURA:
 * - ListaDuplamenteEncadeada é IDEAL para Deque pois:
 *   • Push Front: inserirNoInicio() - O(1)
 *   • Push Back: inserirNoFim() - O(1)
 *   • Pop Front: removerPrimeiro() - O(1)
 *   • Pop Back: removerUltimo() - O(1) - vantagem da lista dupla!
 *   • Navegação bidirecional eficiente
 */
class Deque {
private:
    ListaDuplamenteEncadeada lista;  // Composição: adaptador da lista dupla

public:
    /**
     * @brief Construtor do deque
     */
    Deque() = default;
    
    /**
     * @brief Destrutor do deque
     */
    ~Deque() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    Deque(const Deque& outro) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    Deque& operator=(const Deque& outro) = delete;
    
    /**
     * @brief Insere um elemento no início do deque (push_front)
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(1) - inserção no início da lista dupla
     */
    void inserirInicio(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Insere um elemento no final do deque (push_back)
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(1) - inserção no final da lista dupla
     */
    void inserirFim(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Remove um elemento do início do deque (pop_front)
     * @return Ponteiro único para o elemento removido (nullptr se vazio)
     * 
     * Complexidade: O(1) - remoção do início da lista dupla
     */
    std::unique_ptr<Elemento> removerInicio();
    
    /**
     * @brief Remove um elemento do final do deque (pop_back)
     * @return Ponteiro único para o elemento removido (nullptr se vazio)
     * 
     * Complexidade: O(1) - remoção do final da lista dupla
     */
    std::unique_ptr<Elemento> removerFim();
    
    /**
     * @brief Consulta o elemento do início sem removê-lo (front)
     * @return Ponteiro para o elemento do início (nullptr se vazio)
     * 
     * Complexidade: O(1) - acesso ao primeiro elemento
     */
    Elemento* inicio() const;
    
    /**
     * @brief Consulta o elemento do final sem removê-lo (back)
     * @return Ponteiro para o elemento do final (nullptr se vazio)
     * 
     * Complexidade: O(1) - acesso ao último elemento
     */
    Elemento* fim() const;
    
    /**
     * @brief Verifica se o deque está vazio
     * @return true se o deque está vazio
     * 
     * Complexidade: O(1)
     */
    bool estaVazio() const;
    
    /**
     * @brief Retorna o número de elementos no deque
     * @return Tamanho atual do deque
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;
    
    /**
     * @brief Limpa todos os elementos do deque
     * 
     * Complexidade: O(n) - remove todos os elementos
     */
    void limpar();
    
    /**
     * @brief Imprime todos os elementos do deque (do início ao fim)
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirDeque() const;
    
    /**
     * @brief Imprime todos os elementos do deque em ordem reversa (do fim ao início)
     * 
     * Complexidade: O(n) - percorre todos os elementos em ordem reversa
     * Vantagem específica da lista duplamente encadeada!
     */
    void imprimirDequeReverso() const;
};

#endif
