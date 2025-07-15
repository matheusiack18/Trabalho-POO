# Estruturas de Dados Orientadas a Objetos em C++

## Integrantes do Grupo
- Caio Bento 
- Matheus Iack
- Rayssa Freitas

---

## Estrutura do Projeto

```
📁 Trabalho POO/
├── 📁 src/
│   ├── 📁 elementos/                # Hierarquia de classes
│   ├── 📁 estruturas_sequenciais/   # Listas, pilhas e filas
│   └── 📁 estruturas_encadeadas/    # Listas encadeadas e adaptadores
├── 📁 test/                         # Arquivos de teste
├── 📁 bin/                          # Executáveis compilados
├── main.cpp                         # Demonstração integrada
└── Makefile                         # Build automatizado
```

---

## Principais Decisões de Design

### 1. **Hierarquia de Classes**
**Decisão**: Implementar classe abstrata `Elemento` como base para todas as classes derivadas.
**Justificativa**: Garantir polimorfismo e padronização do atributo `ID` comum a todas as entidades, permitindo que diferentes tipos de objetos sejam armazenados e manipulados nas mesmas estruturas de dados.

### 2. **Estruturas Sequenciais por Composição**
**Decisão**: Implementar Pilha e Fila através de composição usando `ListaNaoOrdenada`.
**Justificativa**: Maximizar o reuso de código já implementado na classe Lista, evitando duplicação de funcionalidades básicas como inserção e remoção de elementos.

### 3. **Busca Binária na Lista Ordenada**
**Decisão**: Implementar busca binária O(log n) na `ListaOrdenada`.
**Justificativa**: Aproveitar a característica de ordenação automática para otimizar significativamente a performance de busca, reduzindo de O(n) para O(log n).

### 4. **Fila Otimizada com Buffer Circular**
**Decisão**: Criar `FilaOtimizada` utilizando array circular com índices de início e fim.
**Justificativa**: Resolver a ineficiência O(n) da operação `desenfileirar` na implementação por composição, alcançando O(1) para todas as operações.

### 5. **Encapsulamento de Nós**
**Decisão**: Implementar classes `No` como privadas dentro de cada estrutura encadeada.
**Justificativa**: Garantir encapsulamento total, impedindo que o usuário manipule diretamente os nós e comprometendo a integridade das estruturas.

### 6. **Adaptadores por Composição**
**Decisão**: Implementar `PilhaEncadeada`, `FilaEncadeada` e `Deque` como adaptadores das listas encadeadas.
**Justificativa**: Aplicar o padrão Adapter para reutilizar código das listas já implementadas, escolhendo a estrutura interna mais adequada para cada tipo de operação (ex: `ListaDuplamenteEncadeada` para Deque por permitir remoção eficiente em ambas as extremidades).

### 7. **Árvore Binária de Busca**
**Decisão**: Implementar ABB com organização automática por ID e métodos recursivos privados.
**Justificativa**: Fornecer estrutura hierárquica com busca eficiente O(log n) e percursos ordenados, mantendo encapsulamento através de métodos auxiliares privados.

### 8. **Gerenciamento de Memória**
**Decisão**: Utilizar `std::unique_ptr` para gerenciamento automático de memória.
**Justificativa**: Seguir práticas modernas de C++ com RAII, evitando vazamentos de memória e simplificando o gerenciamento de recursos.

---

## Tabela Completa de Complexidade das Operações

### Estruturas Sequenciais
| Estrutura | Inserir Início | Inserir Fim | Buscar ID | Remover ID | Remover Primeiro | Remover Último | Alterar ID |
|-----------|----------------|-------------|-----------|------------|------------------|----------------|------------|
| **ListaNaoOrdenada** | O(n) | O(1) | O(n) | O(n) | O(n) | O(1) | O(n) |
| **ListaOrdenada** | O(n) | O(n) | **O(log n)** | O(n) | O(n) | O(1) | O(n) |
| **Pilha** | O(1) empilhar | - | - | - | O(1) desempilhar | - | - |
| **Fila** | - | O(1) enfileirar | - | - | O(n) desenfileirar | - | - |
| **FilaOtimizada** | - | O(1) enfileirar | - | - | **O(1)** desenfileirar | - | - |

