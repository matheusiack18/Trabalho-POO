#ifndef FILA_H
#define FILA_H

#include "ListaNaoOrdenada.h"
#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Fila implementada por composição usando ListaNaoOrdenada (versão ineficiente)
 * 
 * A fila segue o princípio FIFO (First In, First Out).
 * Utiliza ListaNaoOrdenada como estrutura interna para armazenar os elementos.
 * 
 * NOTA: Esta é a versão "ineficiente" da fila, onde:
 * - enfileirar(): insere no final da lista - O(1)
 * - desenfileirar(): remove do início da lista - O(n) devido ao deslocamento
 * 
 * Operações:
 * - enfileirar(): adiciona elemento no final da fila
 * - desenfileirar(): remove e retorna elemento do início da fila
 * - consultarFrente(): consulta elemento da frente sem removê-lo
 * - filaVazia(): verifica se a fila está vazia
 * - filaCheia(): verifica se a fila está cheia (dependente da capacidade)
 */
class Fila {
private:
    ListaNaoOrdenada lista;  // Lista usada como estrutura interna
    int capacidadeMaxima;    // Capacidade máxima da fila

public:
    /**
     * @brief Construtor da fila
     * @param capacidade Capacidade máxima da fila (padrão: 100)
     */
    explicit Fila(int capacidade = 100);

    /**
     * @brief Destrutor da fila
     */
    ~Fila() = default;

    /**
     * @brief Enfileira um elemento no final da fila
     * @param elemento Ponteiro único para o elemento a ser enfileirado
     * @return true se a operação foi bem-sucedida, false se a fila está cheia
     * 
     * Complexidade: O(1) - inserção no final da lista
     */
    bool enfileirar(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Desenfileira o elemento do início da fila
     * @return Ponteiro único para o elemento removido (nullptr se fila vazia)
     * 
     * Complexidade: O(n) - remoção do início da lista (ineficiente)
     */
    std::unique_ptr<Elemento> desenfileirar();

    /**
     * @brief Consulta o elemento da frente da fila sem removê-lo
     * @return Ponteiro para o elemento da frente (nullptr se fila vazia)
     * 
     * Complexidade: O(1) - acesso direto ao primeiro elemento
     */
    Elemento* consultarFrente() const;

    /**
     * @brief Verifica se a fila está vazia
     * @return true se a fila está vazia
     * 
     * Complexidade: O(1)
     */
    bool filaVazia() const;

    /**
     * @brief Verifica se a fila está cheia
     * @return true se a fila atingiu sua capacidade máxima
     * 
     * Complexidade: O(1)
     */
    bool filaCheia() const;

    /**
     * @brief Retorna o tamanho atual da fila
     * @return Número de elementos na fila
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;

    /**
     * @brief Retorna a capacidade máxima da fila
     * @return Capacidade máxima
     * 
     * Complexidade: O(1)
     */
    int getCapacidadeMaxima() const;

    /**
     * @brief Imprime todos os elementos da fila (da frente para o final)
     * 
     * Complexidade: O(n)
     */
    void imprimirFila() const;

    /**
     * @brief Limpa todos os elementos da fila
     * 
     * Complexidade: O(n)
     */
    void limpar();
};

#endif
