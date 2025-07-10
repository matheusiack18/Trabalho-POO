#include "../src/estruturas_sequenciais/Pilha.h"
#include "../src/estruturas_sequenciais/Fila.h"
#include "../src/estruturas_sequenciais/FilaOtimizada.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../src/elementos/Produto.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <memory>

void testarPilha() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: PILHA" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    Pilha pilha(5);  // Capacidade máxima de 5 elementos
    
    std::cout << "\n1. Testando pilha vazia:" << std::endl;
    std::cout << "Pilha vazia? " << (pilha.pilhaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << pilha.getTamanho() << std::endl;
    
    std::cout << "\n2. Empilhando elementos:" << std::endl;
    
    // Empilha alguns alunos
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Ciência da Computação", 8.5);
    auto aluno2 = std::make_unique<Aluno>(2, "Maria Santos", "Engenharia", 9.2);
    auto funcionario1 = std::make_unique<Funcionario>(3, "Carlos Oliveira", "Analista", "TI", 5000.0);
    auto produto1 = std::make_unique<Produto>(4, "Laptop", "Eletrônicos", "Dell", 2500.0, 10);
    auto produto2 = std::make_unique<Produto>(5, "Mouse", "Periféricos", "Logitech", 50.0, 100);
    
    std::cout << "Empilhando Aluno 1: " << (pilha.empilhar(std::move(aluno1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Empilhando Aluno 2: " << (pilha.empilhar(std::move(aluno2)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Empilhando Funcionário: " << (pilha.empilhar(std::move(funcionario1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Empilhando Produto 1: " << (pilha.empilhar(std::move(produto1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Empilhando Produto 2: " << (pilha.empilhar(std::move(produto2)) ? "Sucesso" : "Falha") << std::endl;
    
    std::cout << "\nTamanho após empilhamentos: " << pilha.getTamanho() << std::endl;
    std::cout << "Pilha cheia? " << (pilha.pilhaCheia() ? "Sim" : "Não") << std::endl;
    
    std::cout << "\n3. Tentando empilhar em pilha cheia:" << std::endl;
    auto produtoExtra = std::make_unique<Produto>(6, "Teclado", "Periféricos", "Microsoft", 100.0, 50);
    std::cout << "Tentativa de empilhar elemento extra: " << (pilha.empilhar(std::move(produtoExtra)) ? "Sucesso" : "Falha - Pilha cheia") << std::endl;
    
    std::cout << "\n4. Consultando topo:" << std::endl;
    Elemento* topo = pilha.consultarTopo();
    if (topo) {
        std::cout << "Elemento no topo: ";
        topo->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n5. Imprimindo pilha completa:" << std::endl;
    pilha.imprimirPilha();
    
    std::cout << "\n6. Desempilhando elementos:" << std::endl;
    while (!pilha.pilhaVazia()) {
        auto elemento = pilha.desempilhar();
        if (elemento) {
            std::cout << "Desempilhado: ";
            elemento->imprimirInfo();
            std::cout << " (Tamanho restante: " << pilha.getTamanho() << ")" << std::endl;
        }
    }
    
    std::cout << "\n7. Tentando desempilhar de pilha vazia:" << std::endl;
    auto elementoVazio = pilha.desempilhar();
    std::cout << "Resultado: " << (elementoVazio ? "Elemento retornado" : "nullptr - Pilha vazia") << std::endl;
}

void testarFila() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: FILA (Versão Ineficiente)" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    Fila fila(4);  // Capacidade máxima de 4 elementos
    
    std::cout << "\n1. Testando fila vazia:" << std::endl;
    std::cout << "Fila vazia? " << (fila.filaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << fila.getTamanho() << std::endl;
    
    std::cout << "\n2. Enfileirando elementos:" << std::endl;
    
    auto aluno1 = std::make_unique<Aluno>(1, "Ana Costa", "Matemática", 9.0);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Pedro Lima", "Analista", "RH", 4500.0);
    auto produto1 = std::make_unique<Produto>(3, "Smartphone", "Eletrônicos", "Samsung", 1200.0, 25);
    auto aluno2 = std::make_unique<Aluno>(4, "Lucas Ferreira", "Física", 8.8);
    
    std::cout << "Enfileirando Aluno 1: " << (fila.enfileirar(std::move(aluno1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando Funcionário: " << (fila.enfileirar(std::move(funcionario1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando Produto: " << (fila.enfileirar(std::move(produto1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando Aluno 2: " << (fila.enfileirar(std::move(aluno2)) ? "Sucesso" : "Falha") << std::endl;
    
    std::cout << "\nTamanho após enfileiramentos: " << fila.getTamanho() << std::endl;
    std::cout << "Fila cheia? " << (fila.filaCheia() ? "Sim" : "Não") << std::endl;
    
    std::cout << "\n3. Tentando enfileirar em fila cheia:" << std::endl;
    auto produtoExtra = std::make_unique<Produto>(5, "Tablet", "Eletrônicos", "Apple", 800.0, 15);
    std::cout << "Tentativa de enfileirar elemento extra: " << (fila.enfileirar(std::move(produtoExtra)) ? "Sucesso" : "Falha - Fila cheia") << std::endl;
    
    std::cout << "\n4. Consultando frente:" << std::endl;
    Elemento* frente = fila.consultarFrente();
    if (frente) {
        std::cout << "Elemento na frente: ";
        frente->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n5. Imprimindo fila completa:" << std::endl;
    fila.imprimirFila();
    
    std::cout << "\n6. Desenfileirando alguns elementos:" << std::endl;
    for (int i = 0; i < 2; i++) {
        auto elemento = fila.desenfileirar();
        if (elemento) {
            std::cout << "Desenfileirado: ";
            elemento->imprimirInfo();
            std::cout << " (Tamanho restante: " << fila.getTamanho() << ")" << std::endl;
        }
    }
    
    std::cout << "\n7. Estado da fila após desenfileirar:" << std::endl;
    fila.imprimirFila();
    
    std::cout << "\n8. Enfileirando novos elementos:" << std::endl;
    auto novoAluno = std::make_unique<Aluno>(6, "Sofia Rodrigues", "Química", 9.5);
    auto novoFuncionario = std::make_unique<Funcionario>(7, "Ricardo Alves", "Vendedor", "Vendas", 3500.0);
    
    std::cout << "Enfileirando novo Aluno: " << (fila.enfileirar(std::move(novoAluno)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando novo Funcionário: " << (fila.enfileirar(std::move(novoFuncionario)) ? "Sucesso" : "Falha") << std::endl;
    
    std::cout << "\n9. Estado final da fila:" << std::endl;
    fila.imprimirFila();
}

void testarFilaOtimizada() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: FILA OTIMIZADA (Buffer Circular)" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    FilaOtimizada filaOpt(3);  // Capacidade máxima de 3 elementos
    
    std::cout << "\n1. Testando fila otimizada vazia:" << std::endl;
    std::cout << "Fila vazia? " << (filaOpt.filaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << filaOpt.getTamanho() << std::endl;
    
    std::cout << "\n2. Enfileirando elementos:" << std::endl;
    
    auto produto1 = std::make_unique<Produto>(1, "Monitor", "Eletrônicos", "LG", 800.0, 5);
    auto produto2 = std::make_unique<Produto>(2, "Impressora", "Periféricos", "HP", 400.0, 3);
    auto produto3 = std::make_unique<Produto>(3, "Scanner", "Periféricos", "Canon", 300.0, 8);
    
    std::cout << "Enfileirando Produto 1: " << (filaOpt.enfileirar(std::move(produto1)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando Produto 2: " << (filaOpt.enfileirar(std::move(produto2)) ? "Sucesso" : "Falha") << std::endl;
    std::cout << "Enfileirando Produto 3: " << (filaOpt.enfileirar(std::move(produto3)) ? "Sucesso" : "Falha") << std::endl;
    
    std::cout << "\nFila cheia? " << (filaOpt.filaCheia() ? "Sim" : "Não") << std::endl;
    filaOpt.imprimirFila();
    
    std::cout << "\n3. Testando comportamento circular:" << std::endl;
    std::cout << "Desenfileirando um elemento..." << std::endl;
    auto elementoRemovido = filaOpt.desenfileirar();
    if (elementoRemovido) {
        std::cout << "Removido: ";
        elementoRemovido->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\nEnfileirando novo elemento na posição liberada:" << std::endl;
    auto novoProduto = std::make_unique<Produto>(4, "Webcam", "Periféricos", "Logitech", 150.0, 20);
    std::cout << "Enfileirando Webcam: " << (filaOpt.enfileirar(std::move(novoProduto)) ? "Sucesso" : "Falha") << std::endl;
    
    std::cout << "\n4. Estado final da fila otimizada:" << std::endl;
    filaOpt.imprimirFila();
    
    std::cout << "\n5. Esvaziando a fila:" << std::endl;
    while (!filaOpt.filaVazia()) {
        auto elemento = filaOpt.desenfileirar();
        if (elemento) {
            std::cout << "Desenfileirado: ";
            elemento->imprimirInfo();
            std::cout << std::endl;
        }
    }
    
    std::cout << "\nFila vazia? " << (filaOpt.filaVazia() ? "Sim" : "Não") << std::endl;
}

void compararPerformance() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "COMPARAÇÃO DE PERFORMANCE: FILA vs FILA OTIMIZADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    std::cout << "\nFILA INEFICIENTE (Lista Sequencial):" << std::endl;
    std::cout << "- Enfileirar: O(1) - inserção no final" << std::endl;
    std::cout << "- Desenfileirar: O(n) - remoção do início com deslocamento" << std::endl;
    std::cout << "- Problema: A cada desenfileiramento, todos os elementos" << std::endl;
    std::cout << "  restantes precisam ser deslocados uma posição." << std::endl;
    
    std::cout << "\nFILA OTIMIZADA (Buffer Circular):" << std::endl;
    std::cout << "- Enfileirar: O(1) - inserção na posição circular" << std::endl;
    std::cout << "- Desenfileirar: O(1) - remoção na posição circular" << std::endl;
    std::cout << "- Vantagem: Não há deslocamento de elementos, apenas" << std::endl;
    std::cout << "  movimentação dos índices de início e fim." << std::endl;
    
    std::cout << "\nCONCLUSÃO:" << std::endl;
    std::cout << "Para operações frequentes de enfileirar/desenfileirar," << std::endl;
    std::cout << "a FilaOtimizada é significativamente mais eficiente!" << std::endl;
}

int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "TESTE COMPLETO DAS ESTRUTURAS PILHA E FILA" << std::endl;
    std::cout << "Implementação por Composição usando Lista Não Ordenada" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    try {
        testarPilha();
        testarFila();
        testarFilaOtimizada();
        compararPerformance();
        
        std::cout << "\n" << std::string(60, '=') << std::endl;
        std::cout << "TODOS OS TESTES EXECUTADOS COM SUCESSO!" << std::endl;
        std::cout << std::string(60, '=') << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Erro durante os testes: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
