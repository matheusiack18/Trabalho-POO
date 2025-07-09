#include "Elemento.h"
#include "Aluno.h"
#include "Funcionario.h"
#include "Produto.h"
#include "ConfigLocale.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief Demonstração completa da hierarquia com todas as classes
 * 
 * Este arquivo testa todas as três classes derivadas: Aluno, Funcionario e Produto
 */

int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << "========== DEMONSTRAÇÃO COMPLETA DA HIERARQUIA ==========" << std::endl;
    std::cout << "Testando as três classes: Aluno, Funcionario e Produto" << std::endl << std::endl;

    // =================== TESTE DA CLASSE PRODUTO ===================
    std::cout << "================= TESTE CLASSE PRODUTO =================" << std::endl;
    
    std::cout << "\n1. Criando produtos diversos:" << std::endl;
    
    Produto produto1(7891001, "Notebook Gamer", "Eletronicos", "TechBrand", 2499.99, 15);
    Produto produto2(7891002, "Mouse Wireless", "Eletronicos", "TechBrand", 89.90, 50);
    Produto produto3(7891003, "Cadeira Ergonomica", "Moveis", "Comfort", 699.00, 8);
    
    std::cout << "Três produtos criados com sucesso!" << std::endl;
    
    std::cout << "\n2. Testando métodos específicos de Produto:" << std::endl;
    produto1.imprimirInfo();
    
    std::cout << "\n3. Testando operações de estoque:" << std::endl;
    std::cout << "Estoque inicial do mouse: " << produto2.getQuantidadeEstoque() << std::endl;
    
    // Vendendo produtos (removendo do estoque)
    if (produto2.removerEstoque(10)) {
        std::cout << "Venda de 10 mouses realizada com sucesso!" << std::endl;
    }
    std::cout << "Estoque após venda: " << produto2.getQuantidadeEstoque() << std::endl;
    
    // Recebendo mercadoria (adicionando ao estoque)
    produto2.adicionarEstoque(25);
    std::cout << "Estoque após reposição: " << produto2.getQuantidadeEstoque() << std::endl;
    
    // =================== POLIMORFISMO COMPLETO ===================
    std::cout << "\n\n========= POLIMORFISMO COM TODAS AS CLASSES =========" << std::endl;
    
    std::vector<std::unique_ptr<Elemento>> elementos;
    
    // Adicionando diferentes tipos de elementos
    elementos.push_back(std::make_unique<Aluno>(20231010, "Carlos Silva", "Ciência da Computação", 9.2));
    elementos.push_back(std::make_unique<Funcionario>(100010, "Ana Santos", "Desenvolvedora", "TI", 6800.00));
    elementos.push_back(std::make_unique<Produto>(7891004, "Smartphone", "Eletronicos", "MobileTech", 1299.99, 20));
    elementos.push_back(std::make_unique<Aluno>(20231011, "Maria Costa", "Engenharia", 8.7));
    elementos.push_back(std::make_unique<Produto>(7891005, "Livro de C++", "Livros", "TechBooks", 89.90, 12));
    
    std::cout << "\n1. Lista heterogênea com " << elementos.size() << " elementos:" << std::endl;
    
    for (size_t i = 0; i < elementos.size(); i++) {
        std::cout << "\n--- Elemento " << (i + 1) << " (ID: " << elementos[i]->getID() << ") ---" << std::endl;
        elementos[i]->imprimirInfo();
    }
    
    // =================== TESTE DE ORDENAÇÃO ===================
    std::cout << "\n\n============= TESTE DE ORDENAÇÃO POR ID =============" << std::endl;
    
    std::vector<std::unique_ptr<Elemento>> elementosParaOrdenar;
    
    elementosParaOrdenar.push_back(std::make_unique<Produto>(300, "Produto C", "Cat", "Marca", 100.0, 10));
    elementosParaOrdenar.push_back(std::make_unique<Aluno>(100, "Aluno A", "Curso", 8.0));
    elementosParaOrdenar.push_back(std::make_unique<Funcionario>(200, "Funcionário B", "Cargo", "Depto", 5000.0));
    
    std::cout << "\nAntes da ordenação:" << std::endl;
    for (const auto& elem : elementosParaOrdenar) {
        std::cout << "ID: " << elem->getID() << std::endl;
    }
    
    // Ordenação usando o operador < implementado
    std::sort(elementosParaOrdenar.begin(), elementosParaOrdenar.end(),
              [](const std::unique_ptr<Elemento>& a, const std::unique_ptr<Elemento>& b) {
                  return *a < *b;
              });
    
    std::cout << "\nApós ordenação por ID:" << std::endl;
    for (const auto& elem : elementosParaOrdenar) {
        std::cout << "ID: " << elem->getID() << std::endl;
    }
    
    // =================== RESUMO FINAL ===================
    std::cout << "\n\n=================== RESUMO FINAL ===================" << std::endl;
    std::cout << "Classe Aluno: Implementada com atributos nome, curso e nota" << std::endl;
    std::cout << "Classe Funcionario: Implementada com nome, cargo, departamento e salário" << std::endl;
    std::cout << "Classe Produto: Implementada com nome, categoria, marca, preço e estoque" << std::endl;
    std::cout << "Todas implementam imprimirInfo() de forma específica" << std::endl;
    std::cout << "Polimorfismo funcionando com vetor heterogêneo" << std::endl;
    std::cout << "Operadores de comparação permitem ordenação" << std::endl;
    std::cout << "Encapsulamento: atributos privados com acesso controlado" << std::endl;
    std::cout << "Herança: reutilização do código da classe base Elemento" << std::endl;
    
    std::cout << "\n HIERARQUIA DE CLASSES COMPLETA E FUNCIONAL!" << std::endl;
    
    return 0;
}
