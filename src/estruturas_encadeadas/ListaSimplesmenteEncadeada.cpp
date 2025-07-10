#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() 
    : cabeca(nullptr), cauda(nullptr), tamanho(0) {
}

void ListaSimplesmenteEncadeada::inserirNoInicio(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - primeiro elemento é tanto cabeça quanto cauda
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
    } else {
        // Lista não vazia - novo nó aponta para a antiga cabeça
        novoNo->proximo = std::move(cabeca);
        cabeca = std::move(novoNo);
    }
    
    tamanho++;
}

void ListaSimplesmenteEncadeada::inserirNoFim(std::unique_ptr<Elemento> elemento) {
    auto novoNo = std::make_unique<No>(std::move(elemento));
    
    if (estaVazia()) {
        // Lista vazia - primeiro elemento é tanto cabeça quanto cauda
        cabeca = std::move(novoNo);
        cauda = cabeca.get();
    } else {
        // Lista não vazia - cauda atual aponta para o novo nó
        cauda->proximo = std::move(novoNo);
        cauda = cauda->proximo.get();
    }
    
    tamanho++;
}

std::unique_ptr<Elemento> ListaSimplesmenteEncadeada::removerPeloId(long id) {
    if (estaVazia()) {
        return nullptr;
    }
    
    // Caso especial: remover o primeiro elemento
    if (cabeca->dados->getID() == id) {
        return removerPrimeiro();
    }
    
    // Buscar o elemento nas demais posições
    No* atual = cabeca.get();
    while (atual->proximo && atual->proximo->dados->getID() != id) {
        atual = atual->proximo.get();
    }
    
    // Elemento não encontrado
    if (!atual->proximo) {
        return nullptr;
    }
    
    // Elemento encontrado
    auto elementoRemovido = std::move(atual->proximo->dados);
    auto noRemovido = std::move(atual->proximo);
    atual->proximo = std::move(noRemovido->proximo);
    
    // Atualizar cauda se necessário
    if (cauda == noRemovido.get()) {
        cauda = atual;
    }
    
    tamanho--;
    return elementoRemovido;
}

Elemento* ListaSimplesmenteEncadeada::buscarPeloId(long id) const {
    No* atual = cabeca.get();
    while (atual) {
        if (atual->dados->getID() == id) {
            return atual->dados.get();
        }
        atual = atual->proximo.get();
    }
    return nullptr;
}

bool ListaSimplesmenteEncadeada::alterarPeloId(long id, std::unique_ptr<Elemento> novoElemento) {
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

std::unique_ptr<Elemento> ListaSimplesmenteEncadeada::removerPrimeiro() {
    if (estaVazia()) {
        return nullptr;
    }
    
    auto elementoRemovido = std::move(cabeca->dados);
    auto noRemovido = std::move(cabeca);
    cabeca = std::move(noRemovido->proximo);
    
    // Atualizar cauda se a lista ficou vazia
    if (!cabeca) {
        cauda = nullptr;
    }
    
    tamanho--;
    return elementoRemovido;
}

std::unique_ptr<Elemento> ListaSimplesmenteEncadeada::removerUltimo() {
    if (estaVazia()) {
        return nullptr;
    }
    
    // Caso especial: apenas um elemento
    if (tamanho == 1) {
        return removerPrimeiro();
    }
    
    // Encontrar o penúltimo elemento
    No* atual = cabeca.get();
    while (atual->proximo.get() != cauda) {
        atual = atual->proximo.get();
    }
    
    // Remover o último elemento
    auto elementoRemovido = std::move(cauda->dados);
    atual->proximo = nullptr;
    cauda = atual;
    
    tamanho--;
    return elementoRemovido;
}

int ListaSimplesmenteEncadeada::getTamanho() const {
    return tamanho;
}

bool ListaSimplesmenteEncadeada::estaVazia() const {
    return cabeca == nullptr;
}

void ListaSimplesmenteEncadeada::imprimirLista() const {
    if (estaVazia()) {
        std::cout << "Lista Simplesmente Encadeada vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== LISTA SIMPLESMENTE ENCADEADA ===" << std::endl;
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

void ListaSimplesmenteEncadeada::limpar() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

Elemento* ListaSimplesmenteEncadeada::obterElementoPorPosicao(int posicao) const {
    if (posicao < 0 || posicao >= tamanho) {
        return nullptr;
    }
    
    No* atual = cabeca.get();
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo.get();
    }
    
    return atual->dados.get();
}

template<typename Condicao>
int ListaSimplesmenteEncadeada::contarElementos(Condicao condicao) const {
    int contador = 0;
    No* atual = cabeca.get();
    while (atual) {
        if (condicao(atual->dados.get())) {
            contador++;
        }
        atual = atual->proximo.get();
    }
    return contador;
}
