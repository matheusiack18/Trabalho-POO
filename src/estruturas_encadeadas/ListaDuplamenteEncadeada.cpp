#include "ListaDuplamenteEncadeada.h"
#include <iostream>

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() 
    : cabeca(nullptr), cauda(nullptr), tamanho(0) {
}

void ListaDuplamenteEncadeada::inserirNoInicio(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - primeiro elemento é tanto cabeça quanto cauda
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
    } else {
        // Lista não vazia - novo nó aponta para a antiga cabeça
        novoNo->proximo = std::move(cabeca);
        novoNo->proximo->anterior = novoNo.get();
        cabeca = std::move(novoNo);
    }
    
    tamanho++;
}

void ListaDuplamenteEncadeada::inserirNoFim(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - primeiro elemento é tanto cabeça quanto cauda
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
    } else {
        // Lista não vazia - cauda atual aponta para o novo nó
        novoNo->anterior = cauda;
        cauda->proximo = std::move(novoNo);
        cauda = cauda->proximo.get();
    }
    
    tamanho++;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeada::removerPeloId(long id) {
    if (estaVazia()) {
        return nullptr;
    }
    
    // Buscar o elemento
    No* atual = cabeca.get();
    while (atual && atual->dados->getID() != id) {
        atual = atual->proximo.get();
    }
    
    // Elemento não encontrado
    if (!atual) {
        return nullptr;
    }
    
    // Elemento encontrado - salvar dados
    auto elementoRemovido = std::move(atual->dados);
    
    // Caso especial: remover o primeiro elemento
    if (atual == cabeca.get()) {
        return removerPrimeiro();
    }
    
    // Caso especial: remover o último elemento
    if (atual == cauda) {
        return removerUltimo();
    }
    
    // Caso geral: remover elemento do meio
    atual->anterior->proximo = std::move(atual->proximo);
    atual->proximo->anterior = atual->anterior;
    
    tamanho--;
    return elementoRemovido;
}

Elemento* ListaDuplamenteEncadeada::buscarPeloId(long id) const {
    No* atual = cabeca.get();
    while (atual) {
        if (atual->dados->getID() == id) {
            return atual->dados.get();
        }
        atual = atual->proximo.get();
    }
    return nullptr;
}

bool ListaDuplamenteEncadeada::alterarPeloId(long id, std::unique_ptr<Elemento> novoElemento) {
    No* atual = cabeca.get();
    while (atual) {
        if (atual->dados->getID() == id) {
            atual->dados = std::move(novoElemento);
            return true;
        }
        atual = atual->proximo.get();
    }
    return false;
}

Elemento* ListaDuplamenteEncadeada::getPrimeiro() const {
    if (estaVazia()) {
        return nullptr;
    }
    
    return cabeca->dados.get();
}

Elemento* ListaDuplamenteEncadeada::getUltimo() const {
    if (estaVazia()) {
        return nullptr;
    }
    
    return cauda->dados.get();
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeada::removerPrimeiro() {
    if (estaVazia()) {
        return nullptr;
    }
    
    auto elementoRemovido = std::move(cabeca->dados);
    
    if (tamanho == 1) {
        // Apenas um elemento
        cabeca = nullptr;
        cauda = nullptr;
    } else {
        // Mais de um elemento
        cabeca = std::move(cabeca->proximo);
        cabeca->anterior = nullptr;
    }
    
    tamanho--;
    return elementoRemovido;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeada::removerUltimo() {
    if (estaVazia()) {
        return nullptr;
    }
    
    auto elementoRemovido = std::move(cauda->dados);
    
    if (tamanho == 1) {
        // Apenas um elemento
        cabeca = nullptr;
        cauda = nullptr;
    } else {
        // Mais de um elemento
        cauda = cauda->anterior;
        cauda->proximo = nullptr;
    }
    
    tamanho--;
    return elementoRemovido;
}

int ListaDuplamenteEncadeada::getTamanho() const {
    return tamanho;
}

bool ListaDuplamenteEncadeada::estaVazia() const {
    return cabeca == nullptr;
}

void ListaDuplamenteEncadeada::imprimirLista() const {
    if (estaVazia()) {
        std::cout << "Lista Duplamente Encadeada vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== LISTA DUPLAMENTE ENCADEADA (Início -> Fim) ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << std::endl;
    
    No* atual = cabeca.get();
    int posicao = 0;
    while (atual) {
        std::cout << "[" << posicao << "] ";
        atual->dados->imprimirInfo();
        std::cout << std::endl;
        atual = atual->proximo.get();
        posicao++;
    }
    
    std::cout << "=== FIM DA LISTA ===" << std::endl;
}

void ListaDuplamenteEncadeada::imprimirListaReversa() const {
    if (estaVazia()) {
        std::cout << "Lista Duplamente Encadeada vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== LISTA DUPLAMENTE ENCADEADA (Fim -> Início) ===" << std::endl;
    std::cout << "Tamanho: " << tamanho << std::endl;
    
    No* atual = cauda;
    int posicao = tamanho - 1;
    while (atual) {
        std::cout << "[" << posicao << "] ";
        atual->dados->imprimirInfo();
        std::cout << std::endl;
        atual = atual->anterior;
        posicao--;
    }
    
    std::cout << "=== FIM DA LISTA REVERSA ===" << std::endl;
}

void ListaDuplamenteEncadeada::limpar() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

Elemento* ListaDuplamenteEncadeada::obterElementoPorPosicao(int posicao) const {
    if (posicao < 0 || posicao >= tamanho) {
        return nullptr;
    }
    
    No* atual = cabeca.get();
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo.get();
    }
    
    return atual->dados.get();
}

bool ListaDuplamenteEncadeada::inserirNaPosicao(int posicao, std::unique_ptr<Elemento> elemento) {
    if (posicao < 0 || posicao > tamanho) {
        return false;
    }
    
    if (posicao == 0) {
        inserirNoInicio(std::move(elemento));
        return true;
    }
    
    if (posicao == tamanho) {
        inserirNoFim(std::move(elemento));
        return true;
    }
    
    // Inserir no meio
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    No* atual = cabeca.get();
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo.get();
    }
    
    novoNo->anterior = atual->anterior;
    novoNo->proximo = std::move(atual->anterior->proximo);
    atual->anterior->proximo = std::move(novoNo);
    atual->anterior = atual->anterior->proximo.get();
    
    tamanho++;
    return true;
}

std::unique_ptr<Elemento> ListaDuplamenteEncadeada::removerDaPosicao(int posicao) {
    if (posicao < 0 || posicao >= tamanho) {
        return nullptr;
    }
    
    if (posicao == 0) {
        return removerPrimeiro();
    }
    
    if (posicao == tamanho - 1) {
        return removerUltimo();
    }
    
    // Remover do meio
    No* atual = cabeca.get();
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo.get();
    }
    
    auto elementoRemovido = std::move(atual->dados);
    
    // Conectar os nós anterior e próximo
    if (atual->anterior) {
        atual->anterior->proximo = std::move(atual->proximo);
    }
    if (atual->proximo) {
        atual->proximo->anterior = atual->anterior;
    }
    
    tamanho--;
    return elementoRemovido;
}
