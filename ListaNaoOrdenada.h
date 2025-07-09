#ifndef LISTA_NAO_ORDENADA_H
#define LISTA_NAO_ORDENADA_H

#include "Elemento.h"
#include <memory>

/**
 * @brief Lista Não Ordenada com alocação sequencial
 * 
 * Implementa uma estrutura de dados linear onde os elementos são
 * armazenados em um array e mantidos na ordem de inserção.
 * Utiliza ponteiros inteligentes para gerenciar elementos da hierarquia.
 */
class ListaNaoOrdenada {
private:
    std::unique_ptr<Elemento>* elementos;  // Array de ponteiros para elementos
    int capacidade;                        // Capacidade máxima da lista
    int tamanho;                          // Número atual de elementos

    /**
     * @brief Redimensiona o array quando necessário
     * 
     * Complexidade: O(n) - precisa copiar todos os elementos
     */
    void redimensionar();

public:
    /**
     * @brief Construtor padrão
     * @param capacidadeInicial Capacidade inicial da lista (padrão: 10)
     */
    explicit ListaNaoOrdenada(int capacidadeInicial = 10);

    /**
     * @brief Destrutor
     */
    ~ListaNaoOrdenada();

    /**
     * @brief Construtor de cópia
     */
    ListaNaoOrdenada(const ListaNaoOrdenada& outra);

    /**
     * @brief Operador de atribuição
     */
    ListaNaoOrdenada& operator=(const ListaNaoOrdenada& outra);

    /**
     * @brief Insere elemento no início da lista
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(n) - precisa deslocar todos os elementos uma posição à direita
     */
    void InserirNoInicio(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Insere elemento no final da lista
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(1) amortizado - inserção direta na última posição
     *               O(n) no pior caso quando precisa redimensionar
     */
    void InserirNoFinal(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Remove o primeiro elemento da lista
     * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
     * 
     * Complexidade: O(n) - precisa deslocar todos os elementos uma posição à esquerda
     */
    std::unique_ptr<Elemento> RemoverPrimeiro();

    /**
     * @brief Remove o último elemento da lista
     * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - remoção direta da última posição
     */
    std::unique_ptr<Elemento> RemoverUltimo();

    /**
     * @brief Remove elemento com ID específico
     * @param id ID do elemento a ser removido
     * @return Ponteiro único para o elemento removido (nullptr se não encontrado)
     * 
     * Complexidade: O(n) - busca linear + deslocamento dos elementos posteriores
     */
    std::unique_ptr<Elemento> RemoverPeloId(long id);

    /**
     * @brief Busca elemento pelo ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento (nullptr se não encontrado)
     * 
     * Complexidade: O(n) - busca linear sequencial
     */
    Elemento* BuscarPeloId(long id) const;

    /**
     * @brief Altera elemento com ID específico
     * @param id ID do elemento a ser alterado
     * @param novoElemento Novo elemento para substituir o existente
     * @return true se a alteração foi bem-sucedida, false se ID não encontrado
     * 
     * Complexidade: O(n) - busca linear para encontrar o elemento
     */
    bool AlterarPeloId(long id, std::unique_ptr<Elemento> novoElemento);

    /**
     * @brief Retorna o número de elementos na lista
     * @return Tamanho atual da lista
     * 
     * Complexidade: O(1) - acesso direto ao atributo
     */
    int getTamanho() const;

    /**
     * @brief Verifica se a lista está vazia
     * @return true se a lista está vazia
     * 
     * Complexidade: O(1) - verificação simples
     */
    bool estaVazia() const;

    /**
     * @brief Retorna a capacidade atual da lista
     * @return Capacidade máxima atual
     * 
     * Complexidade: O(1) - acesso direto ao atributo
     */
    int getCapacidade() const;

    /**
     * @brief Imprime todos os elementos da lista
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirLista() const;

    /**
     * @brief Limpa todos os elementos da lista
     * 
     * Complexidade: O(n) - libera memória de todos os elementos
     */
    void limpar();

    /**
     * @brief Obtém elemento por índice (para acesso direto)
     * @param indice Índice do elemento (0-based)
     * @return Ponteiro para o elemento (nullptr se índice inválido)
     * 
     * Complexidade: O(1) - acesso direto por índice
     */
    Elemento* obterElementoPorIndice(int indice) const;
};

#endif
