# Projeto: Estruturas de Dados Orientadas a Objetos em C++

## Objetivo

Este projeto tem como objetivo aplicar de forma prática os **quatro pilares da Programação Orientada a Objetos (POO)**:  
- **Abstração**
- **Encapsulamento**
- **Herança**
- **Polimorfismo**

A proposta consiste na **implementação de um conjunto de estruturas de dados clássicas em C++**, utilizando uma **hierarquia de classes coesa, reutilizável e robusta**, seguindo as melhores práticas de POO.

---

## Estrutura do Projeto

O projeto está dividido em três partes principais:

---

## Parte I – Estruturas com Alocação Sequencial

### Classe Abstrata: `Elemento`
- Contém atributo protegido: `ID` (int ou long)
- Método público: `getID() const`
- Método virtual puro obrigatório: `virtual void imprimirInfo() const = 0;`
- Não pode ser instanciada diretamente

### Classes Derivadas de `Elemento`
- Pelo menos duas classes concretas (ex: `Aluno`, `Funcionario`)
- Implementam todos os métodos virtuais herdados
- Contêm atributos e métodos próprios

### Estruturas de Dados Sequenciais

#### Lista Não Ordenada
- Métodos:
  - `InserirNoInicio`
  - `InserirNoFinal`
  - `RemoverPrimeiro`
  - `RemoverUltimo`
  - `RemoverPeloId`
  - `BuscarPeloId`
  - `AlterarPeloId`
- Cada método possui análise de complexidade

#### Lista Ordenada
- Mesmos métodos da não ordenada
- Mantém elementos ordenados por ID
- Implementa **busca binária** para `BuscarPeloId` (**O(log n)**)

#### Pilha (composição)
- Utiliza uma lista como atributo privado
- Métodos públicos:
  - `empilhar`
  - `desempilhar`
  - `consultarTopo`
  - `pilhaCheia`
  - `pilhaVazia`

#### Fila (composição)
- Utiliza uma lista como estrutura base
- Apresenta implementação ineficiente → propor uma **segunda versão otimizada**

---

## Parte II – Estruturas com Alocação Encadeada

### Encapsulamento dos Nós
- Nós são classes privadas internas às estruturas
- Não são visíveis externamente

### Estruturas Encadeadas

#### Lista Simplesmente Encadeada
#### Lista Duplamente Encadeada
#### Lista Duplamente Encadeada Circular

Cada uma deve implementar:
- `inserirNoInicio`
- `inserirNoFim`
- `removerPeloId`
- `buscarPeloId`
- Outros métodos pertinentes

### Estruturas por Composição

- **Pilha, Fila e Deque** utilizando composição com as listas encadeadas
- Estrutura base deve ser escolhida com foco em **eficiência**

### Árvore Binária de Busca (ABB)

- Classe privada para o nó
- Métodos:
  - `Inserir`
  - `BuscarPeloId`
  - `RemoverPeloId`
  - Percursos:
    - `emOrdem()`
    - `preOrdem()`
    - `posOrdem()`

---

## Parte III – Demonstração e Testes

### Arquivo `main.cpp`

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
