#include "../src/estruturas_encadeadas/ArvoreBinariaBusca.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../src/elementos/Produto.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <memory>

void testarArvoreBinariaBusca() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "🌳 TESTANDO ESTRUTURA: ÁRVORE BINÁRIA DE BUSCA" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    ArvoreBinariaBusca arvore;
    
    std::cout << "\n1. 🌱 Testando árvore vazia:" << std::endl;
    std::cout << "Árvore vazia? " << (arvore.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho: " << arvore.getTamanho() << std::endl;
    std::cout << "Altura: " << arvore.calcularAltura() << std::endl;
    
    std::cout << "\n2. 🌿 Inserindo elementos (organização por ID):" << std::endl;
    
    // Inserir elementos em ordem não sequencial para testar a estrutura da árvore
    auto produto1 = std::make_unique<Produto>(50, "Notebook", "Eletrônicos", "Dell", 2500.0, 10);
    auto aluno1 = std::make_unique<Aluno>(30, "João Silva", "Computação", 8.5);
    auto funcionario1 = std::make_unique<Funcionario>(70, "Maria Santos", "Desenvolvedora", "TI", 6000.0);
    auto aluno2 = std::make_unique<Aluno>(20, "Ana Costa", "Engenharia", 9.0);
    auto produto2 = std::make_unique<Produto>(60, "Mouse", "Periféricos", "Logitech", 80.0, 50);
    auto funcionario2 = std::make_unique<Funcionario>(40, "Carlos Lima", "Gerente", "Vendas", 7500.0);
    auto aluno3 = std::make_unique<Aluno>(80, "Pedro Santos", "Física", 9.2);
    
    std::cout << "Inserindo: Produto (ID=50), Aluno (ID=30), Funcionário (ID=70)" << std::endl;
    std::cout << "           Aluno (ID=20), Produto (ID=60), Funcionário (ID=40), Aluno (ID=80)" << std::endl;
    
    arvore.inserir(std::move(produto1));
    arvore.inserir(std::move(aluno1));
    arvore.inserir(std::move(funcionario1));
    arvore.inserir(std::move(aluno2));
    arvore.inserir(std::move(produto2));
    arvore.inserir(std::move(funcionario2));
    arvore.inserir(std::move(aluno3));
    
    std::cout << "Tamanho após inserções: " << arvore.getTamanho() << std::endl;
    std::cout << "Altura da árvore: " << arvore.calcularAltura() << std::endl;
    
    std::cout << "\n3. 🔍 Testando busca por ID:" << std::endl;
    long idBusca = 40;
    Elemento* encontrado = arvore.buscarPeloId(idBusca);
    if (encontrado) {
        std::cout << "✅ Elemento encontrado (ID=" << idBusca << "): ";
        encontrado->imprimirInfo();
        std::cout << std::endl;
    } else {
        std::cout << "❌ Elemento não encontrado (ID=" << idBusca << ")" << std::endl;
    }
    
    // Buscar elemento inexistente
    idBusca = 999;
    encontrado = arvore.buscarPeloId(idBusca);
    if (encontrado) {
        std::cout << "✅ Elemento encontrado (ID=" << idBusca << ")" << std::endl;
    } else {
        std::cout << "❌ Elemento não encontrado (ID=" << idBusca << ") - Esperado!" << std::endl;
    }
    
    std::cout << "\n4. 🌳 Testando percursos da árvore:" << std::endl;
    
    std::cout << "\n4.1. 📊 Percurso Em Ordem (elementos ordenados por ID):" << std::endl;
    arvore.emOrdem();
    
    std::cout << "\n4.2. 🌱 Percurso Pré-Ordem (ordem de inserção/construção):" << std::endl;
    arvore.preOrdem();
    
    std::cout << "\n4.3. 🍂 Percurso Pós-Ordem (ordem de liberação):" << std::endl;
    arvore.posOrdem();
    
    std::cout << "\n5. 🔍 Testando elementos extremos:" << std::endl;
    Elemento* minimo = arvore.encontrarMinimo();
    Elemento* maximo = arvore.encontrarMaximo();
    
    if (minimo) {
        std::cout << "🔻 Menor elemento (ID=" << minimo->getID() << "): ";
        minimo->imprimirInfo();
        std::cout << std::endl;
    }
    
    if (maximo) {
        std::cout << "🔺 Maior elemento (ID=" << maximo->getID() << "): ";
        maximo->imprimirInfo();
        std::cout << std::endl;
    }
    
    std::cout << "\n6. ❌ Testando remoção de elementos:" << std::endl;
    
    // Remover nó folha
    std::cout << "6.1. Removendo nó folha (ID=20):" << std::endl;
    auto removido = arvore.removerPeloId(20);
    if (removido) {
        std::cout << "✅ Elemento removido: ";
        removido->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após remoção: " << arvore.getTamanho() << std::endl;
    
    // Remover nó com um filho
    std::cout << "\n6.2. Removendo nó com um filho (ID=70):" << std::endl;
    removido = arvore.removerPeloId(70);
    if (removido) {
        std::cout << "✅ Elemento removido: ";
        removido->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após remoção: " << arvore.getTamanho() << std::endl;
    
    // Remover nó com dois filhos (raiz)
    std::cout << "\n6.3. Removendo nó com dois filhos (ID=50 - raiz):" << std::endl;
    removido = arvore.removerPeloId(50);
    if (removido) {
        std::cout << "✅ Elemento removido: ";
        removido->imprimirInfo();
        std::cout << std::endl;
    }
    std::cout << "Tamanho após remoção: " << arvore.getTamanho() << std::endl;
    
    std::cout << "\n7. 🌳 Estado final da árvore:" << std::endl;
    std::cout << "Altura: " << arvore.calcularAltura() << " | Tamanho: " << arvore.getTamanho() << std::endl;
    arvore.emOrdem();
    
    std::cout << "\n✅ Teste da Árvore Binária de Busca concluído!" << std::endl;
}

void analisarComplexidades() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "📊 ANÁLISE DE COMPLEXIDADES DA ÁRVORE BINÁRIA DE BUSCA" << std::endl;
    std::cout << std::string(70, '=') << std::endl;
    
    std::cout << "\n🌳 ÁRVORE BINÁRIA DE BUSCA:" << std::endl;
    std::cout << "├─ inserir()        : O(log n) caso médio, O(n) pior caso" << std::endl;
    std::cout << "├─ buscarPeloId()   : O(log n) caso médio, O(n) pior caso" << std::endl;
    std::cout << "├─ removerPeloId()  : O(log n) caso médio, O(n) pior caso" << std::endl;
    std::cout << "├─ emOrdem()        : O(n) - visita todos os nós" << std::endl;
    std::cout << "├─ preOrdem()       : O(n) - visita todos os nós" << std::endl;
    std::cout << "├─ posOrdem()       : O(n) - visita todos os nós" << std::endl;
    std::cout << "├─ encontrarMinimo(): O(log n) caso médio, O(n) pior caso" << std::endl;
    std::cout << "├─ encontrarMaximo(): O(log n) caso médio, O(n) pior caso" << std::endl;
    std::cout << "├─ calcularAltura() : O(n) - percorre todos os nós" << std::endl;
    std::cout << "├─ estaVazia()      : O(1) - verificação direta" << std::endl;
    std::cout << "└─ getTamanho()     : O(1) - acesso direto" << std::endl;
    
    std::cout << "\n🎯 CARACTERÍSTICAS DA ABB:" << std::endl;
    std::cout << "✅ Organização automática por ID" << std::endl;
    std::cout << "✅ Percurso em ordem produz lista ordenada" << std::endl;
    std::cout << "✅ Busca eficiente em árvores balanceadas" << std::endl;
    std::cout << "✅ Nós privados garantem encapsulamento" << std::endl;
    std::cout << "⚠️  Performance degrada em árvores desbalanceadas" << std::endl;
    
    std::cout << "\n🔍 COMPARAÇÃO COM OUTRAS ESTRUTURAS:" << std::endl;
    std::cout << "📊 Lista Não Ordenada: Busca O(n), Inserção O(1)" << std::endl;
    std::cout << "📊 Lista Ordenada:     Busca O(log n), Inserção O(n)" << std::endl;
    std::cout << "📊 ABB Balanceada:     Busca O(log n), Inserção O(log n)" << std::endl;
    std::cout << "📊 ABB Desbalanceada:  Busca O(n), Inserção O(n)" << std::endl;
}

int main() {
    CONFIGURAR_PORTUGUES();
    
    std::cout << "======================================================================" << std::endl;
    std::cout << "🎯 TESTE DA ÁRVORE BINÁRIA DE BUSCA" << std::endl;
    std::cout << "Implementação com Nós Privados e Organização por ID" << std::endl;
    std::cout << "======================================================================" << std::endl;
    
    try {
        testarArvoreBinariaBusca();
        analisarComplexidades();
        
        std::cout << "\n" << std::string(70, '=') << std::endl;
        std::cout << "✅ CONCLUÍDA COM SUCESSO!" << std::endl;
        std::cout << "Árvore Binária de Busca implementada e testada!" << std::endl;
        std::cout << "🔒 Encapsulamento: Nós são privados" << std::endl;
        std::cout << "🎯 Organização: Elementos ordenados por ID" << std::endl;
        std::cout << "⚡ Eficiência: O(log n) para operações principais" << std::endl;
        std::cout << std::string(70, '=') << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Erro durante os testes: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
