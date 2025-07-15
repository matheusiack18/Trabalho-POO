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


void imprimirSeparador(const std::string& titulo) {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "🎯 " << titulo << std::endl;
    std::cout << std::string(70, '=') << std::endl;
}

void imprimirSubsecao(const std::string& titulo) {
    std::cout << "\n" << std::string(50, '-') << std::endl;
    std::cout << "📋 " << titulo << std::endl;
    std::cout << std::string(50, '-') << std::endl;
}

// PARTE 1: TESTAR ESTRUTURAS SEQUENCIAIS
void testarEstruturasSequenciais() {
    imprimirSeparador("PARTE 1: ESTRUTURAS SEQUENCIAIS");
    
    // Criando instâncias de diferentes classes
    std::cout << "\n1. 🏗️ Criando instâncias de diferentes classes:" << std::endl;
    
    auto aluno1 = std::make_unique<Aluno>(20231001, "Ana Silva", "Computação", 9.2);
    auto aluno2 = std::make_unique<Aluno>(20231002, "João Santos", "Engenharia", 8.7);
    auto funcionario1 = std::make_unique<Funcionario>(100001, "Maria Lima", "Desenvolvedora", "TI", 7500.0);
    auto funcionario2 = std::make_unique<Funcionario>(100002, "Carlos Costa", "Gerente", "Vendas", 9000.0);
    auto produto1 = std::make_unique<Produto>(7891001, "Notebook", "Eletrônicos", "Dell", 3500.0, 12);
    auto produto2 = std::make_unique<Produto>(7891002, "Mouse", "Periféricos", "Logitech", 120.0, 45);
    
    std::cout << "✅ Criadas 6 instâncias: 2 Alunos, 2 Funcionários, 2 Produtos" << std::endl;
    
    imprimirSubsecao("TESTANDO LISTA NÃO ORDENADA");
    
    ListaNaoOrdenada lista(10);
    
    std::cout << "\n2. 📥 Adicionando elementos à Lista Não Ordenada:" << std::endl;
    lista.InserirNoFinal(std::move(aluno1));
    lista.InserirNoFinal(std::move(funcionario1));
    lista.InserirNoFinal(std::move(produto1));
    lista.InserirNoFinal(std::move(aluno2));
    lista.InserirNoFinal(std::move(funcionario2));
    lista.InserirNoFinal(std::move(produto2));
    
    std::cout << "✅ Elementos adicionados. Tamanho: " << lista.getTamanho() << std::endl;
    
    std::cout << "\n3. 🎭 Demonstrando polimorfismo com imprimirInfo():" << std::endl;
    std::cout << "Cada elemento chama sua própria implementação de imprimirInfo()" << std::endl;
    lista.imprimirLista();
    
    std::cout << "\n4. 🔍 Testando busca por ID:" << std::endl;
    int idBusca = 100001;
    Elemento* encontrado = lista.BuscarPeloId(idBusca);
    if (encontrado) {
        std::cout << "✅ Funcionário encontrado (ID=" << idBusca << "):" << std::endl;
        encontrado->imprimirInfo();
    } else {
        std::cout << "❌ Elemento não encontrado" << std::endl;
    }
    
    std::cout << "\n5. ✏️ Testando alteração de elemento:" << std::endl;
    auto novoAluno = std::make_unique<Aluno>(20231001, "Ana Silva Souza", "Ciência da Computação", 9.5);
    bool alterado = lista.AlterarPeloId(20231001, std::move(novoAluno));
    if (alterado) {
        std::cout << "✅ Aluno alterado com sucesso!" << std::endl;
        lista.BuscarPeloId(20231001)->imprimirInfo();
    }
    
    imprimirSubsecao("TESTANDO LISTA ORDENADA");
    
    ListaOrdenada listaOrdenada(8);
    
    std::cout << "\n6. 📊 Testando Lista Ordenada (inserção automática por ID):" << std::endl;
    
    // Criando novos elementos para lista ordenada
    auto alunoOrd1 = std::make_unique<Aluno>(20231005, "Pedro Oliveira", "Física", 8.9);
    auto funcOrd1 = std::make_unique<Funcionario>(100005, "Sofia Rodriguez", "Analista", "RH", 6500.0);
    auto prodOrd1 = std::make_unique<Produto>(7891005, "Teclado", "Periféricos", "Microsoft", 250.0, 30);
    auto alunoOrd2 = std::make_unique<Aluno>(20231003, "Laura Costa", "Matemática", 9.1);
    
    listaOrdenada.InserirOrdenado(std::move(funcOrd1));
    listaOrdenada.InserirOrdenado(std::move(alunoOrd1));
    listaOrdenada.InserirOrdenado(std::move(prodOrd1));
    listaOrdenada.InserirOrdenado(std::move(alunoOrd2));
    
    std::cout << "✅ Elementos inseridos em ordem automática por ID:" << std::endl;
    listaOrdenada.imprimirLista();
    
    std::cout << "\n7. ⚡ Demonstrando busca binária O(log n):" << std::endl;
    encontrado = listaOrdenada.BuscarPeloId(7891005);
    if (encontrado) {
        std::cout << "✅ Produto encontrado com busca binária:" << std::endl;
        encontrado->imprimirInfo();
    }
    
    imprimirSubsecao("TESTANDO PILHA E FILA");
    
    std::cout << "\n8. 📚 Testando Pilha (LIFO):" << std::endl;
    Pilha pilha(5);
    
    auto elemPilha1 = std::make_unique<Aluno>(30001, "Gabriel Lima", "Design", 8.3);
    auto elemPilha2 = std::make_unique<Funcionario>(200001, "Isabela Santos", "Designer", "Marketing", 5800.0);
    auto elemPilha3 = std::make_unique<Produto>(9001, "Tablet", "Eletrônicos", "Samsung", 1200.0, 8);
    
    pilha.empilhar(std::move(elemPilha1));
    pilha.empilhar(std::move(elemPilha2));
    pilha.empilhar(std::move(elemPilha3));
    
    std::cout << "✅ Elementos empilhados. Consultando topo:" << std::endl;
    Elemento* topo = pilha.consultarTopo();
    if (topo) {
        topo->imprimirInfo();
    }
    
    std::cout << "\n9. 🚶 Testando Fila Otimizada (FIFO):" << std::endl;
    FilaOtimizada fila(4);
    
    auto elemFila1 = std::make_unique<Aluno>(30002, "Rafael Alves", "Química", 9.0);
    auto elemFila2 = std::make_unique<Funcionario>(200002, "Camila Ferreira", "Química", "P&D", 8200.0);
    
    fila.enfileirar(std::move(elemFila1));
    fila.enfileirar(std::move(elemFila2));
    
    std::cout << "✅ Elementos enfileirados. Consultando frente:" << std::endl;
    Elemento* frente = fila.consultarFrente();
    if (frente) {
        frente->imprimirInfo();
    }
    
    std::cout << "\n✅ Teste das estruturas sequenciais concluído!" << std::endl;
}

