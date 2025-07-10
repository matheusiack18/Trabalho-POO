#include "Produto.h"
#include "../../ConfigLocale.h"
#include <iostream>
#include <iomanip>
#include <locale.h>

/**
 * @brief Construtor da classe Produto
 * @param id Código único do produto (código de barras)
 * @param nome Nome do produto
 * @param categoria Categoria do produto
 * @param marca Marca do produto
 * @param preco Preço unitário do produto
 * @param quantidadeEstoque Quantidade em estoque
 */
Produto::Produto(long id, const std::string& nome, const std::string& categoria,
                 const std::string& marca, double preco, int quantidadeEstoque)
    : Elemento(id), nome(nome), categoria(categoria), marca(marca), 
      preco(preco), quantidadeEstoque(quantidadeEstoque) {
    // Chama o construtor da classe base e inicializa atributos específicos
}

/**
 * @brief Obtém o nome do produto
 * @return Nome do produto
 */
std::string Produto::getNome() const {
    return nome;
}

/**
 * @brief Obtém a categoria do produto
 * @return Categoria do produto
 */
std::string Produto::getCategoria() const {
    return categoria;
}

/**
 * @brief Obtém a marca do produto
 * @return Marca do produto
 */
std::string Produto::getMarca() const {
    return marca;
}

/**
 * @brief Obtém o preço do produto
 * @return Preço unitário do produto
 */
double Produto::getPreco() const {
    return preco;
}

/**
 * @brief Obtém a quantidade em estoque
 * @return Quantidade disponível em estoque
 */
int Produto::getQuantidadeEstoque() const {
    return quantidadeEstoque;
}

/**
 * @brief Define o preço do produto
 * @param novoPreco Novo preço a ser atribuído
 */
void Produto::setPreco(double novoPreco) {
    if (novoPreco >= 0) {
        preco = novoPreco;
    }
}

/**
 * @brief Define a quantidade em estoque
 * @param novaQuantidade Nova quantidade em estoque
 */
void Produto::setQuantidadeEstoque(int novaQuantidade) {
    if (novaQuantidade >= 0) {
        quantidadeEstoque = novaQuantidade;
    }
}

/**
 * @brief Adiciona quantidade ao estoque
 * @param quantidade Quantidade a ser adicionada
 */
void Produto::adicionarEstoque(int quantidade) {
    if (quantidade > 0) {
        quantidadeEstoque += quantidade;
    }
}

/**
 * @brief Remove quantidade do estoque
 * @param quantidade Quantidade a ser removida
 * @return true se a operação foi bem-sucedida, false se não há estoque suficiente
 */
bool Produto::removerEstoque(int quantidade) {
    if (quantidade > 0 && quantidade <= quantidadeEstoque) {
        quantidadeEstoque -= quantidade;
        return true;
    }
    return false;
}

/**
 * @brief Verifica se o produto está disponível em estoque
 * @return true se há estoque disponível
 */
bool Produto::estaDisponivel() const {
    return quantidadeEstoque > 0;
}

/**
 * @brief Calcula o valor total do estoque
 * @return Valor total (preço * quantidade)
 */
double Produto::calcularValorTotalEstoque() const {
    return preco * quantidadeEstoque;
}

/**
 * @brief Implementação do método virtual puro da classe base
 * 
 * Imprime todas as informações do produto de forma formatada.
 * Demonstra polimorfismo com implementação específica para produtos.
 */
void Produto::imprimirInfo() const {
    std::cout << "=== INFORMAÇÕES DO PRODUTO ===" << std::endl;
    std::cout << "Código: " << ID << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Categoria: " << categoria << std::endl;
    std::cout << "Preço: R$ " << std::fixed << std::setprecision(2) << preco << std::endl;
    std::cout << "Estoque: " << quantidadeEstoque << " unidade(s)" << std::endl;
    std::cout << "Valor Total: R$ " << std::fixed << std::setprecision(2) << calcularValorTotalEstoque() << std::endl;
    std::cout << "Status: " << (estaDisponivel() ? "Disponível" : "Indisponível") << std::endl;
    std::cout << "==============================" << std::endl;
}
