#ifndef LISTA_SIMPLESMENTE_ENCADEADA_H
#define LISTA_SIMPLESMENTE_ENCADEADA_H

#include "../elementos/Elemento.h"
#include <memory>

/**
 * @brief Lista Simplesmente Encadeada com nós privados
 * 
 * Implementa uma estrutura de dados linear onde cada elemento
 * aponta para o próximo elemento da lista. Os nós são encapsulados
 * como classes privadas, garantindo que o usuário não possa
 * manipular diretamente a estrutura interna.
 */
class ListaSimplesmenteEncadeada {
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
        
        /**
         * @brief Construtor do nó
         * @param elemento Elemento a ser armazenado
         */
        explicit No(std::unique_ptr<Elemento> elemento) 
            : dados(std::move(elemento)), proximo(nullptr) {}
    };
    
    std::unique_ptr<No> cabeca;    // Primeiro nó da lista
    No* cauda;                     // Último nó da lista (raw pointer para evitar ciclos)
    int tamanho;                   // Número de elementos na lista

public:
    /**
     * @brief Construtor da lista
     */
    ListaSimplesmenteEncadeada();
    
    /**
     * @brief Destrutor da lista
     */
    ~ListaSimplesmenteEncadeada() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    ListaSimplesmenteEncadeada(const ListaSimplesmenteEncadeada& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    ListaSimplesmenteEncadeada& operator=(const ListaSimplesmenteEncadeada& outra) = delete;
    
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
     * Complexidade: O(n) - precisa percorrer até o penúltimo elemento
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
     * @brief Obtém elemento por posição (para fins de teste)
     * @param posicao Posição do elemento (0-based)
     * @return Ponteiro para o elemento (nullptr se posição inválida)
     * 
     * Complexidade: O(n) - percorre até a posição desejada
     */
    Elemento* obterElementoPorPosicao(int posicao) const;
    
    /**
     * @brief Conta quantos elementos satisfazem uma condição (método auxiliar)
     * @param condicao Função que retorna true para elementos que satisfazem a condição
     * @return Número de elementos que satisfazem a condição
     * 
     * Complexidade: O(n) - percorre todos os elementos
     */
    template<typename Condicao>
    int contarElementos(Condicao condicao) const;
};

#endif
