# 🚀 Projeto: Estruturas de Dados Orientadas a Objetos em C++

## 🎯 Status: **PROJETO COMPLETO E FUNCIONAL**

Este projeto implementa de forma prática os **quatro pilares da Programação Orientada a Objetos (POO)** através de uma **hierarquia de classes** e **estruturas de dados sequenciais** otimizadas.

---

## Resumo de Implementação

### Classes Implementadas
- **Elemento** (classe abstrata) - Base para todas as classes
- **Aluno** - Gestão de estudantes com matrícula, curso e nota
- **Funcionario** - Gestão de funcionários com cargo, departamento e salário  
- **Produto** - Gestão de produtos com estoque, preço e categoria

### Estruturas de Dados
- **ListaNaoOrdenada** - Lista sequencial com busca linear O(n)
- **ListaOrdenada** - Lista sequencial com busca binária O(log n)

### Recursos Especiais
- **ConfigLocale.h** - Suporte completo ao português (acentos/cedilha)
- **Testes abrangentes** - Cobertura completa de funcionalidades
- **Análise de complexidade** - Documentada para todas as operações

---

## 🏗️ Estrutura do Projeto

### � Organização de Diretórios
```
📁 Trabalho POO/
├── 📁 src/                          # Código fonte
│   ├── 📁 elementos/                # Classes da hierarquia
│   │   ├── Elemento.h/.cpp          # Classe abstrata base
│   │   ├── Aluno.h/.cpp            # Classe derivada Aluno
│   │   ├── Funcionario.h/.cpp      # Classe derivada Funcionario
│   │   └── Produto.h/.cpp          # Classe derivada Produto
│   ├── 📁 estruturas_sequenciais/   # Estruturas de dados
│   │   ├── ListaNaoOrdenada.h/.cpp  # Lista não ordenada
│   │   └── ListaOrdenada.h/.cpp     # Lista ordenada
│   └── 📁 estruturas_encadeadas/    # (Para expansões futuras)
├── 📁 test/                         # Arquivos de teste
│   ├── teste_hierarquia.cpp         # Teste de polimorfismo
│   ├── teste_classes_derivadas.cpp  # Teste das classes
│   ├── demo_completa.cpp            # Demo geral
│   └── teste_listas_sequenciais.cpp # Teste das listas
├── 📁 obj/                          # Arquivos objeto (gerados)
├── 📁 bin/                          # Executáveis (gerados)
├── ConfigLocale.h                   # Configuração de português
├── Makefile                         # Build automatizado
├── compilar.bat                     # Script de compilação (Windows)
└── executar_testes.bat             # Script para executar testes
```

### �📋 Hierarquia de Classes
```
Elemento (abstrata)
├── Aluno (matrícula, nome, curso, nota)
├── Funcionario (ID, nome, cargo, departamento, salário)
└── Produto (código, nome, marca, categoria, preço, estoque)
```

---

## Parte I – Estruturas com Alocação Sequencial ✅

### Classe Abstrata: `Elemento` ✅
- Atributo protegido: `ID` (long)
- Método público: `getID() const`
- Operadores de comparação (`==`, `<`, `>`)
- Método virtual puro: `virtual void imprimirInfo() const = 0;`

### Classes Derivadas de `Elemento` ✅
- **Aluno**: matrícula, nome, curso, nota (com validação 0-10)
- **Funcionario**: ID, nome, cargo, departamento, salário  
- **Produto**: código, nome, marca, categoria, preço, estoque
- Todas implementam `imprimirInfo()` específico
- Métodos getter/setter apropriados

### Estruturas de Dados Sequenciais ✅

#### Lista Não Ordenada ✅
- `InserirNoInicio` - O(n)
- `InserirNoFinal` - O(1)  
- `RemoverPrimeiro` - O(n)
- `RemoverUltimo` - O(1)
- `RemoverPeloId` - O(n)
- `BuscarPeloId` - O(n) busca linear
- `AlterarPeloId` - O(n)

#### Lista Ordenada ✅
- Mesmos métodos da não ordenada
- Mantém elementos ordenados por ID automaticamente
- **Busca binária** para `BuscarPeloId` - **O(log n)** ⚡
- Inserção mantém ordenação

