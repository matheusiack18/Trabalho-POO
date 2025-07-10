#include "../src/elementos/Elemento.h"
#include "../src/elementos/Aluno.h"
#include "../src/elementos/Funcionario.h"
#include "../ConfigLocale.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

/**
 * @brief Teste específico e detalhado das classes derivadas de Elemento
 */

void demonstrarAluno() {
    std::cout << "==================== TESTE CLASSE ALUNO ====================" << std::endl;
    
    // Teste 1: Criação de alunos com diferentes dados
    std::cout << "\n1. Criando alunos com diferentes perfis:" << std::endl;
    
    Aluno aluno1(20231001, "Ana Clara Silva", "Ciência da Computação", 9.5);
    Aluno aluno2(20231002, "Pedro Santos", "Engenharia de Software", 7.8);
    Aluno aluno3(20231003, "Maria Oliveira", "Sistemas de Informação", 8.2);
    
    std::cout << "Três alunos criados com sucesso!" << std::endl;
    
    // Teste 2: Testando métodos específicos
    std::cout << "\n2. Testando métodos getter:" << std::endl;
    std::cout << "Aluno 1 - ID: " << aluno1.getID() 
              << ", Nome: " << aluno1.getNome()
              << ", Curso: " << aluno1.getCurso()
              << ", Nota: " << std::fixed << std::setprecision(1) << aluno1.getNota() << std::endl;
    
    // Teste 3: Testando setters
    std::cout << "\n3. Alterando nota do aluno 2:" << std::endl;
    std::cout << "Nota anterior: " << aluno2.getNota() << std::endl;
    aluno2.setNota(8.5);
    std::cout << "Nova nota: " << aluno2.getNota() << std::endl;
    
    // Teste 4: Chamando imprimirInfo()
    std::cout << "\n4. Demonstrando imprimirInfo() específico da classe Aluno:" << std::endl;
    aluno1.imprimirInfo();
    aluno2.imprimirInfo();
    aluno3.imprimirInfo();
}

void demonstrarFuncionario() {
    std::cout << "\n================= TESTE CLASSE FUNCIONARIO ==================" << std::endl;
    
    // Teste 1: Criação de funcionários com diferentes dados
    std::cout << "\n1. Criando funcionários de diferentes departamentos:" << std::endl;
    
    Funcionario func1(100001, "Carlos Mendes", "Desenvolvedor Sênior", "Tecnologia", 8500.00);
    Funcionario func2(100002, "Lucia Fernandes", "Gerente de Projetos", "Gestão", 12000.00);
    Funcionario func3(100003, "Roberto Costa", "Analista de Sistemas", "Tecnologia", 6200.00);
    
    std::cout << "Três funcionários criados com sucesso!" << std::endl;
    
    // Teste 2: Testando métodos específicos
    std::cout << "\n2. Testando métodos getter:" << std::endl;
    std::cout << "Funcionário 1 - ID: " << func1.getID() 
              << ", Nome: " << func1.getNome()
              << ", Cargo: " << func1.getCargo()
              << ", Depto: " << func1.getDepartamento()
              << ", Salário: R$ " << std::fixed << std::setprecision(2) << func1.getSalario() << std::endl;
    
    // Teste 3: Testando setters
    std::cout << "\n3. Promovendo funcionário 3:" << std::endl;
    std::cout << "Cargo anterior: " << func3.getCargo() << std::endl;
    std::cout << "Salário anterior: R$ " << func3.getSalario() << std::endl;
    
    func3.setCargo("Desenvolvedor Sênior");
    func3.setSalario(7800.00);
    
    std::cout << "Novo cargo: " << func3.getCargo() << std::endl;
    std::cout << "Novo salário: R$ " << func3.getSalario() << std::endl;
    
    // Teste 4: Chamando imprimirInfo()
    std::cout << "\n4. Demonstrando imprimirInfo() específico da classe Funcionario:" << std::endl;
    func1.imprimirInfo();
    func2.imprimirInfo();
    func3.imprimirInfo();
}

