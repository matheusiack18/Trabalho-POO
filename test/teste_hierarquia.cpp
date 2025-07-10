#include "../src/elementos/Elemento.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief Função de teste para demonstrar a hierarquia de classes
 * 
 * Este arquivo demonstra:
 * - Abstração: Elemento não pode ser instanciada diretamente
 * - Herança: Aluno e Funcionario herdam de Elemento
 * - Polimorfismo: imprimirInfo() é chamado de forma polimórfica
 * - Encapsulamento: Acesso controlado aos atributos através de métodos
 */
int main() {
    // Configura locale para português
    CONFIGURAR_PORTUGUES();
    std::cout << "=== TESTE DA HIERARQUIA DE CLASSES ===" << std::endl << std::endl;

    // Tentativa de instanciar Elemento diretamente (deve gerar erro de compilação)
    // Elemento elem(1); // ERRO: classe abstrata não pode ser instanciada

    std::cout << "1. Criando objetos das classes derivadas:" << std::endl;
    
    // Criando objetos das classes derivadas
    Aluno aluno1(20231001, "João Silva", "Engenharia de Software", 8.5);
    Funcionario func1(100001, "Maria Santos", "Desenvolvedora", "TI", 5500.00);

    std::cout << "\n2. Testando métodos específicos:" << std::endl;
    std::cout << "Aluno - ID: " << aluno1.getID() << ", Nome: " << aluno1.getNome() << std::endl;
    std::cout << "Funcionário - ID: " << func1.getID() << ", Nome: " << func1.getNome() << std::endl;

    std::cout << "\n3. Demonstrando polimorfismo com ponteiros para classe base:" << std::endl;
    
    // Vetor de ponteiros para a classe base (polimorfismo)
    std::vector<std::unique_ptr<Elemento>> elementos;
    
    elementos.push_back(std::make_unique<Aluno>(20231002, "Ana Costa", "Ciência da Computação", 9.2));
    elementos.push_back(std::make_unique<Funcionario>(100002, "Carlos Oliveira", "Gerente", "Vendas", 7800.00));
    elementos.push_back(std::make_unique<Aluno>(20231003, "Pedro Souza", "Sistemas de Informação", 7.8));

    // Chamada polimórfica do método imprimirInfo()
    for (const auto& elemento : elementos) {
        elemento->imprimirInfo();
        std::cout << std::endl;
    }

    std::cout << "4. Testando operadores de comparação:" << std::endl;
    Aluno aluno2(20231001, "Outro Aluno", "Outro Curso", 7.0);
    
    if (aluno1 == aluno2) {
        std::cout << "Alunos têm o mesmo ID" << std::endl;
    }
    
    if (aluno1 < func1) {
        std::cout << "ID do aluno é menor que ID do funcionário" << std::endl;
    }

    std::cout << "\n=== TESTE CONCLUÍDO COM SUCESSO ===" << std::endl;
    
    return 0;
}
