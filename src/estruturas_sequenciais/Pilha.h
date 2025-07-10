#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"
#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Pilha implementada por composição usando ListaNaoOrdenada
 * 
 * A pilha segue o princípio LIFO (Last In, First Out).
 * Utiliza ListaNaoOrdenada como estrutura interna para armazenar os elementos.
 * 
 * Operações:
 * - empilhar(): adiciona elemento no topo da pilha
 * - desempilhar(): remove e retorna elemento do topo da pilha
 * - consultarTopo(): consulta elemento do topo sem removê-lo
 * - pilhaVazia(): verifica se a pilha está vazia
 * - pilhaCheia(): verifica se a pilha está cheia (dependente da capacidade)
 */
class Pilha {
private:
    ListaNaoOrdenada lista;  // Lista usada como estrutura interna
    int capacidadeMaxima;    // Capacidade máxima da pilha

public:
    /**
     * @brief Construtor da pilha
     * @param capacidade Capacidade máxima da pilha (padrão: 100)
     */
    explicit Pilha(int capacidade = 100);

    /**
     * @brief Destrutor da pilha
     */
    ~Pilha() = default;

    /**
     * @brief Empilha um elemento no topo da pilha
     * @param elemento Ponteiro único para o elemento a ser empilhado
     * @return true se a operação foi bem-sucedida, false se a pilha está cheia
     * 
     * Complexidade: O(1) - inserção no final da lista
     */
    bool empilhar(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Desempilha o elemento do topo da pilha
     * @return Ponteiro único para o elemento removido (nullptr se pilha vazia)
     * 
     * Complexidade: O(1) - remoção do final da lista
     */
    std::unique_ptr<Elemento> desempilhar();

    /**
     * @brief Consulta o elemento do topo da pilha sem removê-lo
     * @return Ponteiro para o elemento do topo (nullptr se pilha vazia)
     * 
     * Complexidade: O(1) - acesso direto ao último elemento
     */
    Elemento* consultarTopo() const;

    /**
     * @brief Verifica se a pilha está vazia
     * @return true se a pilha está vazia
     * 
     * Complexidade: O(1)
     */
    bool pilhaVazia() const;

    /**
     * @brief Verifica se a pilha está cheia
     * @return true se a pilha atingiu sua capacidade máxima
     * 
     * Complexidade: O(1)
     */
    bool pilhaCheia() const;

    /**
     * @brief Retorna o tamanho atual da pilha
     * @return Número de elementos na pilha
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;

    /**
     * @brief Retorna a capacidade máxima da pilha
     * @return Capacidade máxima
     * 
     * Complexidade: O(1)
     */
    int getCapacidadeMaxima() const;

    /**
     * @brief Imprime todos os elementos da pilha (do topo para a base)
     * 
     * Complexidade: O(n)
     */
    void imprimirPilha() const;

    /**
     * @brief Limpa todos os elementos da pilha
     * 
     * Complexidade: O(n)
     */
    void limpar();
};

#endif
