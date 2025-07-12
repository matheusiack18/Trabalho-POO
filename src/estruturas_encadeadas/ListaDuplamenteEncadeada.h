#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Lista Duplamente Encadeada com nós privados
 * 
 * Implementa uma estrutura de dados linear onde cada elemento
 * tem ponteiros para o próximo e o anterior. Os nós são encapsulados
 * como classes privadas, garantindo que o usuário não possa
 * manipular diretamente a estrutura interna.
 */
class ListaDuplamenteEncadeada {
private:
    /**
     * @brief Nó da lista - CLASSE PRIVADA (Encapsulamento)
     * 
     * Esta classe é privada para garantir que o usuário não possa
     * acessar ou manipular diretamente os nós da lista.
     */
    class No {
    public:
        std::unique_ptr<Elemento> dados;    // Elemento armazenado
        std::unique_ptr<No> proximo;        // Ponteiro para o próximo nó
        No* anterior;                       // Ponteiro para o nó anterior (raw pointer para evitar ciclos)
        
        /**
         * @brief Construtor do nó
         * @param elemento Elemento a ser armazenado
         */
        explicit No(std::unique_ptr<Elemento> elemento) 
            : dados(std::move(elemento)), proximo(nullptr), anterior(nullptr) {}
    };
    
    std::unique_ptr<No> cabeca;    // Primeiro nó da lista
    No* cauda;                     // Último nó da lista (raw pointer para evitar ciclos)
    int tamanho;                   // Número de elementos na lista

public:
    /**
     * @brief Construtor da lista
     */
    ListaDuplamenteEncadeada();
    
    /**
     * @brief Destrutor da lista
     */
    ~ListaDuplamenteEncadeada() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    ListaDuplamenteEncadeada(const ListaDuplamenteEncadeada& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    ListaDuplamenteEncadeada& operator=(const ListaDuplamenteEncadeada& outra) = delete;
    
    /**
     * @brief Insere elemento no início da lista
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(1) - inserção direta no início
     */
    void inserirNoInicio(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Insere elemento no final da lista
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(1) - inserção direta no final (com ponteiro cauda)
     */
    void inserirNoFim(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Remove elemento com ID específico
     * @param id ID do elemento a ser removido
     * @return Ponteiro único para o elemento removido (nullptr se não encontrado)
     * 
     * Complexidade: O(n) - busca linear para encontrar o elemento
     */
    std::unique_ptr<Elemento> removerPeloId(long id);
    
    /**
     * @brief Busca elemento pelo ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento (nullptr se não encontrado)
     * 
     * Complexidade: O(n) - busca linear sequencial
     */
    Elemento* buscarPeloId(long id) const;
    
    /**
     * @brief Altera elemento com ID específico
     * @param id ID do elemento a ser alterado
     * @param novoElemento Novo elemento para substituir o existente
     * @return true se a alteração foi bem-sucedida, false se ID não encontrado
     * 
     * Complexidade: O(n) - busca linear para encontrar o elemento
     */
    bool alterarPeloId(long id, std::unique_ptr<Elemento> novoElemento);
    
    /**
     * @brief Obtém o primeiro elemento da lista sem removê-lo
     * @return Ponteiro para o primeiro elemento (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - acesso direto ao primeiro elemento
     */
    Elemento* getPrimeiro() const;
    
    /**
     * @brief Obtém o último elemento da lista sem removê-lo
     * @return Ponteiro para o último elemento (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - acesso direto ao último elemento (vantagem da lista dupla)
     */
    Elemento* getUltimo() const;
    
    /**
     * @brief Remove o primeiro elemento da lista
     * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - remoção direta do primeiro elemento
     */
    std::unique_ptr<Elemento> removerPrimeiro();
    
    /**
     * @brief Remove o último elemento da lista
     * @return Ponteiro único para o elemento removido (nullptr se lista vazia)
     * 
     * Complexidade: O(1) - remoção direta do último elemento (vantagem da lista dupla)
     */
    std::unique_ptr<Elemento> removerUltimo();
    
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
     * @brief Imprime todos os elementos da lista (do início ao fim)
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirLista() const;
    
    /**
     * @brief Imprime todos os elementos da lista (do fim ao início)
     * Demonstra a capacidade de percorrer na direção reversa
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    void imprimirListaReversa() const;
    
    /**
     * @brief Limpa todos os elementos da lista
     * 
     * Complexidade: O(n) - libera memória de todos os elementos
     */
    void limpar();
    
    /**
     * @brief Obtém elemento por posição (para fins de teste)
     * @param posicao Posição do elemento (0-based)
     * @return Ponteiro para o elemento (nullptr se posição inválida)
     * 
     * Complexidade: O(n) - percorre até a posição desejada
     */
    Elemento* obterElementoPorPosicao(int posicao) const;
    
    /**
     * @brief Insere elemento em posição específica
     * @param posicao Posição onde inserir (0-based)
     * @param elemento Elemento a ser inserido
     * @return true se a inserção foi bem-sucedida
     * 
     * Complexidade: O(n) - percorre até a posição desejada
     */
    bool inserirNaPosicao(int posicao, std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Remove elemento de posição específica
     * @param posicao Posição do elemento a ser removido (0-based)
     * @return Ponteiro único para o elemento removido (nullptr se posição inválida)
     * 
     * Complexidade: O(n) - percorre até a posição desejada
     */
    std::unique_ptr<Elemento> removerDaPosicao(int posicao);
};

#endif
