#ifndef ELEMENTO_H
#define ELEMENTO_H

/**
 * @brief Classe abstrata que serve como base para todos os elementos
 * que podem ser armazenados nas estruturas de dados do projeto.
 */
class Elemento {
protected:
    /**
     * @brief Identificador único do elemento
     * 
     * Atributo protegido que pode ser acessado pelas classes derivadas
     * mas não diretamente por código externo, implementando encapsulamento.
     */
    long ID;

public:
    /**
     * @brief Construtor da classe Elemento
     * @param id Identificador único do elemento
     */
    explicit Elemento(long id);

    /**
     * @brief Destrutor virtual para permitir polimorfismo adequado
     * 
     * Virtual para garantir que o destrutor correto seja chamado
     * quando objetos são deletados através de ponteiros para a classe base.
     */
    virtual ~Elemento() = default;

    /**
     * @brief Obtém o ID do elemento
     * @return O identificador único do elemento
     * 
     * Método público const que permite acesso controlado ao ID,
     * implementando encapsulamento.
     */
    long getID() const;

    /**
     * @brief Imprime as informações do elemento
     * 
     * Método virtual puro que deve ser implementado por todas as classes
     * derivadas. Implementa polimorfismo e abstração, forçando cada
     * classe filha a definir como suas informações serão exibidas.
     */
    virtual void imprimirInfo() const = 0;

    /**
     * @brief Operador de comparação para ordenação por ID
     * @param outro Elemento a ser comparado
     * @return true se este elemento tem ID menor que o outro
     */
    virtual bool operator<(const Elemento& outro) const;

    /**
     * @brief Operador de igualdade baseado no ID
     * @param outro Elemento a ser comparado
     * @return true se os IDs são iguais
     */
    virtual bool operator==(const Elemento& outro) const;
};

#endif
