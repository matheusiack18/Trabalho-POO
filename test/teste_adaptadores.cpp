#include "../src/estruturas_encadeadas/PilhaEncadeada.h"
#include "../src/estruturas_encadeadas/FilaEncadeada.h"
#include "../src/estruturas_encadeadas/Deque.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../src/elementos/Produto.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <memory>

void testarPilhaEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "🚀 TESTANDO ADAPTADOR: PILHA ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    PilhaEncadeada pilha;
    
    std::cout << "\n1. 📥 Testando pilha vazia:" << std::endl;
    std::cout << "Pilha vazia? " << (pilha.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << pilha.getTamanho() << std::endl;
    
    std::cout << "\n2. 📚 Empilhando elementos (LIFO):" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    auto produto1 = std::make_unique<Produto>(3, "Notebook", "Eletrônicos", "Dell", 2500.0, 10);
    
    std::cout << "Empilhando Aluno (ID=1)..." << std::endl;
    pilha.empilhar(std::move(aluno1));
    std::cout << "Empilhando Funcionário (ID=2)..." << std::endl;
    pilha.empilhar(std::move(funcionario1));
    std::cout << "Empilhando Produto (ID=3)..." << std::endl;
    pilha.empilhar(std::move(produto1));
    
    std::cout << "Tamanho após empilhamentos: " << pilha.getTamanho() << std::endl;
    pilha.imprimirPilha();
    
    std::cout << "\n3. 🔍 Testando consulta do topo:" << std::endl;
    Elemento* topo = pilha.topo();
    if (topo) {
        std::cout << "Elemento no topo: ";
        topo->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n4. 📤 Testando desempilhamento (LIFO):" << std::endl;
    while (!pilha.estaVazia()) {
        auto desempilhado = pilha.desempilhar();
        if (desempilhado) {
            std::cout << "Desempilhado: ";
            desempilhado->imprimirInfo();
            std::cout << "Tamanho restante: " << pilha.getTamanho() << std::endl;
        }
    }
    
    std::cout << "\n✅ Teste da Pilha Encadeada concluído!" << std::endl;
}

void testarFilaEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "🚀 TESTANDO ADAPTADOR: FILA ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    FilaEncadeada fila;
    
    std::cout << "\n1. 📭 Testando fila vazia:" << std::endl;
    std::cout << "Fila vazia? " << (fila.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << fila.getTamanho() << std::endl;
    
    std::cout << "\n2. 🚶 Enfileirando elementos (FIFO):" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "Ana Costa", "Engenharia", 9.0);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Carlos Lima", "Gerente", "Vendas", 7500.0);
    auto produto1 = std::make_unique<Produto>(3, "Mouse", "Periféricos", "Logitech", 80.0, 50);
    
    std::cout << "Enfileirando Aluno (ID=1)..." << std::endl;
    fila.enfileirar(std::move(aluno1));
    std::cout << "Enfileirando Funcionário (ID=2)..." << std::endl;
    fila.enfileirar(std::move(funcionario1));
    std::cout << "Enfileirando Produto (ID=3)..." << std::endl;
    fila.enfileirar(std::move(produto1));
    
    std::cout << "Tamanho após enfileiramentos: " << fila.getTamanho() << std::endl;
    fila.imprimirFila();
    
    std::cout << "\n3. 🔍 Testando consulta da frente:" << std::endl;
    Elemento* frente = fila.frente();
    if (frente) {
        std::cout << "Elemento na frente: ";
        frente->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n4. 🚪 Testando desenfileiramento (FIFO):" << std::endl;
    while (!fila.estaVazia()) {
        auto desenfileirado = fila.desenfileirar();
        if (desenfileirado) {
            std::cout << "Desenfileirado: ";
            desenfileirado->imprimirInfo();
            std::cout << "Tamanho restante: " << fila.getTamanho() << std::endl;
        }
    }
    
    std::cout << "\n✅ Teste da Fila Encadeada concluído!" << std::endl;
}

void testarDeque() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "🚀 TESTANDO ADAPTADOR: DEQUE" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    Deque deque;
    
    std::cout << "\n1. 📦 Testando deque vazio:" << std::endl;
    std::cout << "Deque vazio? " << (deque.estaVazio() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << deque.getTamanho() << std::endl;
    
    std::cout << "\n2. ⬌ Inserindo elementos em ambas as pontas:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "Pedro Santos", "Física", 9.2);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Sofia Rodrigues", "Analista", "TI", 5500.0);
    auto produto1 = std::make_unique<Produto>(3, "Teclado", "Periféricos", "Microsoft", 200.0, 30);
    auto aluno2 = std::make_unique<Aluno>(4, "Mariana Silva", "Química", 8.8);
    
    std::cout << "Inserindo no início: Aluno (ID=1)..." << std::endl;
    deque.inserirInicio(std::move(aluno1));
    std::cout << "Inserindo no fim: Funcionário (ID=2)..." << std::endl;
    deque.inserirFim(std::move(funcionario1));
    std::cout << "Inserindo no início: Produto (ID=3)..." << std::endl;
    deque.inserirInicio(std::move(produto1));
    std::cout << "Inserindo no fim: Aluno (ID=4)..." << std::endl;
    deque.inserirFim(std::move(aluno2));
    
    std::cout << "Tamanho após inserções: " << deque.getTamanho() << std::endl;
    deque.imprimirDeque();
    
    std::cout << "\n3. 🔍 Testando consultas:" << std::endl;
    Elemento* inicio = deque.inicio();
    Elemento* fim = deque.fim();
    if (inicio) {
        std::cout << "Elemento no início: ";
        inicio->imprimirInfo();
        std::cout << std::endl;
    }
    if (fim) {
        std::cout << "Elemento no fim: ";
        fim->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n4. 🎯 Testando impressão reversa (vantagem da lista dupla):" << std::endl;
    deque.imprimirDequeReverso();
    
    std::cout << "\n5. ↔️ Testando remoções de ambas as pontas:" << std::endl;
    
    std::cout << "Removendo do início..." << std::endl;
    auto removidoInicio = deque.removerInicio();
    if (removidoInicio) {
        std::cout << "Removido do início: ";
        removidoInicio->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "Removendo do fim..." << std::endl;
    auto removidoFim = deque.removerFim();
    if (removidoFim) {
        std::cout << "Removido do fim: ";
        removidoFim->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "Estado final do deque:" << std::endl;
    std::cout << "Tamanho: " << deque.getTamanho() << std::endl;
    deque.imprimirDeque();
    
    std::cout << "\n✅ Teste do Deque concluído!" << std::endl;
}

void demonstrarComplexidades() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "📊 ANÁLISE DE COMPLEXIDADES DOS ADAPTADORES" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    std::cout << "\n🔥 PILHA ENCADEADA (usando ListaSimplesmenteEncadeada):" << std::endl;
    std::cout << "├─ empilhar()     : O(1) - inserção no início" << std::endl;
    std::cout << "├─ desempilhar()  : O(1) - remoção do início" << std::endl;
    std::cout << "├─ topo()         : O(1) - acesso ao primeiro elemento" << std::endl;
    std::cout << "├─ estaVazia()    : O(1) - verificação de tamanho" << std::endl;
    std::cout << "└─ getTamanho()   : O(1) - acesso direto" << std::endl;
    
    std::cout << "\n🚶 FILA ENCADEADA (usando ListaSimplesmenteEncadeada):" << std::endl;
    std::cout << "├─ enfileirar()   : O(1) - inserção no fim (com ponteiro cauda)" << std::endl;
    std::cout << "├─ desenfileirar(): O(1) - remoção do início" << std::endl;
    std::cout << "├─ frente()       : O(1) - acesso ao primeiro elemento" << std::endl;
    std::cout << "├─ estaVazia()    : O(1) - verificação de tamanho" << std::endl;
    std::cout << "└─ getTamanho()   : O(1) - acesso direto" << std::endl;
    
    std::cout << "\n⬌ DEQUE (usando ListaDuplamenteEncadeada):" << std::endl;
    std::cout << "├─ inserirInicio(): O(1) - inserção no início" << std::endl;
    std::cout << "├─ inserirFim()   : O(1) - inserção no fim" << std::endl;
    std::cout << "├─ removerInicio(): O(1) - remoção do início" << std::endl;
    std::cout << "├─ removerFim()   : O(1) - remoção do fim (VANTAGEM da lista dupla!)" << std::endl;
    std::cout << "├─ inicio()       : O(1) - acesso ao primeiro elemento" << std::endl;
    std::cout << "├─ fim()          : O(1) - acesso ao último elemento" << std::endl;
    std::cout << "├─ estaVazio()    : O(1) - verificação de tamanho" << std::endl;
    std::cout << "└─ getTamanho()   : O(1) - acesso direto" << std::endl;
    
    std::cout << "\n🎯 JUSTIFICATIVAS DAS ESCOLHAS:" << std::endl;
    std::cout << "📚 Pilha: ListaSimplesmenteEncadeada é suficiente (só acessa uma ponta)" << std::endl;
    std::cout << "🚶 Fila: ListaSimplesmenteEncadeada com ponteiro cauda otimiza inserção" << std::endl;
    std::cout << "⬌ Deque: ListaDuplamenteEncadeada permite acesso eficiente às duas pontas" << std::endl;
}

int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << "======================================================================" << std::endl;
    std::cout << "🎯 TESTE DOS ADAPTADORES ENCADEADOS" << std::endl;
    std::cout << "Pilha, Fila e Deque implementados por COMPOSIÇÃO" << std::endl;
    std::cout << "======================================================================" << std::endl;
    
    try {
        testarPilhaEncadeada();
        testarFilaEncadeada();
        testarDeque();
        demonstrarComplexidades();
        
        std::cout << "\n" << std::string(70, '=') << std::endl;
        std::cout << "✅ CONCLUÍDA COM SUCESSO!" << std::endl;
        std::cout << "Todos os adaptadores implementados e testados!" << std::endl;
        std::cout << "🔒 Encapsulamento: Nós são privados nas listas" << std::endl;
        std::cout << "🎯 Composição: Adaptadores usam listas como componentes" << std::endl;
        std::cout << "⚡ Otimização: Complexidades O(1) para todas as operações!" << std::endl;
        std::cout << std::string(70, '=') << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Erro durante os testes: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
