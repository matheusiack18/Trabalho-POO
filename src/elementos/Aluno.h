#ifndef ALUNO_H
#define ALUNO_H

#include "Elemento.h"
#include <string>

/**
 * @brief Classe que representa um aluno, derivada de Elemento
 * Implementa a herança da classe abstrata Elemento,
 * demonstrando polimorfismo ao implementar o método virtual puro.
 */
class Aluno : public Elemento {
private:
    std::string nome;
    std::string curso;
    double nota;

public:
    /**
     * @brief Construtor da classe Aluno
     * @param id Identificador único do aluno (matrícula)
     * @param nome Nome completo do aluno
     * @param curso Curso em que está matriculado
     * @param nota Nota atual do aluno (0.0 a 10.0)
     * 
     * Inicializa um novo aluno com todas as informações necessárias.
     * A nota é validada para estar entre 0.0 e 10.0.
     */
    Aluno(long id, const std::string& nome, const std::string& curso, double nota);

    /**
     * @brief Obtém o nome do aluno
     * @return Nome completo do aluno
     */
    std::string getNome() const;

    /**
     * @brief Obtém o curso do aluno
     * @return Curso em que está matriculado
     */
    std::string getCurso() const;

    /**
     * @brief Obtém a nota do aluno
     * @return Nota atual do aluno
     */
    double getNota() const;

    /**
     * @brief Define a nota do aluno
     * @param novaNota Nova nota a ser atribuída
     */
    void setNota(double novaNota);

    /**
     * @brief Implementação do método virtual puro da classe base
     * 
     * Imprime todas as informações do aluno de forma formatada.
     * Demonstra polimorfismo ao fornecer implementação específica
     * para a classe Aluno.
     */
    void imprimirInfo() const override;
};

#endif
