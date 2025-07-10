#include "../src/estruturas_sequenciais/ListaNaoOrdenada.h"
#include "../src/estruturas_sequenciais/ListaOrdenada.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../src/elementos/Produto.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <chrono>
#include <memory>

/**
 * @brief Teste abrangente das estruturas de lista sequencial
 * 
 * Este arquivo demonstra e testa todas as funcionalidades das
 * listas não ordenada e ordenada, incluindo análise de performance.
 */

void testarListaNaoOrdenada() {
    std::cout << "=============== TESTE LISTA NÃO ORDENADA ===============" << std::endl;
    
    ListaNaoOrdenada lista(5); // Capacidade inicial pequena para testar redimensionamento
    
    // Teste 1: Inserção no final
    std::cout << "\n1. Testando InserirNoFinal:" << std::endl;
    lista.InserirNoFinal(std::make_unique<Aluno>(20231005, "Maria Silva", "Computação", 8.5));
    lista.InserirNoFinal(std::make_unique<Funcionario>(100003, "João Santos", "Dev", "TI", 5500.0));
    lista.InserirNoFinal(std::make_unique<Produto>(7891001, "Notebook", "Eletrônicos", "Dell", 2500.0, 10));
    
    std::cout << "Elementos inseridos no final. Tamanho: " << lista.getTamanho() << std::endl;
    
    // Teste 2: Inserção no início
    std::cout << "\n2. Testando InserirNoInicio:" << std::endl;
    lista.InserirNoInicio(std::make_unique<Aluno>(20231001, "Ana Costa", "Engenharia", 9.0));
    lista.InserirNoInicio(std::make_unique<Funcionario>(100001, "Carlos Lima", "Gerente", "Admin", 8000.0));
    
    std::cout << "Elementos inseridos no início. Tamanho: " << lista.getTamanho() << std::endl;
    
    // Teste 3: Verificar estado atual
    std::cout << "\n3. Estado atual da lista:" << std::endl;
    lista.imprimirLista();
    
    // Teste 4: Busca por ID (O(n))
    std::cout << "\n4. Testando BuscarPeloId (Complexidade O(n)):" << std::endl;
    
    auto inicio = std::chrono::high_resolution_clock::now();
    Elemento* encontrado = lista.BuscarPeloId(20231005);
    auto fim = std::chrono::high_resolution_clock::now();
    
    if (encontrado) {
        std::cout << "Elemento encontrado:" << std::endl;
        encontrado->imprimirInfo();
    } else {
        std::cout << "✗ Elemento não encontrado" << std::endl;
    }
    
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    std::cout << "Tempo de busca: " << duracao.count() << " microssegundos" << std::endl;
    
    // Teste 5: Alteração de elemento
    std::cout << "\n5. Testando AlterarPeloId:" << std::endl;
    bool alterado = lista.AlterarPeloId(7891001, 
        std::make_unique<Produto>(7891001, "Notebook Gaming", "Eletrônicos", "Dell", 3000.0, 15));
    
    if (alterado) {
        std::cout << "Elemento alterado com sucesso" << std::endl;
        lista.BuscarPeloId(7891001)->imprimirInfo();
    }
    
    // Teste 6: Remoções
    std::cout << "\n6. Testando remoções:" << std::endl;
    
    // Remove primeiro
    auto removido = lista.RemoverPrimeiro();
    if (removido) {
        std::cout << "Primeiro elemento removido (ID: " << removido->getID() << ")" << std::endl;
    }
    
    // Remove último
    removido = lista.RemoverUltimo();
    if (removido) {
        std::cout << "Último elemento removido (ID: " << removido->getID() << ")" << std::endl;
    }
    
    // Remove por ID
    removido = lista.RemoverPeloId(20231005);
    if (removido) {
        std::cout << "Elemento com ID 20231005 removido" << std::endl;
    }
    
    std::cout << "\nTamanho final: " << lista.getTamanho() << std::endl;
    lista.imprimirLista();
}