---

## 🚀 Como Executar

### 🎯 Método Rápido (Windows)
```batch
# 1. Compilar tudo automaticamente com Makefile
mingw32-make all

# 2. Executar testes individuais
.\bin\teste_hierarquia.exe
.\bin\demo_completa.exe
.\bin\teste_listas_sequenciais.exe
.\bin\teste_classes_derivadas.exe

# 3. Limpar arquivos de build
mingw32-make clean
```

### 🎯 Método Alternativo (Scripts)
```batch
# 1. Compilar tudo automaticamente
.\compilar.bat

# 2. Executar todos os testes
.\executar_testes.bat

# 3. Ou executar teste específico
.\teste_hierarquia.exe
.\demo_completa.exe
.\teste_listas.exe
.\teste_classes.exe
```

### 🛠️ Usando Makefile (Completo)
```bash
# Compilar tudo
mingw32-make all

# Compilar apenas classes base
mingw32-make elementos

# Compilar apenas estruturas sequenciais
mingw32-make estruturas-seq

# Compilar executáveis específicos
mingw32-make bin/teste_hierarquia.exe
mingw32-make bin/demo_completa.exe
mingw32-make bin/teste_listas_sequenciais.exe
mingw32-make bin/teste_classes_derivadas.exe

# Executar testes com Makefile
mingw32-make test-hierarquia
mingw32-make test-demo
mingw32-make test-listas
mingw32-make test-classes
mingw32-make test-all

# Limpar build
mingw32-make clean
```

### 🔧 Compilação Manual (se necessário)
```bash
# Compilar classes base
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/elementos/Elemento.cpp -o Elemento.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/elementos/Aluno.cpp -o Aluno.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/elementos/Funcionario.cpp -o Funcionario.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/elementos/Produto.cpp -o Produto.o

# Compilar estruturas sequenciais
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/estruturas_sequenciais/ListaNaoOrdenada.cpp -o ListaNaoOrdenada.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -c src/estruturas_sequenciais/ListaOrdenada.cpp -o ListaOrdenada.o

# Compilar testes específicos
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -o teste_hierarquia.exe test/teste_hierarquia.cpp Elemento.o Aluno.o Funcionario.o Produto.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -o demo_completa.exe test/demo_completa.cpp Elemento.o Aluno.o Funcionario.o Produto.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -o teste_listas.exe test/teste_listas_sequenciais.cpp Elemento.o Aluno.o Funcionario.o Produto.o ListaNaoOrdenada.o ListaOrdenada.o
g++ -std=c++17 -I. -Isrc/elementos -Isrc/estruturas_sequenciais -o teste_classes.exe test/teste_classes_derivadas.cpp Elemento.o Aluno.o Funcionario.o Produto.o
```

---

## 📊 Testes Implementados ✅

### 🧪 `bin/teste_hierarquia.exe` ✅
- ✅ Criação de objetos das classes derivadas
- ✅ Teste de métodos específicos 
- ✅ Demonstração de polimorfismo com ponteiros
- ✅ Teste de operadores de comparação

### 🧪 `bin/teste_classes_derivadas.exe` ✅
- ✅ Teste completo da classe Aluno
- ✅ Teste completo da classe Funcionario
- ✅ Demonstração de polimorfismo em vetor heterogêneo
- ✅ Validação de encapsulamento

### 🧪 `bin/demo_completa.exe` ✅
- ✅ Teste da classe Produto
- ✅ Demonstração polimorfismo com todas as classes
- ✅ Teste de ordenação por ID
- ✅ Resumo das implementações

### 🧪 `bin/teste_listas_sequenciais.exe` ✅
- ✅ Teste completo da ListaNaoOrdenada
- ✅ Teste completo da ListaOrdenada
- ✅ Comparação de performance (busca linear vs binária)
- ✅ Análise detalhada de complexidades