### Estruturas Encadeadas
| Estrutura | Inserir Início | Inserir Fim | Buscar ID | Remover ID | Alterar ID | Navegação | Vantagens |
|-----------|----------------|-------------|-----------|------------|------------|-----------|-----------|
| **ListaSimples** | O(1) | O(1) | O(n) | O(n) | O(n) | → | Memória dinâmica |
| **ListaDupla** | O(1) | O(1) | O(n) | O(n) | O(n) | ← → | Navegação bidirecional |
| **ListaCircular** | O(1) | O(1) | O(n) | O(n) | O(n) | ↻ | Acesso cíclico |

### Adaptadores por Composição
| Adaptador | Operação Principal | Inserir | Remover | Consultar | Verificar (vazio/cheio) | Estrutura Interna |
|-----------|-------------------|---------|---------|-----------|-------------------|
| **PilhaEncadeada** | LIFO | O(1) empilhar | O(1) desempilhar | O(1) topo | `pilhaVazia()` / `pilhaCheia()` - O(1) | ListaSimplesmenteEncadeada |
| **FilaEncadeada** | FIFO | O(1) enfileirar | O(n) desenfileirar | O(1) frente | `filaVazia()` / `filaCheia()` - O(1) | ListaSimplesmenteEncadeada |
| **Deque** | Dupla extremidade | O(1) início/fim | O(1) início/fim | O(1) início/fim | `filaVazia()` / `filaCheia()` - O(1) | ListaDuplamenteEncadeada |

### Árvore Binária de Busca
| Operação | Melhor Caso | Caso Médio | Pior Caso | Observações |
|----------|-------------|------------|-----------|-------------|
| **Inserir** | O(log n) | O(log n) | O(n) | Degrada se desbalanceada |
| **Buscar** | O(log n) | O(log n) | O(n) | Eficiente se balanceada |
| **Remover** | O(log n) | O(log n) | O(n) | Complexa para 2 filhos |
| **EmOrdem** | O(n) | O(n) | O(n) | Produz sequência ordenada |
| **PreOrdem** | O(n) | O(n) | O(n) | Útil para copiar árvore |
| **PosOrdem** | O(n) | O(n) | O(n) | Útil para liberar memória |
| **Mínimo** | O(log n) | O(log n) | O(n) | Caminho à esquerda |
| **Máximo** | O(log n) | O(log n) | O(n) | Caminho à direita |
| **Altura** | O(n) | O(n) | O(n) | Visita todos os nós |

### Comparação de Performance por Operação

#### Busca por ID
| Estrutura | Complexidade | Método | Eficiência |
|-----------|-------------|--------|------------|
| **ListaNaoOrdenada** | O(n) | Busca linear | 🔴 Lenta |
| **ListaOrdenada** | **O(log n)** | Busca binária | 🟡 Rápida |
| **Listas Encadeadas** | O(n) | Busca linear | 🔴 Lenta |
| **ArvoreBinariaBusca** | **O(log n)** | Busca hierárquica | 🟢 Muito rápida |

#### Inserção
| Estrutura | No Início | No Fim | Ordenada | Observações |
|-----------|-----------|--------|----------|-------------|
| **ListaNaoOrdenada** | O(n) | O(1) | - | Deslocamento de elementos |
| **ListaOrdenada** | O(n) | O(n) | O(n) | Mantém ordenação |
| **Listas Encadeadas** | O(1) | O(1) | - | Sem deslocamento |
| **ArvoreBinariaBusca** | - | - | O(log n) | Auto-organizada |

