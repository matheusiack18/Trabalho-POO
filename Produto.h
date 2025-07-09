#ifndef PRODUTO_H
#define PRODUTO_H

#include "Elemento.h"
#include <string>

/**
 * @brief Classe que representa um produto, derivada de Elemento
 * 
 * Terceira implementação da herança da classe abstrata Elemento,
 * demonstrando a flexibilidade da hierarquia para diferentes
 * tipos de entidades do mundo real.
 */
class Produto : public Elemento {
private:
    std::string nome;
    std::string categoria;
    std::string marca;
    double preco;
    int quantidadeEstoque;

public:
    /**
     * @brief Construtor da classe Produto
     * @param id Código único do produto (código de barras)
     * @param nome Nome do produto
     * @param categoria Categoria do produto
     * @param marca Marca do produto
     * @param preco Preço unitário do produto
     * @param quantidadeEstoque Quantidade em estoque
     */
    Produto(long id, const std::string& nome, const std::string& categoria,
            const std::string& marca, double preco, int quantidadeEstoque);

    /**
     * @brief Obtém o nome do produto
     * @return Nome do produto
     */
    std::string getNome() const;

    /**
     * @brief Obtém a categoria do produto
     * @return Categoria do produto
     */
    std::string getCategoria() const;

    /**
     * @brief Obtém a marca do produto
     * @return Marca do produto
     */
    std::string getMarca() const;

    /**
     * @brief Obtém o preço do produto
     * @return Preço unitário do produto
     */
    double getPreco() const;

    /**
     * @brief Obtém a quantidade em estoque
     * @return Quantidade disponível em estoque
     */
    int getQuantidadeEstoque() const;

    /**
     * @brief Define o preço do produto
     * @param novoPreco Novo preço a ser atribuído
     */
    void setPreco(double novoPreco);

    /**
     * @brief Define a quantidade em estoque
     * @param novaQuantidade Nova quantidade em estoque
     */
    void setQuantidadeEstoque(int novaQuantidade);

    /**
     * @brief Adiciona quantidade ao estoque
     * @param quantidade Quantidade a ser adicionada
     */
    void adicionarEstoque(int quantidade);

    /**
     * @brief Remove quantidade do estoque
     * @param quantidade Quantidade a ser removida
     * @return true se a operação foi bem-sucedida, false se não há estoque suficiente
     */
    bool removerEstoque(int quantidade);

    /**
     * @brief Verifica se o produto está disponível em estoque
     * @return true se há estoque disponível
     */
    bool estaDisponivel() const;

    /**
     * @brief Calcula o valor total do estoque
     * @return Valor total (preço * quantidade)
     */
    double calcularValorTotalEstoque() const;

    /**
     * @brief Implementação do método virtual puro da classe base
     * 
     * Imprime todas as informações do produto de forma formatada.
     * Demonstra polimorfismo com implementação específica para produtos.
     */
    void imprimirInfo() const override;
};

#endif
