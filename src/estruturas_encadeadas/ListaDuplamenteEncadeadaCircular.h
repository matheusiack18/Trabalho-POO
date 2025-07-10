#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Lista Duplamente Encadeada Circular com nós privados
 * 
 * Implementa uma estrutura de dados linear onde cada elemento
 * tem ponteiros para o próximo e o anterior, formando um ciclo.
 * A cauda aponta para a cabeça e a cabeça aponta para a cauda.
 * Os nós são encapsulados como classes privadas.
 */
class ListaDuplamenteEncadeadaCircular {
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
        No* proximo;                        // Ponteiro para o próximo nó (raw pointer para ciclo)
        No* anterior;                       // Ponteiro para o nó anterior (raw pointer para ciclo)
        
        /**
         * @brief Construtor do nó
         * @param elemento Elemento a ser armazenado
         */
        explicit No(std::unique_ptr<Elemento> elemento) 
            : dados(std::move(elemento)), proximo(nullptr), anterior(nullptr) {}
    };
    
    std::unique_ptr<No> cabeca;    // Primeiro nó da lista (único unique_ptr)
    No* cauda;                     // Último nó da lista (raw pointer para evitar ciclos)
    int tamanho;                   // Número de elementos na lista

    /**
     * @brief Remove um nó específico da lista circular
     * @param no Ponteiro para o nó a ser removido
     * @return Ponteiro único para o elemento removido
     * 
     * Método auxiliar privado para facilitar remoções
     */
    std::unique_ptr<Elemento> removerNo(No* no);

public:
    /**
     * @brief Construtor da lista
     */
    ListaDuplamenteEncadeadaCircular();
    
    /**
     * @brief Destrutor da lista
     */
    ~ListaDuplamenteEncadeadaCircular();
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    ListaDuplamenteEncadeadaCircular(const ListaDuplamenteEncadeadaCircular& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    ListaDuplamenteEncadeadaCircular& operator=(const ListaDuplamenteEncadeadaCircular& outra) = delete;
    
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
     * Complexidade: O(1) - inserção direta no final
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
     * Complexidade: O(1) - remoção direta do último elemento
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
     * @brief Imprime a lista de forma circular (demonstra a circularidade)
     * @param voltas Número de voltas completas para imprimir
     * 
     * Complexidade: O(n * voltas) - percorre elementos múltiplas vezes
     */
    void imprimirListaCircular(int voltas = 2) const;
    
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
     * @brief Rotaciona a lista para a direita
     * @param posicoes Número de posições para rotacionar
     * 
     * Complexidade: O(n) - pode precisar percorrer a lista
     */
    void rotacionarDireita(int posicoes);
    
    /**
     * @brief Rotaciona a lista para a esquerda
     * @param posicoes Número de posições para rotacionar
     * 
     * Complexidade: O(n) - pode precisar percorrer a lista
     */
    void rotacionarEsquerda(int posicoes);
    
    /**
     * @brief Verifica se a lista está corretamente circular
     * @return true se a circularidade está íntegra
     * 
     * Método para debug e validação da integridade da estrutura
     */
    bool verificarIntegridade() const;
};

#endif