// PARTE 2: TESTAR ESTRUTURAS ENCADEADAS
void testarEstruturasEncadeadas() {
    imprimirSeparador("PARTE 2: ESTRUTURAS ENCADEADAS");
    
    imprimirSubsecao("TESTANDO LISTA SIMPLESMENTE ENCADEADA");
    
    ListaSimplesmenteEncadeada listaSE;
    
    std::cout << "\n1. 🔗 Testando Lista Simplesmente Encadeada:" << std::endl;
    
    auto elemSE1 = std::make_unique<Aluno>(40001, "Marcos Silva", "Biologia", 8.6);
    auto elemSE2 = std::make_unique<Funcionario>(300001, "Fernanda Lima", "Bióloga", "Pesquisa", 7200.0);
    auto elemSE3 = std::make_unique<Produto>(8001, "Microscópio", "Científicos", "Zeiss", 5500.0, 2);
    
    listaSE.inserirNoInicio(std::move(elemSE1));
    listaSE.inserirNoFim(std::move(elemSE2));
    listaSE.inserirNoFim(std::move(elemSE3));
    
    std::cout << "✅ Inserções realizadas. Estado da lista:" << std::endl;
    listaSE.imprimirLista();
    
    std::cout << "\n2. 🔍 Testando busca na lista encadeada:" << std::endl;
    Elemento* encontradoSE = listaSE.buscarPeloId(300001);
    if (encontradoSE) {
        std::cout << "✅ Funcionária encontrada:" << std::endl;
        encontradoSE->imprimirInfo();
    }
    
    std::cout << "\n3. ❌ Testando remoção na lista encadeada:" << std::endl;
    std::unique_ptr<Elemento> removidoSE(listaSE.removerPeloId(40001));
    if (removidoSE) {
        std::cout << "✅ Elemento removido:" << std::endl;
        removidoSE->imprimirInfo();
    }
    
    imprimirSubsecao("TESTANDO LISTA DUPLAMENTE ENCADEADA");
    
    ListaDuplamenteEncadeada listaDE;
    
    std::cout << "\n4. ↔️ Testando Lista Duplamente Encadeada:" << std::endl;
    
    auto elemDE1 = std::make_unique<Aluno>(40002, "Beatriz Santos", "História", 9.3);
    auto elemDE2 = std::make_unique<Funcionario>(300002, "Ricardo Oliveira", "Historiador", "Educação", 6800.0);
    auto elemDE3 = std::make_unique<Produto>(8002, "Livro", "Educacionais", "Pearson", 180.0, 25);
    
    listaDE.inserirNoInicio(std::move(elemDE2));
    listaDE.inserirNoFim(std::move(elemDE1));
    listaDE.inserirNoFim(std::move(elemDE3));
    
    std::cout << "✅ Elementos inseridos. Navegação normal:" << std::endl;
    listaDE.imprimirLista();
    
    std::cout << "\n5. 🔄 Demonstrando navegação reversa:" << std::endl;
    listaDE.imprimirListaReversa();
    
    imprimirSubsecao("TESTANDO ADAPTADORES ENCADEADOS");
    
    std::cout << "\n6. 📚 Testando Pilha Encadeada:" << std::endl;
    PilhaEncadeada pilhaEnc;
    
    auto elemPE1 = std::make_unique<Produto>(8003, "Calculadora", "Escritório", "Casio", 45.0, 15);
    auto elemPE2 = std::make_unique<Aluno>(40003, "Diego Costa", "Matemática", 8.8);
    
    pilhaEnc.empilhar(std::move(elemPE1));
    pilhaEnc.empilhar(std::move(elemPE2));
    
    std::cout << "✅ Elementos empilhados. Topo atual:" << std::endl;
    Elemento* topoPE = pilhaEnc.topo();
    if (topoPE) {
        topoPE->imprimirInfo();
    }
    
    std::cout << "\n7. 🚶 Testando Fila Encadeada:" << std::endl;
    FilaEncadeada filaEnc;
    
    auto elemFE1 = std::make_unique<Funcionario>(300003, "Juliana Alves", "Contadora", "Financeiro", 7800.0);
    auto elemFE2 = std::make_unique<Produto>(8004, "Impressora", "Escritório", "Canon", 800.0, 5);
    
    filaEnc.enfileirar(std::move(elemFE1));
    filaEnc.enfileirar(std::move(elemFE2));
    
    std::cout << "✅ Elementos enfileirados. Frente atual:" << std::endl;
    Elemento* frenteFE = filaEnc.frente();
    if (frenteFE) {
        frenteFE->imprimirInfo();
    }
    
    std::cout << "\n8. ↔️ Testando Deque (Double-ended queue):" << std::endl;
    Deque deque;
    
    auto elemDeque1 = std::make_unique<Aluno>(40004, "Larissa Lima", "Psicologia", 9.1);
    auto elemDeque2 = std::make_unique<Funcionario>(300004, "Paulo Santos", "Psicólogo", "RH", 6900.0);
    
    deque.inserirInicio(std::move(elemDeque1));
    deque.inserirFim(std::move(elemDeque2));
    
    std::cout << "✅ Elementos inseridos no deque:" << std::endl;
    deque.imprimirDeque();
    
    std::cout << "\n✅ Teste das estruturas encadeadas concluído!" << std::endl;
}

