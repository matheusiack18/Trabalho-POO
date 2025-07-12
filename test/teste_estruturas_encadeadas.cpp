#include "../src/estruturas_encadeadas/ListaSimplesmenteEncadeada.h"
#include "../src/estruturas_encadeadas/ListaDuplamenteEncadeada.h"
#include "../src/estruturas_encadeadas/ListaDuplamenteEncadeadaCircular.h"
#include "../src/estruturas_encadeadas/PilhaEncadeada.h"
#include "../src/estruturas_encadeadas/FilaEncadeada.h"
#include "../src/estruturas_encadeadas/Deque.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../src/elementos/Produto.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <memory>

// Declarações das funções de teste
void testarListaSimplesmenteEncadeada();
void testarListaDuplamenteEncadeada();
void testarListaDuplamenteEncadeadaCircular();
void testarPilhaEncadeada();
void testarFilaEncadeada();
void testarDeque();
void compararEstruturas();
void demonstrarEncapsulamento();
void testarAdaptadores();

void testarListaSimplesmenteEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: LISTA SIMPLESMENTE ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    ListaSimplesmenteEncadeada lista;
    
    std::cout << "\n1. Testando lista vazia:" << std::endl;
    std::cout << "Lista vazia? " << (lista.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << lista.getTamanho() << std::endl;
    
    std::cout << "\n2. Inserindo elementos no início:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    auto produto1 = std::make_unique<Produto>(3, "Notebook", "Eletrônicos", "Dell", 2500.0, 10);
    
    lista.inserirNoInicio(std::move(aluno1));
    lista.inserirNoInicio(std::move(funcionario1));
    lista.inserirNoInicio(std::move(produto1));
    
    std::cout << "Tamanho após inserções no início: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n3. Inserindo elementos no fim:" << std::endl;
    auto aluno2 = std::make_unique<Aluno>(4, "Ana Costa", "Engenharia", 9.0);
    auto produto2 = std::make_unique<Produto>(5, "Mouse", "Periféricos", "Logitech", 50.0, 100);
    
    lista.inserirNoFim(std::move(aluno2));
    lista.inserirNoFim(std::move(produto2));
    
    std::cout << "Tamanho após inserções no fim: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n4. Testando busca por ID:" << std::endl;
    Elemento* encontrado = lista.buscarPeloId(2);
    if (encontrado) {
        std::cout << "Elemento encontrado (ID=2): ";
        encontrado->imprimirInfo();
        std::cout << std::endl;
    } else {
        std::cout << "Elemento não encontrado!" << std::endl;
    }
    
    std::cout << "\n5. Testando alteração por ID:" << std::endl;
    auto novoProduto = std::make_unique<Produto>(3, "Notebook Gaming", "Eletrônicos", "Dell", 3500.0, 5);
    bool alterado = lista.alterarPeloId(3, std::move(novoProduto));
    std::cout << "Alteração " << (alterado ? "bem-sucedida" : "falhou") << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n6. Testando remoção por ID:" << std::endl;
    auto elementoRemovido = lista.removerPeloId(4);
    if (elementoRemovido) {
        std::cout << "Elemento removido (ID=4): ";
        elementoRemovido->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após remoção: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n7. Testando remoção primeiro e último:" << std::endl;
    auto primeiro = lista.removerPrimeiro();
    auto ultimo = lista.removerUltimo();
    
    std::cout << "Primeiro removido: ";
    primeiro->imprimirInfo();
    std::cout << std::endl;
    
    std::cout << "Último removido: ";
    ultimo->imprimirInfo();
    std::cout << std::endl;
    
    std::cout << "Estado final:" << std::endl;
    lista.imprimirLista();
}

void testarListaDuplamenteEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: LISTA DUPLAMENTE ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    ListaDuplamenteEncadeada lista;
    
    std::cout << "\n1. Inserindo elementos:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(10, "Carlos Lima", "Matemática", 8.8);
    auto funcionario1 = std::make_unique<Funcionario>(20, "Sofia Rodrigues", "Gerente", "Admin", 8000.0);
    auto produto1 = std::make_unique<Produto>(30, "Teclado", "Periféricos", "Microsoft", 200.0, 50);
    auto aluno2 = std::make_unique<Aluno>(40, "Pedro Santos", "Física", 9.2);
    
    lista.inserirNoInicio(std::move(aluno1));
    lista.inserirNoFim(std::move(funcionario1));
    lista.inserirNoFim(std::move(produto1));
    lista.inserirNoInicio(std::move(aluno2));
    
    std::cout << "Tamanho: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n2. Demonstrando navegação reversa:" << std::endl;
    lista.imprimirListaReversa();
    
    std::cout << "\n3. Testando inserção em posição específica:" << std::endl;
    auto novoFuncionario = std::make_unique<Funcionario>(25, "Ricardo Alves", "Analista", "TI", 5500.0);
    bool inserido = lista.inserirNaPosicao(2, std::move(novoFuncionario));
    std::cout << "Inserção na posição 2: " << (inserido ? "Sucesso" : "Falha") << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n4. Testando remoção da posição específica:" << std::endl;
    auto removidoPosicao = lista.removerDaPosicao(1);
    if (removidoPosicao) {
        std::cout << "Elemento removido da posição 1: ";
        removidoPosicao->imprimirInfo();
        std::cout << std::endl;
    }
    lista.imprimirLista();
    
    std::cout << "\n5. Testando remoção último (O(1) na lista dupla):" << std::endl;
    auto ultimo = lista.removerUltimo();
    if (ultimo) {
        std::cout << "Último elemento removido: ";
        ultimo->imprimirInfo();
        std::cout << std::endl;
    }
    lista.imprimirLista();
}

