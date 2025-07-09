#include "Elemento.h"

/**
 * @brief Construtor da classe Elemento
 * @param id Identificador único do elemento
 * 
 * Inicializa o atributo protegido ID com o valor fornecido.
 */
Elemento::Elemento(long id) : ID(id) {
    // Construtor implementa inicialização simples do ID
}

/**
 * @brief Obtém o ID do elemento
 * @return O identificador único do elemento
 * 
 * Método const que garante que o objeto não será modificado
 * durante a consulta, implementando boas práticas de encapsulamento.
 */
long Elemento::getID() const {
    return ID;
}

/**
 * @brief Operador de comparação para ordenação por ID
 * @param outro Elemento a ser comparado
 * @return true se este elemento tem ID menor que o outro
 */
bool Elemento::operator<(const Elemento& outro) const {
    return this->ID < outro.ID;
}

/**
 * @brief Operador de igualdade baseado no ID
 * @param outro Elemento a ser comparado
 * @return true se os IDs são iguais
 */
bool Elemento::operator==(const Elemento& outro) const {
    return this->ID == outro.ID;
}