// PARTE 3: TESTAR ÁRVORE BINÁRIA DE BUSCA
void testarArvoreBinariaBusca() {
    imprimirSeparador("DEMONSTRAÇÃO: ÁRVORE BINÁRIA DE BUSCA");
    
    ArvoreBinariaBusca arvore;
    
    std::cout << "\n1. 🌳 Testando Árvore Binária de Busca:" << std::endl;
    std::cout << "A ABB organiza automaticamente os elementos por ID" << std::endl;
    
    auto arvElem1 = std::make_unique<Produto>(50, "Servidor", "TI", "HP", 15000.0, 1);
    auto arvElem2 = std::make_unique<Aluno>(25, "Vítor Lima", "Redes", 8.9);
    auto arvElem3 = std::make_unique<Funcionario>(75, "Amanda Silva", "Administradora", "TI", 8500.0);
    auto arvElem4 = std::make_unique<Aluno>(15, "Carla Santos", "Sistemas", 9.4);
    auto arvElem5 = std::make_unique<Produto>(65, "Switch", "TI", "Cisco", 1200.0, 3);
    auto arvElem6 = std::make_unique<Funcionario>(35, "Bruno Costa", "Técnico", "Suporte", 4500.0);
    auto arvElem7 = std::make_unique<Aluno>(85, "Marina Oliveira", "Segurança", 8.7);
    
    std::cout << "\n2. 🌿 Inserindo elementos (IDs: 50, 25, 75, 15, 65, 35, 85):" << std::endl;
    arvore.inserir(std::move(arvElem1));
    arvore.inserir(std::move(arvElem2));
    arvore.inserir(std::move(arvElem3));
    arvore.inserir(std::move(arvElem4));
    arvore.inserir(std::move(arvElem5));
    arvore.inserir(std::move(arvElem6));
    arvore.inserir(std::move(arvElem7));
    
    std::cout << "✅ Árvore construída! Tamanho: " << arvore.getTamanho() 
              << " | Altura: " << arvore.calcularAltura() << std::endl;
    
    std::cout << "\n3. 📊 Percurso Em Ordem (elementos em ordem crescente por ID):" << std::endl;
    arvore.emOrdem();
    
    std::cout << "\n4. 🔍 Testando busca eficiente O(log n):" << std::endl;
    Elemento* encontradoArv = arvore.buscarPeloId(35);
    if (encontradoArv) {
        std::cout << "✅ Funcionário encontrado rapidamente:" << std::endl;
        encontradoArv->imprimirInfo();
    }
    
    std::cout << "\n5. 🔻🔺 Testando extremos da árvore:" << std::endl;
    Elemento* minimo = arvore.encontrarMinimo();
    Elemento* maximo = arvore.encontrarMaximo();
    
    if (minimo) {
        std::cout << "🔻 Menor elemento (ID=" << minimo->getID() << "):" << std::endl;
        minimo->imprimirInfo();
    }
    if (maximo) {
        std::cout << "🔺 Maior elemento (ID=" << maximo->getID() << "):" << std::endl;
        maximo->imprimirInfo();
    }
    
    std::cout << "\n6. ❌ Testando remoção (mantém estrutura da árvore):" << std::endl;
    std::unique_ptr<Elemento> removidoArv(arvore.removerPeloId(25));
    if (removidoArv) {
        std::cout << "✅ Elemento removido com sucesso!" << std::endl;
        removidoArv->imprimirInfo();
        std::cout << "Tamanho após remoção: " << arvore.getTamanho() << std::endl;
    }
    
    std::cout << "\n7. 📊 Estado final da árvore (ainda ordenada):" << std::endl;
    arvore.emOrdem();
    
    std::cout << "\n✅ Teste da Árvore Binária de Busca concluído!" << std::endl;
}

