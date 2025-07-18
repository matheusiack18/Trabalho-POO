# Makefile para o projeto de Estruturas de Dados POO
# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Diretórios
SRCDIR = src
TESTDIR = test
OBJDIR = obj
BINDIR = bin

# Subdiretórios de código fonte
ELEM_DIR = $(SRCDIR)/elementos
SEQ_DIR = $(SRCDIR)/estruturas_sequenciais
ENC_DIR = $(SRCDIR)/estruturas_encadeadas

# Caminhos de include
INCLUDES = -I. -I$(ELEM_DIR) -I$(SEQ_DIR) -I$(ENC_DIR)

# Arquivos fonte das classes
ELEM_SOURCES = $(wildcard $(ELEM_DIR)/*.cpp)
SEQ_SOURCES = $(wildcard $(SEQ_DIR)/*.cpp)
ENC_SOURCES = $(wildcard $(ENC_DIR)/*.cpp)

# Arquivos de teste
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)

# Objetos
ELEM_OBJECTS = $(ELEM_SOURCES:$(ELEM_DIR)/%.cpp=$(OBJDIR)/elementos/%.o)
SEQ_OBJECTS = $(SEQ_SOURCES:$(SEQ_DIR)/%.cpp=$(OBJDIR)/estruturas_sequenciais/%.o)
ENC_OBJECTS = $(ENC_SOURCES:$(ENC_DIR)/%.cpp=$(OBJDIR)/estruturas_encadeadas/%.o)

# Objetos de teste
TEST_OBJECTS = $(TEST_SOURCES:$(TESTDIR)/%.cpp=$(OBJDIR)/test/%.o)

# Executáveis
TARGETS = $(BINDIR)/main.exe \
          $(BINDIR)/teste_hierarquia.exe \
          $(BINDIR)/teste_classes_derivadas.exe \
          $(BINDIR)/demo_completa.exe \
          $(BINDIR)/teste_listas_sequenciais.exe \
          $(BINDIR)/teste_pilha_fila.exe \
          $(BINDIR)/teste_estruturas_encadeadas.exe \
          $(BINDIR)/teste_adaptadores.exe \
          $(BINDIR)/teste_arvore_binaria.exe

# Regra padrão
all: $(TARGETS)

# Main principal do projeto
$(BINDIR)/main.exe: $(ELEM_OBJECTS) $(SEQ_OBJECTS) $(ENC_OBJECTS) $(OBJDIR)/main.o $(OBJDIR)/funcoes.o | $(BINDIR)
	$(CXX) $^ -o $@

# Criação dos executáveis
$(BINDIR)/teste_hierarquia.exe: $(ELEM_OBJECTS) $(OBJDIR)/test/teste_hierarquia.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_classes_derivadas.exe: $(ELEM_OBJECTS) $(OBJDIR)/test/teste_classes_derivadas.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/demo_completa.exe: $(ELEM_OBJECTS) $(OBJDIR)/test/demo_completa.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_listas_sequenciais.exe: $(ELEM_OBJECTS) $(SEQ_OBJECTS) $(OBJDIR)/test/teste_listas_sequenciais.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_pilha_fila.exe: $(ELEM_OBJECTS) $(SEQ_OBJECTS) $(OBJDIR)/test/teste_pilha_fila.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_estruturas_encadeadas.exe: $(ELEM_OBJECTS) $(ENC_OBJECTS) $(OBJDIR)/test/teste_estruturas_encadeadas.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_adaptadores.exe: $(ELEM_OBJECTS) $(OBJDIR)/estruturas_encadeadas/PilhaEncadeada.o $(OBJDIR)/estruturas_encadeadas/FilaEncadeada.o $(OBJDIR)/estruturas_encadeadas/Deque.o $(OBJDIR)/estruturas_encadeadas/ListaSimplesmenteEncadeada.o $(OBJDIR)/estruturas_encadeadas/ListaDuplamenteEncadeada.o $(OBJDIR)/test/teste_adaptadores.o | $(BINDIR)
	$(CXX) $^ -o $@

$(BINDIR)/teste_arvore_binaria.exe: $(ELEM_OBJECTS) $(OBJDIR)/estruturas_encadeadas/ArvoreBinariaBusca.o $(OBJDIR)/test/teste_arvore_binaria.o | $(BINDIR)
	$(CXX) $^ -o $@

# Compilação dos objetos das classes
$(OBJDIR)/elementos/%.o: $(ELEM_DIR)/%.cpp | $(OBJDIR)/elementos
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/estruturas_sequenciais/%.o: $(SEQ_DIR)/%.cpp | $(OBJDIR)/estruturas_sequenciais
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/estruturas_encadeadas/%.o: $(ENC_DIR)/%.cpp | $(OBJDIR)/estruturas_encadeadas
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilação dos objetos de teste
$(OBJDIR)/test/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)/test
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilação do main.cpp 
$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilação do funcoes.cpp
$(OBJDIR)/funcoes.o: funcoes.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Criação dos diretórios
$(OBJDIR):
	@if not exist $(OBJDIR) mkdir $(OBJDIR)

$(OBJDIR)/elementos: | $(OBJDIR)
	@if not exist $(OBJDIR)\elementos mkdir $(OBJDIR)\elementos

$(OBJDIR)/estruturas_sequenciais: | $(OBJDIR)
	@if not exist $(OBJDIR)\estruturas_sequenciais mkdir $(OBJDIR)\estruturas_sequenciais

$(OBJDIR)/estruturas_encadeadas: | $(OBJDIR)
	@if not exist $(OBJDIR)\estruturas_encadeadas mkdir $(OBJDIR)\estruturas_encadeadas

$(OBJDIR)/test: | $(OBJDIR)
	@if not exist $(OBJDIR)\test mkdir $(OBJDIR)\test

$(BINDIR):
	@if not exist $(BINDIR) mkdir $(BINDIR)

# Limpeza
clean:
	@if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	@if exist $(BINDIR) rmdir /s /q $(BINDIR)

# Tarefas de teste
run-main: $(BINDIR)/main.exe
	./$(BINDIR)/main.exe

test-hierarquia: $(BINDIR)/teste_hierarquia.exe
	./$(BINDIR)/teste_hierarquia.exe

test-demo: $(BINDIR)/demo_completa.exe
	./$(BINDIR)/demo_completa.exe

test-classes: $(BINDIR)/teste_classes_derivadas.exe
	./$(BINDIR)/teste_classes_derivadas.exe

test-listas: $(BINDIR)/teste_listas_sequenciais.exe
	./$(BINDIR)/teste_listas_sequenciais.exe

test-pilha-fila: $(BINDIR)/teste_pilha_fila.exe
	./$(BINDIR)/teste_pilha_fila.exe

test-estruturas-encadeadas: $(BINDIR)/teste_estruturas_encadeadas.exe
	./$(BINDIR)/teste_estruturas_encadeadas.exe

test-adaptadores: $(BINDIR)/teste_adaptadores.exe
	./$(BINDIR)/teste_adaptadores.exe

test-arvore-binaria: $(BINDIR)/teste_arvore_binaria.exe
	./$(BINDIR)/teste_arvore_binaria.exe

test-all: test-hierarquia test-demo test-classes test-listas test-pilha-fila test-estruturas-encadeadas test-adaptadores test-arvore-binaria

# Compilação apenas das classes base
elementos: $(ELEM_OBJECTS)

# Compilação apenas das estruturas sequenciais
estruturas-seq: $(SEQ_OBJECTS)

# Compilação apenas das estruturas encadeadas
estruturas-enc: $(ENC_OBJECTS)

# Regras que não são arquivos
.PHONY: all clean test-hierarquia test-demo test-classes test-listas test-pilha-fila test-estruturas-encadeadas test-adaptadores test-arvore-binaria test-all run-main

# Dependências dos headers
$(OBJDIR)/elementos/Aluno.o: $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Elemento.h ConfigLocale.h
$(OBJDIR)/elementos/Funcionario.o: $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Elemento.h ConfigLocale.h
$(OBJDIR)/elementos/Produto.o: $(ELEM_DIR)/Produto.h $(ELEM_DIR)/Elemento.h ConfigLocale.h
$(OBJDIR)/elementos/Elemento.o: $(ELEM_DIR)/Elemento.h
$(OBJDIR)/estruturas_sequenciais/ListaNaoOrdenada.o: $(SEQ_DIR)/ListaNaoOrdenada.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/estruturas_sequenciais/ListaOrdenada.o: $(SEQ_DIR)/ListaOrdenada.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/estruturas_sequenciais/Pilha.o: $(SEQ_DIR)/Pilha.h $(SEQ_DIR)/ListaNaoOrdenada.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/estruturas_sequenciais/Fila.o: $(SEQ_DIR)/Fila.h $(SEQ_DIR)/ListaNaoOrdenada.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/estruturas_sequenciais/FilaOtimizada.o: $(SEQ_DIR)/FilaOtimizada.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/test/teste_hierarquia.o: $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h ConfigLocale.h
$(OBJDIR)/test/teste_classes_derivadas.o: $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/demo_completa.o: $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/teste_listas_sequenciais.o: $(SEQ_DIR)/ListaNaoOrdenada.h $(SEQ_DIR)/ListaOrdenada.h $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/teste_pilha_fila.o: $(SEQ_DIR)/Pilha.h $(SEQ_DIR)/Fila.h $(SEQ_DIR)/FilaOtimizada.h $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/teste_estruturas_encadeadas.o: $(ENC_DIR)/ListaSimplesmenteEncadeada.h $(ENC_DIR)/ListaDuplamenteEncadeada.h $(ENC_DIR)/ListaDuplamenteEncadeadaCircular.h $(ENC_DIR)/PilhaEncadeada.h $(ENC_DIR)/FilaEncadeada.h $(ENC_DIR)/Deque.h $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/teste_adaptadores.o: $(ENC_DIR)/PilhaEncadeada.h $(ENC_DIR)/FilaEncadeada.h $(ENC_DIR)/Deque.h $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/test/teste_arvore_binaria.o: $(ENC_DIR)/ArvoreBinariaBusca.h $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h ConfigLocale.h
$(OBJDIR)/estruturas_encadeadas/ArvoreBinariaBusca.o: $(ENC_DIR)/ArvoreBinariaBusca.h $(ELEM_DIR)/Elemento.h
$(OBJDIR)/main.o: $(ELEM_DIR)/Elemento.h $(ELEM_DIR)/Aluno.h $(ELEM_DIR)/Funcionario.h $(ELEM_DIR)/Produto.h $(SEQ_DIR)/ListaNaoOrdenada.h $(SEQ_DIR)/ListaOrdenada.h $(SEQ_DIR)/Pilha.h $(SEQ_DIR)/Fila.h $(SEQ_DIR)/FilaOtimizada.h $(ENC_DIR)/ListaSimplesmenteEncadeada.h $(ENC_DIR)/ListaDuplamenteEncadeada.h $(ENC_DIR)/PilhaEncadeada.h $(ENC_DIR)/FilaEncadeada.h $(ENC_DIR)/Deque.h $(ENC_DIR)/ArvoreBinariaBusca.h ConfigLocale.h
$(OBJDIR)/funcoes.o: funcoes.h