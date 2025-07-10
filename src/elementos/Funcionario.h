#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Elemento.h"
#include <string>

/**
 * @brief Classe que representa um funcionário, derivada de Elemento
 * 
 * Segunda implementação da herança da classe abstrata Elemento,
 * demonstrando como diferentes classes podem implementar
 * o mesmo contrato (interface) de formas distintas.
 */
class Funcionario : public Elemento {
private:
    std::string nome;
    std::string cargo;
    std::string departamento;
    double salario;

public:
    /**
     * @brief Construtor da classe Funcionario
     * @param id Identificador único do funcionário
     * @param nome Nome completo do funcionário
     * @param cargo Cargo ocupado pelo funcionário
     * @param departamento Departamento onde trabalha
     * @param salario Salário do funcionário
     */
    Funcionario(long id, const std::string& nome, const std::string& cargo, 
                const std::string& departamento, double salario);

    /**
     * @brief Obtém o nome do funcionário
     * @return Nome completo do funcionário
     */
    std::string getNome() const;

    /**
     * @brief Obtém o cargo do funcionário
     * @return Cargo ocupado pelo funcionário
     */
    std::string getCargo() const;

    /**
     * @brief Obtém o departamento do funcionário
     * @return Departamento onde trabalha
     */
    std::string getDepartamento() const;

    /**
     * @brief Obtém o salário do funcionário
     * @return Salário do funcionário
     */
    double getSalario() const;

    /**
     * @brief Define o salário do funcionário
     * @param novoSalario Novo salário a ser atribuído
     */
    void setSalario(double novoSalario);

    /**
     * @brief Define o cargo do funcionário
     * @param novoCargo Novo cargo a ser atribuído
     */
    void setCargo(const std::string& novoCargo);

    /**
     * @brief Implementação do método virtual puro da classe base
     * 
     * Imprime todas as informações do funcionário de forma formatada.
     * Demonstra polimorfismo com implementação específica diferente
     * da classe Aluno, mas usando a mesma interface.
     */
    void imprimirInfo() const override;
};

#endif