// PARTE 4: DEMONSTRAÇÃO DE ENCAPSULAMENTO
void demonstrarEncapsulamento() {
    imprimirSeparador("DEMONSTRAÇÃO: ENCAPSULAMENTO");
    
    std::cout << "\n🔒 Demonstrando que apenas métodos públicos são acessíveis:" << std::endl;
    std::cout << "Este main.cpp usa APENAS a interface pública das classes." << std::endl;
    
    std::cout << "\n1. ✅ Acesso permitido - métodos públicos:" << std::endl;
    
    ListaNaoOrdenada lista(5);
    ArvoreBinariaBusca arvore;
    auto aluno = std::make_unique<Aluno>(12345, "Teste", "Curso", 8.0);
    
    std::cout << "   • lista.getTamanho(): " << lista.getTamanho() << std::endl;
    std::cout << "   • arvore.estaVazia(): " << (arvore.estaVazia() ? "Sim" : "Não") << std::endl;
    std::cout << "   • aluno->getID(): " << aluno->getID() << std::endl;
    std::cout << "   • aluno->getNome(): " << aluno->getNome() << std::endl;
    
    std::cout << "\n2. ❌ Acesso negado - tentativas comentadas:" << std::endl;
    std::cout << "   As linhas abaixo causariam ERRO DE COMPILAÇÃO:" << std::endl;
    std::cout << "   // lista.elementos[0];           // ❌ Atributo privado" << std::endl;
    std::cout << "   // arvore.raiz;                  // ❌ Atributo privado" << std::endl;
    std::cout << "   // aluno.ID = 999;               // ❌ Atributo protegido" << std::endl;
    std::cout << "   // new ArvoreBinariaBusca::No(); // ❌ Classe No é privada" << std::endl;
    
    std::cout << "\n✅ Encapsulamento funcionando corretamente!" << std::endl;
    std::cout << "Apenas a interface pública está acessível ao usuário." << std::endl;
}