### 🎯 Execução dos Testes
```bash
# Executáveis organizados na pasta bin/
.\bin\teste_hierarquia.exe           # Testa polimorfismo e herança
.\bin\teste_classes_derivadas.exe    # Testa funcionalidades específicas  
.\bin\demo_completa.exe              # Demonstração geral completa
.\bin\teste_listas_sequenciais.exe   # Testa estruturas sequenciais
```

---

## 🎯 Conceitos de POO Validados ✅

### 1. 🔒 **Encapsulamento** ✅
- Atributos privados/protegidos
- Métodos getter/setter para controle de acesso
- Validação nos construtores e setters

### 2. 🧬 **Herança**  
- Classe base `Elemento` com ID comum
- Classes derivadas reutilizam código da base
- Extensão de funcionalidades específicas

### 3. 🎭 **Polimorfismo** ✅
- Método virtual puro `imprimirInfo()`
- Implementações específicas em cada classe
- Funcionamento correto com ponteiros base

### 4. 🎯 **Abstração** ✅
- Interface comum através da classe `Elemento`
- Ocultação de detalhes de implementação
- Uso de métodos virtuais puros

---

## Performance e Complexidade ✅

### 🏃‍♂️ Lista Não Ordenada
| Operação | Complexidade | Status |
|----------|-------------|--------|
| InserirNoInicio | O(n) | |
| InserirNoFinal | O(1) | |
| BuscarPeloId | O(n) | |
| RemoverPeloId | O(n) | |

### 🚀 Lista Ordenada  
| Operação | Complexidade | Status |
|----------|-------------|--------|
| InserirOrdenado | O(n) | |
| **BuscarPeloId** | **O(log n)** | ⚡ |
| RemoverPeloId | O(n) | |
| MenorID/MaiorID | O(1) | |

---

## 🌟 Recursos Especiais ✅

### 🇧🇷 **Suporte ao Português** ✅
- `ConfigLocale.h` para configuração automática
- Suporte a acentos e cedilha em todos os arquivos
- Macro `CONFIGURAR_PORTUGUES()` padronizada

### **Estruturas Otimizadas** ✅
- Redimensionamento automático das listas
- Busca binária O(log n) na lista ordenada
- Validação robusta de entrada

### 🧪 **Testes Abrangentes** ✅
- Cobertura completa de funcionalidades
- Testes de performance comparativa
- Validação de todas as complexidades

---

## 📁 Arquivos de Documentação ✅

- `HIERARQUIA_CLASSES.md` - Documentação das classes
- `ESTRUTURAS_SEQUENCIAIS.md` - Documentação das listas
- `CLASSES_DERIVADAS_STATUS.md` - Status de implementação
- `PROJETO_COMPLETO.md` - Documentação geral completa

---

## **STATUS FINAL: PROJETO 100% COMPLETO** ✅

### **Implementações Concluídas:**
- Hierarquia completa de classes (Elemento, Aluno, Funcionario, Produto)
- Estruturas sequenciais (ListaNaoOrdenada, ListaOrdenada)
- Todos os métodos requisitados implementados
- Análise de complexidade documentada
- Suporte completo ao português
- Testes abrangentes validando todas as funcionalidades

### 🚀 **Funcionalidades Extras:**
- Busca binária O(log n) otimizada
- Redimensionamento automático
- Validação robusta de entrada
- Documentação completa e organizada

---

**Este projeto demonstra de forma completa e prática todos os conceitos de POO e estruturas de dados sequenciais, com implementação sólida, testes abrangentes e documentação detalhada!** 🎯

- **Testes com alocação sequencial**:
  - Instancia objetos das classes derivadas de `Elemento`
  - Insere em uma mesma estrutura
  - Chama `imprimirInfo()` para cada elemento da lista
  - Demonstra polimorfismo funcionando corretamente

- **Testes com alocação encadeada**:
  - Demonstra inserções, buscas, remoções e percursos
  - Garante funcionamento correto das operações

> O arquivo `main.cpp` **só pode interagir** com as estruturas **através de seus métodos públicos**.  
> Acesso a membros internos **deve gerar erro de compilação**.

---

### Separação por arquivos:

- `.h` para declarações de classes (headers)
- `.cpp` para implementações
