#include "Funcionario.h"
#include "../../ConfigLocale.h"
#include <iostream>
#include <iomanip>
#include <locale.h>

/**
 * @brief 
 * @param id 
 * @param nome 
 * @param cargo 
 * @param departamento 
 * @param salario 
 */
Funcionario::Funcionario(long id, const std::string& nome, const std::string& cargo,
                         const std::string& departamento, double salario)
    : Elemento(id), nome(nome), cargo(cargo), departamento(departamento), salario(salario) {
}

/**
 * @brief Obtém o nome do funcionário
 * @return Nome completo do funcionário
 */
std::string Funcionario::getNome() const {
    return nome;
}

/**
 * @brief Obtém o cargo do funcionário
 * @return Cargo ocupado pelo funcionário
 */
std::string Funcionario::getCargo() const {
    return cargo;
}

/**
 * @brief Obtém o departamento do funcionário
 * @return Departamento onde trabalha
 */
std::string Funcionario::getDepartamento() const {
    return departamento;
}

/**
 * @brief Obtém o salário do funcionário
 * @return Salário do funcionário
 */
double Funcionario::getSalario() const {
    return salario;
}

/**
 * @brief Define o salário do funcionário
 * @param novoSalario Novo salário a ser atribuído
 */
void Funcionario::setSalario(double novoSalario) {
    salario = novoSalario;
}

/**
 * @brief Define o cargo do funcionário
 * @param novoCargo Novo cargo a ser atribuído
 */
void Funcionario::setCargo(const std::string& novoCargo) {
    cargo = novoCargo;
}

/**
 * @brief Implementação do método virtual puro da classe base
 * 
 * Imprime todas as informações do funcionário de forma formatada.
 * Demonstra polimorfismo com implementação específica diferente
 * da classe Aluno, mas usando a mesma interface.
 */
void Funcionario::imprimirInfo() const {
    std::cout << "=== INFORMAÇÕES DO FUNCIONÁRIO ===" << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Salário: R$ " << std::fixed << std::setprecision(2) << salario << std::endl;
    std::cout << "==================================" << std::endl;
}