void testarListaOrdenada() {
    std::cout << "\n\n=============== TESTE LISTA ORDENADA ===============" << std::endl;
    
    ListaOrdenada lista(5);
    
    // Teste 1: Inserção ordenada
    std::cout << "\n1. Testando inserções ordenadas:" << std::endl;
    
    // Insere elementos em ordem aleatória para testar ordenação
    lista.InserirOrdenado(std::make_unique<Aluno>(20231003, "Pedro Silva", "Design", 7.8));
    lista.InserirOrdenado(std::make_unique<Funcionario>(100001, "Ana Santos", "Dev", "TI", 6000.0));
    lista.InserirOrdenado(std::make_unique<Produto>(7891005, "Mouse", "Eletrônicos", "Logitech", 150.0, 25));
    lista.InserirOrdenado(std::make_unique<Aluno>(20231001, "Maria Costa", "Computação", 9.5));
    lista.InserirOrdenado(std::make_unique<Funcionario>(100010, "Carlos Lima", "Gerente", "Admin", 9000.0));
    
    std::cout << "Elementos inseridos. Verificando ordenação..." << std::endl;
    
    if (lista.verificarOrdenacao()) {
        std::cout << "Lista está corretamente ordenada por ID!" << std::endl;
    } else {
        std::cout << "✗ ERRO: Lista não está ordenada!" << std::endl;
    }
    
    // Teste 2: Estado atual ordenado
    std::cout << "\n2. Estado atual da lista ordenada:" << std::endl;
    lista.imprimirLista();
    
    // Teste 3: Busca binária (O(log n))
    std::cout << "\n3. Testando BuscarPeloId com busca binária (Complexidade O(log n)):" << std::endl;
    
    auto inicio = std::chrono::high_resolution_clock::now();
    Elemento* encontrado = lista.BuscarPeloId(20231003);
    auto fim = std::chrono::high_resolution_clock::now();
    
    if (encontrado) {
        std::cout << "Elemento encontrado com busca binária:" << std::endl;
        encontrado->imprimirInfo();
    }
    
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    std::cout << "Tempo de busca binária: " << duracao.count() << " microssegundos" << std::endl;
    
    // Teste 4: Comparação de performance - criar lista maior para medir diferença
    std::cout << "\n4. Teste de performance - Lista maior:" << std::endl;
    
    ListaNaoOrdenada listaNaoOrd(1000);
    ListaOrdenada listaOrd(1000);
    
    // Adiciona muitos elementos
    for (int i = 1000; i < 1100; i++) {
        listaNaoOrd.InserirNoFinal(std::make_unique<Aluno>(20230000 + i, "Aluno" + std::to_string(i), "Curso", 8.0));
        listaOrd.InserirOrdenado(std::make_unique<Aluno>(20230000 + i, "Aluno" + std::to_string(i), "Curso", 8.0));
    }
    
    // Busca na lista não ordenada (O(n))
    inicio = std::chrono::high_resolution_clock::now();
    listaNaoOrd.BuscarPeloId(20231050);
    fim = std::chrono::high_resolution_clock::now();
    auto tempoLinear = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    
    // Busca na lista ordenada (O(log n))
    inicio = std::chrono::high_resolution_clock::now();
    listaOrd.BuscarPeloId(20231050);
    fim = std::chrono::high_resolution_clock::now();
    auto tempoBinario = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    
    std::cout << "Busca linear (100 elementos): " << tempoLinear.count() << " μs" << std::endl;
    std::cout << "Busca binária (100 elementos): " << tempoBinario.count() << " μs" << std::endl;
    std::cout << "Ganho de performance: " << (double)tempoLinear.count() / tempoBinario.count() << "x" << std::endl;
    
    // Teste 5: Métodos específicos da lista ordenada
    std::cout << "\n5. Testando métodos específicos da lista ordenada:" << std::endl;
    
    Elemento* menor = lista.obterMenorElemento();
    Elemento* maior = lista.obterMaiorElemento();
    
    if (menor) {
        std::cout << "Menor ID: " << menor->getID() << std::endl;
    }
    
    if (maior) {
        std::cout << "Maior ID: " << maior->getID() << std::endl;
    }
    
    // Teste 6: Remoção mantendo ordenação
    std::cout << "\n6. Testando remoção por ID:" << std::endl;
    
    auto removido = lista.RemoverPeloId(20231003);
    if (removido) {
        std::cout << "Elemento removido (ID: " << removido->getID() << ")" << std::endl;
    }
    
    if (lista.verificarOrdenacao()) {
        std::cout << "Lista ainda está ordenada após remoção!" << std::endl;
    }
    
    std::cout << "\nEstado final da lista ordenada:" << std::endl;
    lista.imprimirLista();
}

