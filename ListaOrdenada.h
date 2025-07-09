#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

#include "Elemento.h"
#include <memory>

/**
 * @brief Lista Ordenada com alocação sequencial
 * 
 * Implementa uma estrutura de dados linear onde os elementos são
 * mantidos ordenados por ID em ordem crescente. Utiliza busca binária
 * para operações de busca com complexidade O(log n).
 */
class ListaOrdenada {
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

    /**
     * @brief Encontra a posição correta para inserir um elemento
     * @param id ID do elemento a ser inserido
     * @return Índice onde o elemento deve ser inserido para manter ordenação
     * 
     * Complexidade: O(log n) - busca binária para encontrar posição
     */
    int encontrarPosicaoInsercao(long id) const;

    /**
     * @brief Busca binária por ID
     * @param id ID procurado
     * @return Índice do elemento (ou -1 se não encontrado)
     * 
     * Complexidade: O(log n) - busca binária clássica
     */
    int buscaBinaria(long id) const;

public:
    /**
     * @brief Construtor padrão
     * @param capacidadeInicial Capacidade inicial da lista (padrão: 10)
     */
    explicit ListaOrdenada(int capacidadeInicial = 10);

    /**
     * @brief Destrutor
     */
    ~ListaOrdenada();

    /**
     * @brief Construtor de cópia
     */
    ListaOrdenada(const ListaOrdenada& outra);

    /**
     * @brief Operador de atribuição
     */
    ListaOrdenada& operator=(const ListaOrdenada& outra);

    /**
     * @brief Insere elemento no início da lista (mantém ordenação)
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(n) - busca binária O(log n) + inserção ordenada O(n)
     * Nota: Insere na posição correta, não necessariamente no início
     */
    void InserirNoInicio(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Insere elemento no final da lista (mantém ordenação)
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(n) - busca binária O(log n) + inserção ordenada O(n)
     * Nota: Insere na posição correta, não necessariamente no final
     */
    void InserirNoFinal(std::unique_ptr<Elemento> elemento);

    /**
     * @brief Insere elemento mantendo a ordenação por ID
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(n) - busca binária O(log n) + deslocamento O(n)
     */
    void InserirOrdenado(std::unique_ptr<Elemento> elemento);

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
     * Complexidade: O(n) - busca binária O(log n) + deslocamento O(n)
     */
    std::unique_ptr<Elemento> RemoverPeloId(long id);

    /**
     * @brief Busca elemento pelo ID usando busca binária
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento (nullptr se não encontrado)
     * 
     * Complexidade: O(log n) - busca binária otimizada
     */
    Elemento* BuscarPeloId(long id) const;

    /**
     * @brief Altera elemento com ID específico
     * @param id ID do elemento a ser alterado
     * @param novoElemento Novo elemento para substituir o existente
     * @return true se a alteração foi bem-sucedida, false se ID não encontrado
     * 
     * Complexidade: O(log n) se o novo elemento tem o mesmo ID
     *               O(n) se precisa remover e inserir em nova posição
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
     * @brief Imprime todos os elementos da lista (já ordenados)
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

    /**
     * @brief Verifica se a lista está ordenada (método de teste)
     * @return true se a lista está corretamente ordenada por ID
     * 
     * Complexidade: O(n) - verifica ordenação sequencial
     */
    bool verificarOrdenacao() const;

    /**
     * @brief Busca o menor ID na lista
     * @return Ponteiro para o elemento com menor ID (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - primeiro elemento em lista ordenada
     */
    Elemento* obterMenorElemento() const;

    /**
     * @brief Busca o maior ID na lista
     * @return Ponteiro para o elemento com maior ID (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - último elemento em lista ordenada
     */
    Elemento* obterMaiorElemento() const;
};

#endif // LISTA_ORDENADA_H
