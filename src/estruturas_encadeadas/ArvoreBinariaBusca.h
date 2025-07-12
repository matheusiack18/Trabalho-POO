#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include "../elementos/Elemento.h"
#include <memory>
#include <functional>

/**
 * @brief Árvore Binária de Busca com nós privados
 * 
 * Implementa uma estrutura hierárquica onde cada nó tem no máximo
 * dois filhos, organizados pelo atributo ID dos elementos.
 * Os nós são encapsulados como classes privadas, garantindo que
 * o usuário não possa manipular diretamente a estrutura interna.
 * 
 * PROPRIEDADES DA ABB:
 * - Subárvore esquerda: todos os IDs menores que o nó atual
 * - Subárvore direita: todos os IDs maiores que o nó atual
 * - Busca eficiente: O(log n) no caso médio, O(n) no pior caso
 */
class ArvoreBinariaBusca {
private:
    /**
     * @brief Nó da árvore - CLASSE PRIVADA (Encapsulamento)
     * 
     * Esta classe é privada para garantir que o usuário não possa
     * acessar ou manipular diretamente os nós da árvore.
     */
    class No {
    public:
        std::unique_ptr<Elemento> dados;    // Elemento armazenado
        std::unique_ptr<No> esquerdo;       // Filho esquerdo
        std::unique_ptr<No> direito;        // Filho direito
        
        /**
         * @brief Construtor do nó
         * @param elemento Elemento a ser armazenado
         */
        explicit No(std::unique_ptr<Elemento> elemento) 
            : dados(std::move(elemento)), esquerdo(nullptr), direito(nullptr) {}
    };
    
    std::unique_ptr<No> raiz;    // Raiz da árvore
    int tamanho;                 // Número de elementos na árvore

    /**
     * @brief Métodos auxiliares privados para recursão
     */
    
    /**
     * @brief Insere elemento recursivamente
     * @param no Nó atual
     * @param elemento Elemento a ser inserido
     * @return Nó atualizado
     */
    std::unique_ptr<No> inserirRecursivo(std::unique_ptr<No> no, std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Busca elemento recursivamente
     * @param no Nó atual
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento (nullptr se não encontrado)
     */
    Elemento* buscarRecursivo(No* no, long id) const;
    
    /**
     * @brief Remove elemento recursivamente
     * @param no Nó atual
     * @param id ID do elemento a ser removido
     * @return Par: nó atualizado e elemento removido
     */
    std::pair<std::unique_ptr<No>, std::unique_ptr<Elemento>> removerRecursivo(std::unique_ptr<No> no, long id);
    
    /**
     * @brief Encontra o menor elemento de uma subárvore
     * @param no Nó raiz da subárvore
     * @return Ponteiro para o menor elemento
     */
    No* encontrarMinimo(No* no) const;
    
    /**
     * @brief Percurso em ordem recursivo
     * @param no Nó atual
     * @param funcao Função a ser aplicada em cada elemento
     */
    void emOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const;
    
    /**
     * @brief Percurso pré-ordem recursivo
     * @param no Nó atual
     * @param funcao Função a ser aplicada em cada elemento
     */
    void preOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const;
    
    /**
     * @brief Percurso pós-ordem recursivo
     * @param no Nó atual
     * @param funcao Função a ser aplicada em cada elemento
     */
    void posOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const;
    
    /**
     * @brief Calcula altura da árvore recursivamente
     * @param no Nó atual
     * @return Altura da subárvore
     */
    int calcularAlturaRecursivo(No* no) const;

public:
    /**
     * @brief Construtor da árvore
     */
    ArvoreBinariaBusca();
    
    /**
     * @brief Destrutor da árvore
     */
    ~ArvoreBinariaBusca() = default;
    
    /**
     * @brief Construtor de cópia (removido para simplificar)
     */
    ArvoreBinariaBusca(const ArvoreBinariaBusca& outra) = delete;
    
    /**
     * @brief Operador de atribuição (removido para simplificar)
     */
    ArvoreBinariaBusca& operator=(const ArvoreBinariaBusca& outra) = delete;
    
    /**
     * @brief Insere um elemento na árvore
     * @param elemento Ponteiro único para o elemento a ser inserido
     * 
     * Complexidade: O(log n) caso médio, O(n) pior caso
     */
    void inserir(std::unique_ptr<Elemento> elemento);
    
    /**
     * @brief Busca elemento pelo ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento (nullptr se não encontrado)
     * 
     * Complexidade: O(log n) caso médio, O(n) pior caso
     */
    Elemento* buscarPeloId(long id) const;
    
    /**
     * @brief Remove elemento pelo ID
     * @param id ID do elemento a ser removido
     * @return Ponteiro único para o elemento removido (nullptr se não encontrado)
     * 
     * Complexidade: O(log n) caso médio, O(n) pior caso
     */
    std::unique_ptr<Elemento> removerPeloId(long id);
    
    /**
     * @brief Percurso em ordem (esquerda, raiz, direita)
     * Imprime elementos em ordem crescente de ID
     * 
     * Complexidade: O(n) - visita todos os nós
     */
    void emOrdem() const;
    
    /**
     * @brief Percurso pré-ordem (raiz, esquerda, direita)
     * Útil para copiar ou serializar a árvore
     * 
     * Complexidade: O(n) - visita todos os nós
     */
    void preOrdem() const;
    
    /**
     * @brief Percurso pós-ordem (esquerda, direita, raiz)
     * Útil para liberar memória ou calcular propriedades
     * 
     * Complexidade: O(n) - visita todos os nós
     */
    void posOrdem() const;
    
    /**
     * @brief Verifica se a árvore está vazia
     * @return true se a árvore está vazia
     * 
     * Complexidade: O(1)
     */
    bool estaVazia() const;
    
    /**
     * @brief Retorna o número de elementos na árvore
     * @return Tamanho atual da árvore
     * 
     * Complexidade: O(1)
     */
    int getTamanho() const;
    
    /**
     * @brief Calcula a altura da árvore
     * @return Altura da árvore (0 se vazia)
     * 
     * Complexidade: O(n) - percorre todos os nós
     */
    int calcularAltura() const;
    
    /**
     * @brief Limpa todos os elementos da árvore
     * 
     * Complexidade: O(n) - libera memória de todos os nós
     */
    void limpar();
    
    /**
     * @brief Imprime a estrutura da árvore de forma hierárquica
     * 
     * Complexidade: O(n) - visita todos os nós
     */
    void imprimirArvore() const;
    
    /**
     * @brief Encontra o elemento com menor ID
     * @return Ponteiro para o menor elemento (nullptr se vazia)
     * 
     * Complexidade: O(log n) caso médio, O(n) pior caso
     */
    Elemento* encontrarMinimo() const;
    
    /**
     * @brief Encontra o elemento com maior ID
     * @return Ponteiro para o maior elemento (nullptr se vazia)
     * 
     * Complexidade: O(log n) caso médio, O(n) pior caso
     */
    Elemento* encontrarMaximo() const;
};

#endif