// DEMONSTRAÇÃO FINAL INTEGRADA
void demonstracaoIntegrada() {
    imprimirSeparador("DEMONSTRAÇÃO FINAL: INTEGRAÇÃO COMPLETA");
    
    std::cout << "\n🎯 Demonstração usando polimorfismo com todas as estruturas:" << std::endl;
    
    std::cout << "\n1. 📋 Testando em Lista Sequencial:" << std::endl;
    ListaOrdenada listaIntegrada(10);
    
    // Criar elementos para testar polimorfismo
    auto elemTeste1 = std::make_unique<Aluno>(1, "Alice", "IA", 9.8);
    auto elemTeste2 = std::make_unique<Funcionario>(2, "Bob", "Dev", "TI", 8000);
    auto elemTeste3 = std::make_unique<Produto>(3, "Chip", "Hardware", "Intel", 300, 100);
    auto elemTeste4 = std::make_unique<Aluno>(4, "Carol", "ML", 9.5);
    auto elemTeste5 = std::make_unique<Funcionario>(5, "Dave", "Analista", "Dados", 7500);
    
    listaIntegrada.InserirOrdenado(std::move(elemTeste1));
    listaIntegrada.InserirOrdenado(std::move(elemTeste2));
    listaIntegrada.InserirOrdenado(std::move(elemTeste3));
    listaIntegrada.InserirOrdenado(std::move(elemTeste4));
    listaIntegrada.InserirOrdenado(std::move(elemTeste5));
    
    std::cout << "✅ Elementos inseridos automaticamente em ordem por ID:" << std::endl;
    listaIntegrada.imprimirLista();
    
    std::cout << "\n2. 🔗 Testando em Lista Encadeada:" << std::endl;
    ListaDuplamenteEncadeada listaEncIntegrada;
    
    // Criar novos elementos para a lista encadeada
    auto elemEnc1 = std::make_unique<Aluno>(10, "Elena", "IA", 9.8);
    auto elemEnc2 = std::make_unique<Funcionario>(20, "Frank", "Dev", "TI", 8000);
    auto elemEnc3 = std::make_unique<Produto>(30, "GPU", "Hardware", "NVIDIA", 1500, 20);
    auto elemEnc4 = std::make_unique<Aluno>(40, "Grace", "ML", 9.5);
    auto elemEnc5 = std::make_unique<Funcionario>(50, "Henry", "Analista", "Dados", 7500);
    
    listaEncIntegrada.inserirNoFim(std::move(elemEnc1));
    listaEncIntegrada.inserirNoFim(std::move(elemEnc2));
    listaEncIntegrada.inserirNoFim(std::move(elemEnc3));
    listaEncIntegrada.inserirNoFim(std::move(elemEnc4));
    listaEncIntegrada.inserirNoFim(std::move(elemEnc5));
    
    std::cout << "✅ Mesmos tipos de elementos na lista duplamente encadeada:" << std::endl;
    listaEncIntegrada.imprimirLista();
    
    std::cout << "\n3. 🌳 Testando em Árvore Binária:" << std::endl;
    ArvoreBinariaBusca arvoreIntegrada;
    
    // Criar elementos para a árvore
    auto elemArv1 = std::make_unique<Aluno>(15, "Ivy", "IA", 9.8);
    auto elemArv2 = std::make_unique<Funcionario>(25, "Jack", "Dev", "TI", 8000);
    auto elemArv3 = std::make_unique<Produto>(35, "CPU", "Hardware", "AMD", 800, 50);
    auto elemArv4 = std::make_unique<Aluno>(45, "Kate", "ML", 9.5);
    auto elemArv5 = std::make_unique<Funcionario>(55, "Luke", "Analista", "Dados", 7500);
    
    arvoreIntegrada.inserir(std::move(elemArv1));
    arvoreIntegrada.inserir(std::move(elemArv2));
    arvoreIntegrada.inserir(std::move(elemArv3));
    arvoreIntegrada.inserir(std::move(elemArv4));
    arvoreIntegrada.inserir(std::move(elemArv5));
    
    std::cout << "✅ Mesmos tipos de elementos organizados hierarquicamente:" << std::endl;
    arvoreIntegrada.emOrdem();
    
    std::cout << "\n🎉 RESULTADO:" << std::endl;
    std::cout << "• Lista Ordenada: Busca O(log n), Inserção O(n)" << std::endl;
    std::cout << "• Lista Encadeada: Busca O(n), Inserção O(1)" << std::endl;
    std::cout << "• Árvore Binária: Busca O(log n), Inserção O(log n)" << std::endl;
    std::cout << "• Polimorfismo: Cada elemento usa sua própria imprimirInfo()" << std::endl;
    
    std::cout << "\n✅ Demonstração integrada concluída!" << std::endl;
}
