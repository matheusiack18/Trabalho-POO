#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() 
    : cabeca(nullptr), cauda(nullptr), tamanho(0) {
}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    limpar();
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - criar estrutura circular com um elemento
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
        cabeca->proximo = cabeca.get();
        cabeca->anterior = cabeca.get();
    } else {
        // Lista não vazia - inserir no início
        No* novoNoPtr = novoNo.get();
        
        // Configurar ligações do novo nó
        novoNo->proximo = cabeca.get();
        novoNo->anterior = cauda;
        
        // Atualizar ligações existentes
        cabeca->anterior = novoNoPtr;
        cauda->proximo = novoNoPtr;
        
        // Novo nó vira cabeça
        cabeca = std::move(novoNo);
    }
    
    tamanho++;
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - criar estrutura circular com um elemento
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
        cabeca->proximo = cabeca.get();
        cabeca->anterior = cabeca.get();
    } else {
        // Lista não vazia - inserir no final
        No* novoNoPtr = novoNo.get();
        
        // Configurar ligações do novo nó
        novoNo->anterior = cauda;
        novoNo->proximo = cabeca.get();
        
        // Atualizar ligações existentes
        cauda->proximo = novoNoPtr;
        cabeca->anterior = novoNoPtr;
        
        // Novo nó vira cauda
        cauda = novoNoPtr;
        
        // Transferir propriedade para o nó anterior
        cauda->anterior->proximo = novoNo.release();
    }
    
    tamanho++;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeadaCircular::removerNo(No* no) {
    if (!no) {
        return nullptr;
    }
    
    auto elementoRemovido = std::move(no->dados);
    
    if (tamanho == 1) {
        // Apenas um elemento
        cabeca = nullptr;
        cauda = nullptr;
    } else {
        // Atualizar ligações
        no->anterior->proximo = no->proximo;
        no->proximo->anterior = no->anterior;
        
        // Atualizar cabeça ou cauda se necessário
        if (no == cabeca.get()) {
            cabeca.reset(no->proximo);
        } else if (no == cauda) {
            cauda = no->anterior;
        }
        
        // Se o nó não é a cabeça, precisamos deletá-lo manualmente
        if (no != cabeca.get()) {
            delete no;
        }
    }
    
    tamanho--;
    return elementoRemovido;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeadaCircular::removerPeloId(long id) {
    if (estaVazia()) {
        return nullptr;
    }
    
    // Buscar o elemento
    No* atual = cabeca.get();
    for (int i = 0; i < tamanho; i++) {
        if (atual->dados->getID() == id) {
            return removerNo(atual);
        }
        atual = atual->proximo;
    }
    
    return nullptr;
}

Elemento* ListaDuplamenteEncadeadaCircular::buscarPeloId(long id) const {
    if (estaVazia()) {
        return nullptr;
    }
    
    No* atual = cabeca.get();
    for (int i = 0; i < tamanho; i++) {
        if (atual->dados->getID() == id) {
            return atual->dados.get();
        }
        atual = atual->proximo;
    }
    
    return nullptr;
}

bool ListaDuplamenteEncadeadaCircular::alterarPeloId(long id, std::unique_ptr<Elemento> novoElemento) {
    if (estaVazia()) {
        return false;
    }
    
    No* atual = cabeca.get();
    for (int i = 0; i < tamanho; i++) {
        if (atual->dados->getID() == id) {
            atual->dados = std::move(novoElemento);
            return true;
        }
        atual = atual->proximo;
    }
    
    return false;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeadaCircular::removerPrimeiro() {
    if (estaVazia()) {
        return nullptr;
    }
    
    return removerNo(cabeca.get());
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeadaCircular::removerUltimo() {
    if (estaVazia()) {
        return nullptr;
    }
    
    return removerNo(cauda);
}

int ListaDuplamenteEncadeadaCircular::getTamanho() const {
    return tamanho;
}

bool ListaDuplamenteEncadeadaCircular::estaVazia() const {
    return cabeca == nullptr;
}

void ListaDuplamenteEncadeadaCircular::imprimirLista() const {
    if (estaVazia()) {
        std::cout << "Lista Duplamente Encadeada Circular vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== LISTA DUPLAMENTE ENCADEADA CIRCULAR (Início -> Fim) ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << std::endl;
    
    No* atual = cabeca.get();
    for (int i = 0; i < tamanho; i++) {
        std::cout << "[" << i << "] ";
        atual->dados->imprimirInfo();
        std::cout << std::endl;
        atual = atual->proximo;
    }
    
    std::cout << "=== FIM DA LISTA ===" << std::endl;
}

void ListaDuplamenteEncadeadaCircular::imprimirListaReversa() const {
    if (estaVazia()) {
        std::cout << "Lista Duplamente Encadeada Circular vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== LISTA DUPLAMENTE ENCADEADA CIRCULAR (Fim -> Início) ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << std::endl;
    
    No* atual = cauda;
    for (int i = tamanho - 1; i >= 0; i--) {
        std::cout << "[" << i << "] ";
        atual->dados->imprimirInfo();
        std::cout << std::endl;
        atual = atual->anterior;
    }
    
    std::cout << "=== FIM DA LISTA REVERSA ===" << std::endl;
}

void ListaDuplamenteEncadeadaCircular::imprimirListaCircular(int voltas) const {
    if (estaVazia()) {
        std::cout << "Lista Duplamente Encadeada Circular vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== DEMONSTRAÇÃO CIRCULAR (" << voltas << " voltas) ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << std::endl;
    
    No* atual = cabeca.get();
    int totalElementos = tamanho * voltas;
    
    for (int i = 0; i < totalElementos; i++) {
        int posicao = i % tamanho;
        int volta = i / tamanho;
        
        std::cout << "[Volta " << volta << ", Pos " << posicao << "] ";
        atual->dados->imprimirInfo();
        std::cout << std::endl;
        
        atual = atual->proximo;
    }
    
    std::cout << "=== FIM DA DEMONSTRAÇÃO CIRCULAR ===" << std::endl;
}

void ListaDuplamenteEncadeadaCircular::limpar() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

Elemento* ListaDuplamenteEncadeadaCircular::obterElementoPorPosicao(int posicao) const {
    if (posicao < 0 || posicao >= tamanho) {
        return nullptr;
    }
    
    No* atual = cabeca.get();
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }
    
    return atual->dados.get();
}

void ListaDuplamenteEncadeadaCircular::rotacionarDireita(int posicoes) {
    if (estaVazia() || tamanho == 1) {
        return;
    }
    
    posicoes = posicoes % tamanho;  // Normalizar posições
    if (posicoes == 0) {
        return;
    }
    
    // Mover cabeça para a direita
    for (int i = 0; i < posicoes; i++) {
        cauda = cabeca.get();
        cabeca.reset(cabeca->proximo);
    }
}

void ListaDuplamenteEncadeadaCircular::rotacionarEsquerda(int posicoes) {
    if (estaVazia() || tamanho == 1) {
        return;
    }
    
    posicoes = posicoes % tamanho;  // Normalizar posições
    if (posicoes == 0) {
        return;
    }
    
    // Mover cabeça para a esquerda
    for (int i = 0; i < posicoes; i++) {
        cabeca.reset(cauda);
        cauda = cauda->anterior;
    }
}

bool ListaDuplamenteEncadeadaCircular::verificarIntegridade() const {
    if (estaVazia()) {
        return true;
    }
    
    if (tamanho == 1) {
        return (cabeca.get() == cauda && 
                cabeca->proximo == cabeca.get() && 
                cabeca->anterior == cabeca.get());
    }
    
    // Verificar se conseguimos percorrer a lista e voltar ao início
    No* atual = cabeca.get();
    for (int i = 0; i < tamanho; i++) {
        if (!atual) {
            return false;
        }
        atual = atual->proximo;
    }
    
    // Após percorrer todos os elementos, devemos estar de volta na cabeça
    return atual == cabeca.get();
}