void testarListaDuplamenteEncadeadaCircular() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: LISTA DUPLAMENTE ENCADEADA CIRCULAR" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    ListaDuplamenteEncadeadaCircular lista;
    
    std::cout << "\n1. Inserindo elementos:" << std::endl;
    auto produto1 = std::make_unique<Produto>(100, "Monitor", "Eletrônicos", "LG", 800.0, 8);
    auto produto2 = std::make_unique<Produto>(200, "Impressora", "Periféricos", "HP", 400.0, 3);
    auto produto3 = std::make_unique<Produto>(300, "Scanner", "Periféricos", "Canon", 300.0, 5);
    auto produto4 = std::make_unique<Produto>(400, "Webcam", "Periféricos", "Logitech", 150.0, 20);
    
    lista.inserirNoFim(std::move(produto1));
    lista.inserirNoFim(std::move(produto2));
    lista.inserirNoFim(std::move(produto3));
    lista.inserirNoFim(std::move(produto4));
    
    std::cout << "Tamanho: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n2. Demonstrando navegação reversa:" << std::endl;
    lista.imprimirListaReversa();
    
    std::cout << "\n3. Demonstrando comportamento circular:" << std::endl;
    lista.imprimirListaCircular(2);  // 2 voltas completas
    
    std::cout << "\n4. Testando verificação de integridade:" << std::endl;
    bool integra = lista.verificarIntegridade();
    std::cout << "Integridade da estrutura circular: " << (integra ? "OK" : "FALHA") << std::endl;
    
    std::cout << "\n5. Testando rotação para direita:" << std::endl;
    std::cout << "Antes da rotação:" << std::endl;
    lista.imprimirLista();
    
    lista.rotacionarDireita(2);
    std::cout << "Após rotação de 2 posições para direita:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n6. Testando rotação para esquerda:" << std::endl;
    lista.rotacionarEsquerda(1);
    std::cout << "Após rotação de 1 posição para esquerda:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n7. Testando remoção por ID:" << std::endl;
    auto removido = lista.removerPeloId(200);
    if (removido) {
        std::cout << "Elemento removido (ID=200): ";
        removido->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "Estado após remoção:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "Verificando integridade após remoção: " << (lista.verificarIntegridade() ? "OK" : "FALHA") << std::endl;
}

void testarPilhaEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: PILHA ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    PilhaEncadeada pilha;
    
    std::cout << "\n1. Testando pilha vazia:" << std::endl;
    std::cout << "Pilha vazia? " << (pilha.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << pilha.getTamanho() << std::endl;
    
    std::cout << "\n2. Empilhando elementos:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    
    pilha.empilhar(std::move(aluno1));
    pilha.empilhar(std::move(funcionario1));
    
    std::cout << "Tamanho após empilhamentos: " << pilha.getTamanho() << std::endl;
    pilha.imprimirPilha();
    
    std::cout << "\n3. Testando desempilhamento:" << std::endl;
    auto desempilhado = pilha.desempilhar();
    if (desempilhado) {
        std::cout << "Elemento desempilhado: ";
        desempilhado->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após desempilhamento: " << pilha.getTamanho() << std::endl;
    pilha.imprimirPilha();
}

void testarFilaEncadeada() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: FILA ENCADEADA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    FilaEncadeada fila;
    
    std::cout << "\n1. Testando fila vazia:" << std::endl;
    std::cout << "Fila vazia? " << (fila.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << fila.getTamanho() << std::endl;
    
    std::cout << "\n2. Enfileirando elementos:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    
    fila.enfileirar(std::move(aluno1));
    fila.enfileirar(std::move(funcionario1));
    
    std::cout << "Tamanho após enfileiramentos: " << fila.getTamanho() << std::endl;
    fila.imprimirFila();
    
    std::cout << "\n3. Testando desenfileiramento:" << std::endl;
    auto desenfileirado = fila.desenfileirar();
    if (desenfileirado) {
        std::cout << "Elemento desenfileirado: ";
        desenfileirado->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após desenfileiramento: " << fila.getTamanho() << std::endl;
    fila.imprimirFila();
}

void testarDeque() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "TESTANDO ESTRUTURA: DEQUE" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    Deque deque;
    
    std::cout << "\n1. Testando deque vazio:" << std::endl;
    std::cout << "Deque vazio? " << (deque.estaVazio() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << deque.getTamanho() << std::endl;
    
    std::cout << "\n2. Adicionando elementos:" << std::endl;
    auto aluno1 = std::make_unique<Aluno>(1, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(2, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    
    deque.inserirInicio(std::move(aluno1));
    deque.inserirFim(std::move(funcionario1));
    
    std::cout << "Tamanho após adições: " << deque.getTamanho() << std::endl;
    deque.imprimirDeque();
    
    std::cout << "\n3. Removendo elementos:" << std::endl;
    auto removidoInicio = deque.removerInicio();
    if (removidoInicio) {
        std::cout << "Elemento removido do início: ";
        removidoInicio->imprimirInfo();
        std::cout << std::endl;
    }
    auto removidoFim = deque.removerFim();
    if (removidoFim) {
        std::cout << "Elemento removido do fim: ";
        removidoFim->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após remoções: " << deque.getTamanho() << std::endl;
    deque.imprimirDeque();
}

void compararEstruturas() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "COMPARAÇÃO DE ESTRUTURAS ENCADEADAS" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    std::cout << "\n📋 LISTA SIMPLESMENTE ENCADEADA:" << std::endl;
    std::cout << "✅ Vantagens:" << std::endl;
    std::cout << "   - Menor uso de memória (apenas um ponteiro por nó)" << std::endl;
    std::cout << "   - Inserção no início: O(1)" << std::endl;
    std::cout << "   - Inserção no fim: O(1) (com ponteiro cauda)" << std::endl;
    std::cout << "   - Estrutura mais simples" << std::endl;
    
    std::cout << "❌ Desvantagens:" << std::endl;
    std::cout << "   - Remoção do último: O(n) (precisa encontrar penúltimo)" << std::endl;
    std::cout << "   - Navegação apenas em uma direção" << std::endl;
    std::cout << "   - Remoção de nó específico: O(n)" << std::endl;
    
    std::cout << "\n📋 LISTA DUPLAMENTE ENCADEADA:" << std::endl;
    std::cout << "✅ Vantagens:" << std::endl;
    std::cout << "   - Navegação bidirecional" << std::endl;
    std::cout << "   - Remoção do último: O(1)" << std::endl;
    std::cout << "   - Remoção de nó específico: O(1) se tiver ponteiro para o nó" << std::endl;
    std::cout << "   - Inserção em qualquer posição mais eficiente" << std::endl;
    
    std::cout << "❌ Desvantagens:" << std::endl;
    std::cout << "   - Maior uso de memória (dois ponteiros por nó)" << std::endl;
    std::cout << "   - Estrutura mais complexa" << std::endl;
    std::cout << "   - Maior cuidado com ponteiros (anterior e próximo)" << std::endl;
    
    std::cout << "\n📋 LISTA DUPLAMENTE ENCADEADA CIRCULAR:" << std::endl;
    std::cout << "✅ Vantagens:" << std::endl;
    std::cout << "   - Todas as vantagens da lista dupla" << std::endl;
    std::cout << "   - Navegação circular infinita" << std::endl;
    std::cout << "   - Útil para algoritmos que precisam de acesso cíclico" << std::endl;
    std::cout << "   - Rotação eficiente" << std::endl;
    
    std::cout << "❌ Desvantagens:" << std::endl;
    std::cout << "   - Maior complexidade de implementação" << std::endl;
    std::cout << "   - Cuidado especial com loops infinitos" << std::endl;
    std::cout << "   - Destruição requer quebra manual do ciclo" << std::endl;
    
    std::cout << "\n🎯 QUANDO USAR CADA UMA:" << std::endl;
    std::cout << "📌 Simplesmente Encadeada: Quando só precisa inserir no início/fim" << std::endl;
    std::cout << "📌 Duplamente Encadeada: Quando precisa navegar nas duas direções" << std::endl;
    std::cout << "📌 Circular: Para algoritmos que precisam de acesso cíclico aos dados" << std::endl;
}

void demonstrarEncapsulamento() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "DEMONSTRAÇÃO DE ENCAPSULAMENTO - NÓS PRIVADOS" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    std::cout << "\n🔒 ENCAPSULAMENTO IMPLEMENTADO:" << std::endl;
    std::cout << "✅ Classes 'No' são PRIVADAS dentro de cada estrutura" << std::endl;
    std::cout << "✅ Usuário não pode acessar diretamente os nós" << std::endl;
    std::cout << "✅ Usuário não pode manipular ponteiros internos" << std::endl;
    std::cout << "✅ Interface pública expõe apenas métodos necessários" << std::endl;
    
    std::cout << "\n📝 EXEMPLO DE CÓDIGO QUE NÃO COMPILA:" << std::endl;
    std::cout << "   ListaSimplesmenteEncadeada lista;" << std::endl;
    std::cout << "   // lista.cabeca = ...;        // ❌ ERRO: membro privado" << std::endl;
    std::cout << "   // lista.No novoNo = ...;     // ❌ ERRO: classe privada" << std::endl;
    std::cout << "   // auto no = lista.cabeca;    // ❌ ERRO: acesso negado" << std::endl;
    
    std::cout << "\n✅ APENAS MÉTODOS PÚBLICOS SÃO ACESSÍVEIS:" << std::endl;
    std::cout << "   lista.inserirNoInicio(elemento);  // ✅ OK" << std::endl;
    std::cout << "   lista.buscarPeloId(id);           // ✅ OK" << std::endl;
    std::cout << "   lista.removerPeloId(id);          // ✅ OK" << std::endl;
    
    std::cout << "\n🎯 BENEFÍCIOS DO ENCAPSULAMENTO:" << std::endl;
    std::cout << "   - Proteção contra modificações inválidas" << std::endl;
    std::cout << "   - Manutenção da integridade da estrutura" << std::endl;
    std::cout << "   - Interface limpa e simples para o usuário" << std::endl;
    std::cout << "   - Facilita manutenção e evolução do código" << std::endl;
}

int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << std::string(70, '=') << std::endl;
    std::cout << "TESTE COMPLETO DAS ESTRUTURAS ENCADEADAS" << std::endl;
    std::cout << "Implementação com Nós Privados (Encapsulamento)" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    try {
        testarListaSimplesmenteEncadeada();
        testarListaDuplamenteEncadeada();
        testarListaDuplamenteEncadeadaCircular();
        testarPilhaEncadeada();
        testarFilaEncadeada();
        testarDeque();
        compararEstruturas();
        demonstrarEncapsulamento();
        
        std::cout << "\n" << std::string(70, '=') << std::endl;
        std::cout << "✅ CONCLUÍDA COM SUCESSO!" << std::endl;
        std::cout << "Todas as estruturas encadeadas implementadas e testadas!" << std::endl;
        std::cout << std::string(70, '=') << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Erro durante os testes: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