#### Remoção
| Estrutura | Primeiro | Último | Por ID | Observações |
|-----------|----------|--------|--------|-------------|
| **ListaNaoOrdenada** | O(n) | O(1) | O(n) | Deslocamento |
| **ListaOrdenada** | O(n) | O(1) | O(n) | Mantém ordenação |
| **Listas Encadeadas** | O(1) | O(1)/O(n) | O(n) | Depende da estrutura |
| **ArvoreBinariaBusca** | - | - | O(log n) | Reorganização automática |

---

## Execução dos Testes

### Compilação e Execução
```bash
# Compilar tudo
mingw32-make all

# Executar demonstração principal
.\bin\main.exe

# Executar testes específicos
.\bin\teste_hierarquia.exe           # Polimorfismo e herança
.\bin\teste_listas_sequenciais.exe   # Estruturas sequenciais
.\bin\teste_estruturas_encadeadas.exe # Estruturas encadeadas
.\bin\teste_adaptadores.exe          # Adaptadores por composição
.\bin\teste_arvore_binaria.exe       # Árvore binária de busca
.\bin\teste_pilha_fila.exe          # Pilha e filas
```

### Funcionalidades Testadas
- **Polimorfismo**: Diferentes classes usando a mesma interface
- **Encapsulamento**: Acesso apenas através da interface pública
- **Herança**: Reutilização de código da classe base
- **Composição**: Reutilização através de adaptadores
- **Performance**: Comparação de complexidades

---

## Resumo das Implementações

### Classes da Hierarquia
- **Elemento** (abstrata) - Base com ID comum
- **Aluno** - Matrícula, nome, curso, nota (validação 0-10)
- **Funcionario** - ID, nome, cargo, departamento, salário
- **Produto** - Código, nome, marca, categoria, preço, estoque

### Estruturas Implementadas
- **5 Estruturas Sequenciais** - Listas, pilhas e filas
- **3 Estruturas Encadeadas** - Com nós privados encapsulados
- **3 Adaptadores por Composição** - Reutilização de código
- **1 Estrutura Hierárquica** - Árvore Binária de Busca

### Recursos Especiais
- **Busca binária O(log n)** na lista ordenada
- **Buffer circular** na fila otimizada
- **Navegação bidirecional** na lista dupla
- **Percursos da árvore** (em ordem, pré-ordem, pós-ordem)
- **Gerenciamento automático de memória** com smart pointers
- **Encapsulamento total** com nós privados
- **Suporte completo ao português** com ConfigLocale.h

---

## Análise de Complexidade por Caso de Uso

### Para Aplicações que Precisam de Busca Frequente
**Recomendação**: ArvoreBinariaBusca > ListaOrdenada > Listas Encadeadas
- **ABB**: O(log n) - Ideal para muitas buscas
- **Lista Ordenada**: O(log n) - Boa para dados sequenciais
- **Listas Encadeadas**: O(n) - Evitar para busca intensiva

### Para Aplicações com Inserções/Remoções Frequentes no Início
**Recomendação**: Listas Encadeadas > Pilha > Listas Sequenciais
- **Listas Encadeadas**: O(1) - Sem deslocamento
- **Pilha**: O(1) - Ideal para padrão LIFO
- **Listas Sequenciais**: O(n) - Deslocamento custoso

### Para Aplicações com Acesso Sequencial
**Recomendação**: Listas Sequenciais > Listas Encadeadas
- **Listas Sequenciais**: Melhor localidade de memória
- **Listas Encadeadas**: Fragmentação de memória

### Para Aplicações com Padrões LIFO/FIFO
**Recomendação**: Adaptadores Específicos
- **LIFO**: PilhaEncadeada - O(1) todas operações
- **FIFO**: FilaOtimizada - O(1) todas operações
- **Dupla Extremidade**: Deque - O(1) ambas extremidades

---

## Conclusão

Este projeto demonstra a implementação completa de estruturas de dados orientadas a objetos em C++, com foco na análise de complexidade e escolha adequada de estruturas para diferentes cenários de uso. A implementação garante encapsulamento total, reutilização de código através de composição e herança, e performance otimizada através de algoritmos eficientes como busca binária e buffer circular.