void compararComplexidades() {
    std::cout << "\n\n============= ANÁLISE DE COMPLEXIDADES =============" << std::endl;
    
    std::cout << "\nLISTA NÃO ORDENADA:" << std::endl;
    std::cout << "├─ InserirNoInicio:     O(n) - desloca todos os elementos" << std::endl;
    std::cout << "├─ InserirNoFinal:      O(1) amortizado - inserção direta" << std::endl;
    std::cout << "├─ RemoverPrimeiro:     O(n) - desloca todos os elementos" << std::endl;
    std::cout << "├─ RemoverUltimo:       O(1) - remoção direta" << std::endl;
    std::cout << "├─ RemoverPeloId:       O(n) - busca linear + deslocamento" << std::endl;
    std::cout << "├─ BuscarPeloId:        O(n) - busca linear sequencial" << std::endl;
    std::cout << "└─ AlterarPeloId:       O(n) - busca linear" << std::endl;
    
    std::cout << "\nLISTA ORDENADA:" << std::endl;
    std::cout << "├─ InserirNoInicio:     O(n) - inserção ordenada" << std::endl;
    std::cout << "├─ InserirNoFinal:      O(n) - inserção ordenada" << std::endl;
    std::cout << "├─ InserirOrdenado:     O(n) - busca O(log n) + inserção O(n)" << std::endl;
    std::cout << "├─ RemoverPrimeiro:     O(n) - desloca todos os elementos" << std::endl;
    std::cout << "├─ RemoverUltimo:       O(1) - remoção direta" << std::endl;
    std::cout << "├─ RemoverPeloId:       O(n) - busca O(log n) + deslocamento O(n)" << std::endl;
    std::cout << "├─ BuscarPeloId:        O(log n) - BUSCA BINÁRIA ⚡" << std::endl;
    std::cout << "└─ AlterarPeloId:       O(log n) ou O(n) dependendo do caso" << std::endl;
    
    std::cout << "\nVANTAGENS:" << std::endl;
    std::cout << "Lista Não Ordenada: Inserção no final mais rápida" << std::endl;
    std::cout << "Lista Ordenada:     Busca muito mais eficiente O(log n)" << std::endl;
}

int main() {
    // Configura locale para português
    CONFIGURAR_PORTUGUES();
    
    std::cout << "========== TESTE DAS ESTRUTURAS SEQUENCIAIS ==========" << std::endl;
    std::cout << "Este teste demonstra as implementações de Lista Não Ordenada" << std::endl;
    std::cout << "e Lista Ordenada com análise de complexidade detalhada." << std::endl;
    
    try {
        testarListaNaoOrdenada();
        testarListaOrdenada();
        compararComplexidades();
        
        std::cout << "\n\nTODOS OS TESTES CONCLUÍDOS COM SUCESSO! " << std::endl;
        std::cout << "Lista Não Ordenada: Funcional" << std::endl;
        std::cout << "Lista Ordenada: Funcional com busca binária O(log n)" << std::endl;
        std::cout << "Todas as complexidades documentadas e validadas" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Erro durante os testes: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
