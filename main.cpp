#include "src/elementos/Aluno.h"
#include "src/elementos/Funcionario.h"
#include "src/elementos/Produto.h"
#include "src/estruturas_sequenciais/ListaNaoOrdenada.h"
#include "src/estruturas_sequenciais/ListaOrdenada.h"
#include "src/estruturas_sequenciais/Pilha.h"
#include "src/estruturas_sequenciais/Fila.h"
#include "src/estruturas_sequenciais/FilaOtimizada.h"
#include "src/estruturas_encadeadas/ListaSimplesmenteEncadeada.h"
#include "src/estruturas_encadeadas/ListaDuplamenteEncadeada.h"
#include "src/estruturas_encadeadas/PilhaEncadeada.h"
#include "src/estruturas_encadeadas/FilaEncadeada.h"
#include "src/estruturas_encadeadas/Deque.h"
#include "src/estruturas_encadeadas/ArvoreBinariaBusca.h"
#include "ConfigLocale.h"
#include <iostream>
#include <memory>
#include <vector>
#include "funcoes.h"



int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << "======================================================================" << std::endl;
    std::cout << "DEMONSTRAÇÃO COMPLETA DO PROJETO" << std::endl;
    std::cout << "Main.cpp - Teste Integrado de Todas as Estruturas" << std::endl;
    std::cout << "======================================================================" << std::endl;
    
    try {
        // PARTE 1: Estruturas Sequenciais
        testarEstruturasSequenciais();
        
        // PARTE 2: Estruturas Encadeadas
        testarEstruturasEncadeadas();
        
        // PARTE 3: Árvore Binária de Busca
        testarArvoreBinariaBusca();
        
        // PARTE 4: Demonstração de Encapsulamento
        demonstrarEncapsulamento();
        
        // DEMONSTRAÇÃO FINAL: Integração Completa
        demonstracaoIntegrada();
        
        std::cout << "\n" << std::string(70, '=') << std::endl;
        std::cout << "CONCLUÍDA COM SUCESSO!" << std::endl;
        std::cout << "======================================================================" << std::endl;
        std::cout << "✅ Estruturas Sequenciais: Testadas com polimorfismo" << std::endl;
        std::cout << "✅ Estruturas Encadeadas: Inserções, buscas, remoções validadas" << std::endl;
        std::cout << "✅ Árvore Binária: Organização hierárquica demonstrada" << std::endl;
        std::cout << "✅ Encapsulamento: Apenas interface pública acessível" << std::endl;
        std::cout << "✅ Polimorfismo: imprimirInfo() específico para cada classe" << std::endl;
        std::cout << "✅ Integração: Todas as estruturas trabalhando em conjunto" << std::endl;
        std::cout << "======================================================================" << std::endl;
        std::cout << "PROJETO COMPLETO" << std::endl;
        std::cout << "======================================================================" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a demonstração: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