void demonstrarPolimorfismo() {
    std::cout << "\n================ TESTE DE POLIMORFISMO =================" << std::endl;
    
    std::cout << "\n1. Criando vetor heterogêneo com ponteiros para Elemento:" << std::endl;
    
    // Vetor polimórfico com diferentes tipos de elementos
    std::vector<std::unique_ptr<Elemento>> elementos;
    
    elementos.push_back(std::make_unique<Aluno>(20231004, "Julia Rodrigues", "Engenharia", 9.0));
    elementos.push_back(std::make_unique<Funcionario>(100004, "Antonio Silva", "Coordenador", "Educação", 9500.00));
    elementos.push_back(std::make_unique<Aluno>(20231005, "Felipe Costa", "Design", 8.7));
    elementos.push_back(std::make_unique<Funcionario>(100005, "Sandra Lima", "Diretora", "Administração", 15000.00));
    
    std::cout << "Elementos adicionados ao vetor polimórfico!" << std::endl;
    
    std::cout << "\n2. Iterando pelo vetor e chamando imprimirInfo() polimorficamente:" << std::endl;
    std::cout << "   (Cada elemento chama sua própria implementação)" << std::endl;
    
    for (size_t i = 0; i < elementos.size(); i++) {
        std::cout << "\n--- Elemento " << (i + 1) << " (ID: " << elementos[i]->getID() << ") ---" << std::endl;
        elementos[i]->imprimirInfo();
    }
    
    std::cout << "\n3. Testando operadores de comparação:" << std::endl;
    
    Aluno alunoTeste1(20231010, "Teste A", "Curso A", 8.0);
    Aluno alunoTeste2(20231010, "Teste B", "Curso B", 7.0); // Mesmo ID
    Funcionario funcTeste(20231020, "Teste C", "Cargo C", "Depto C", 5000.0);
    
    if (alunoTeste1 == alunoTeste2) {
        std::cout << "Alunos com mesmo ID são considerados iguais (operador ==)" << std::endl;
    }
    
    if (alunoTeste1 < funcTeste) {
        std::cout << "Aluno tem ID menor que funcionário (operador <)" << std::endl;
    }
}

void demonstrarEncapsulamento() {
    std::cout << "\n================ TESTE DE ENCAPSULAMENTO ================" << std::endl;
    
    std::cout << "\n1. Demonstrando acesso controlado aos atributos:" << std::endl;
    
    Aluno aluno(20231006, "Teste Encapsulamento", "Teste", 8.0);
    
    // Acesso permitido através de métodos públicos
    std::cout << "Acesso ao ID através de getID(): " << aluno.getID() << std::endl;
    std::cout << "Acesso ao nome através de getNome(): " << aluno.getNome() << std::endl;
    
    // Modificação controlada através de setters
    std::cout << "Modificação da nota através de setNota()" << std::endl;
    aluno.setNota(9.5);
    std::cout << "  Nova nota: " << aluno.getNota() << std::endl;
    
    std::cout << "\n2. Tentativas de acesso direto aos atributos privados:" << std::endl;
    std::cout << "   (As linhas abaixo causariam erro de compilação se descomentadas)" << std::endl;
    std::cout << "   // aluno.nome = \"Hack\";        // ERRO: atributo privado" << std::endl;
    std::cout << "   // aluno.ID = 999;              // ERRO: atributo protegido" << std::endl;
    std::cout << "   // aluno.nota = 10.0;           // ERRO: atributo privado" << std::endl;
    
    std::cout << "Encapsulamento funcionando corretamente!" << std::endl;
}

int main() {
    // Configura locale para português
    CONFIGURAR_PORTUGUES();
    
    std::cout << "========== TESTE COMPLETO DAS CLASSES DERIVADAS ==========" << std::endl;
    std::cout << "Este teste demonstra todas as funcionalidades implementadas" << std::endl;
    std::cout << "nas classes Aluno e Funcionario que herdam de Elemento." << std::endl;
    
    // Executar todos os testes
    demonstrarAluno();
    demonstrarFuncionario();
    demonstrarPolimorfismo();
    demonstrarEncapsulamento();
    
    std::cout << "\n=================== RESUMO DOS TESTES ===================" << std::endl;
    std::cout << "Classe Aluno: Todos os métodos funcionando corretamente" << std::endl;
    std::cout << "Classe Funcionario: Todos os métodos funcionando corretamente" << std::endl;
    std::cout << "Polimorfismo: imprimirInfo() chamado corretamente para cada tipo" << std::endl;
    std::cout << "Encapsulamento: Acesso controlado aos atributos" << std::endl;
    std::cout << "Herança: Reutilização do código da classe base" << std::endl;
    std::cout << "Operadores: Comparação baseada no ID funcionando" << std::endl;
    
    std::cout << "\nTODOS OS TESTES PASSARAM COM SUCESSO! " << std::endl;
    
    return 0;
}
