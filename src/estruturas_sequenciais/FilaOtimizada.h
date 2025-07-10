#ifndef FILA_OTIMIZADA_H
#define FILA_OTIMIZADA_H

#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Fila Otimizada implementada com buffer circular
 * 
 * A fila segue o princípio FIFO (First In, First Out).
 * Utiliza um array circular para armazenar os elementos de forma eficiente.
 * 
 * Esta é a versão "otimizada" da fila, onde:
 * - enfileirar(): insere no final da fila - O(1)
 * - desenfileirar(): remove do início da fila - O(1)
 * 
 * O buffer circular evita o deslocamento de elementos, tornando
 * ambas as operações constantes no tempo.
 * 
 * Operações:
 * - enfileirar(): adiciona elemento no final da fila
 * - desenfileirar(): remove e retorna elemento do início da fila
 * - consultarFrente(): consulta elemento da frente sem removê-lo
 * - filaVazia(): verifica se a fila está vazia
 * - filaCheia(): verifica se a fila está cheia
 */
class FilaOtimizada {
private:
    std::unique_ptr<Elemento>* buffer;  // Array circular de ponteiros para elementos
    int capacidade;                     // Capacidade máxima da fila
    int inicio;                         // Índice do primeiro elemento
    int fim;                           // Índice da próxima posição livre
    int tamanho;                       // Número atual de elementos

    /**
     * @brief Calcula o próximo índice no buffer circular
     * @param indice Índice atual
     * @return Próximo índice (com wrap-around)
     */
    int proximoIndice(int indice) const;

public:
    /**
     * @brief Construtor da fila otimizada
     * @param capacidade Capacidade máxima da fila (padrão: 100)
     */
    explicit FilaOtimizada(int capacidade = 100);

    /**
     * @brief Destrutor da fila otimizada
     */
    ~FilaOtimizada();

    /**
     * @brief Construtor de cópia
     */
    FilaOtimizada(const FilaOtimizada& outra);

    /**
     * @brief Operador de atribuição
     */
    FilaOtimizada& operator=(const FilaOtimizada& outra);

    /**
     * @brief Enfileira um elemento no final da fila
     * @param elemento Ponteiro único para o elemento a ser enfileirado
     * @return true se a operação foi bem-sucedida, false se a fila está cheia
     * 
     * Complexidade: O(1) - inserção no buffer circular
     */
    bool enfileirar(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Desenfileira o elemento do início da fila
     * @return Ponteiro único para o elemento removido (nullptr se fila vazia)
     * 
     * Complexidade: O(1) - remoção no buffer circular
     */
    std::unique_ptr<Elemento> desenfileirar();

    /**
     * @brief Consulta o elemento da frente da fila sem removê-lo
     * @return Ponteiro para o elemento da frente (nullptr se fila vazia)
     * 
     * Complexidade: O(1) - acesso direto
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
    int getCapacidade() const;

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
