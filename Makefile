# Makefile para o projeto de Estruturas de Dados POO
# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Diretórios
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Arquivos fonte
SOURCES = Elemento.cpp Aluno.cpp Funcionario.cpp Produto.cpp ListaNaoOrdenada.cpp ListaOrdenada.cpp teste_hierarquia.cpp teste_classes_derivadas.cpp teste_listas_sequenciais.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Executável principal
TARGET = $(BINDIR)/teste_hierarquia
TARGET2 = $(BINDIR)/teste_classes_derivadas
TARGET3 = $(BINDIR)/teste_listas_sequenciais

# Regra padrão
all: $(TARGET) $(TARGET2) $(TARGET3)

# Criação do executável
$(TARGET): $(OBJDIR)/Elemento.o $(OBJDIR)/Aluno.o $(OBJDIR)/Funcionario.o $(OBJDIR)/Produto.o $(OBJDIR)/teste_hierarquia.o | $(BINDIR)
	$(CXX) $^ -o $@

$(TARGET2): $(OBJDIR)/Elemento.o $(OBJDIR)/Aluno.o $(OBJDIR)/Funcionario.o $(OBJDIR)/Produto.o $(OBJDIR)/teste_classes_derivadas.o | $(BINDIR)
	$(CXX) $^ -o $@

$(TARGET3): $(OBJDIR)/Elemento.o $(OBJDIR)/Aluno.o $(OBJDIR)/Funcionario.o $(OBJDIR)/Produto.o $(OBJDIR)/ListaNaoOrdenada.o $(OBJDIR)/ListaOrdenada.o $(OBJDIR)/teste_listas_sequenciais.o | $(BINDIR)
	$(CXX) $^ -o $@

# Compilação dos arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criação dos diretórios
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Limpeza
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Execução do teste
test: $(TARGET)
	./$(TARGET)

test-completo: $(TARGET2)
	./$(TARGET2)

test-listas: $(TARGET3)
	./$(TARGET3)

# Compilação apenas da hierarquia (sem o main)
hierarquia: $(OBJDIR)/Elemento.o $(OBJDIR)/Aluno.o $(OBJDIR)/Funcionario.o $(OBJDIR)/Produto.o

# Compilação apenas das listas
listas: $(OBJDIR)/ListaNaoOrdenada.o $(OBJDIR)/ListaOrdenada.o

# Regras que não são arquivos
.PHONY: all clean test test-completo test-listas hierarquia listas

# Dependências dos headers
$(OBJDIR)/Aluno.o: Aluno.h Elemento.h
$(OBJDIR)/Funcionario.o: Funcionario.h Elemento.h
$(OBJDIR)/Produto.o: Produto.h Elemento.h
$(OBJDIR)/ListaNaoOrdenada.o: ListaNaoOrdenada.h Elemento.h
$(OBJDIR)/ListaOrdenada.o: ListaOrdenada.h Elemento.h
$(OBJDIR)/teste_hierarquia.o: Elemento.h Aluno.h Funcionario.h
$(OBJDIR)/teste_classes_derivadas.o: Elemento.h Aluno.h Funcionario.h Produto.h
$(OBJDIR)/teste_listas_sequenciais.o: ListaNaoOrdenada.h ListaOrdenada.h Elemento.h Aluno.h Funcionario.h Produto.h
