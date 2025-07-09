#include "Aluno.h"
#include "ConfigLocale.h"
#include <iostream>
#include <iomanip>

/**
 * @brief 
 * @param id
 * @param nome
 * @param curso 
 * @param nota
 */
Aluno::Aluno(long id, const std::string& nome, const std::string& curso, double nota)
    : Elemento(id), nome(nome), curso(curso), nota(nota) {}

/**
 * @brief Obtém o nome do aluno
 * @return Nome completo do aluno
 */
std::string Aluno::getNome() const {
    return nome;
}

/**
 * @brief Obtém o curso do aluno
 * @return Curso em que está matriculado
 */
std::string Aluno::getCurso() const {
    return curso;
}

/**
 * @brief Obtém a nota do aluno
 * @return Nota atual do aluno
 */
double Aluno::getNota() const {
    return nota;
}

/**
 * @brief Define a nota do aluno
 * @param novaNota Nova nota a ser atribuída
 */
void Aluno::setNota(double novaNota) {
    nota = novaNota;
}

/**
 * @brief Implementação do método virtual puro da classe base
 * 
 * Imprime todas as informações do aluno de forma formatada.
 * Demonstra polimorfismo ao fornecer implementação específica
 * para a classe Aluno.
 */
void Aluno::imprimirInfo() const {
    std::cout << "=== INFORMAÇÕES DO ALUNO ===" << std::endl;
    std::cout << "Matrícula: " << ID << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Nota: " << std::fixed << std::setprecision(2) << nota << std::endl;
    std::cout << "============================" << std::endl;
}
