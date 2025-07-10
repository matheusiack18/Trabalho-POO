#include "Pilha.h"
#include <iostream>

Pilha::Pilha(int capacidade) 
    : lista(capacidade), capacidadeMaxima(capacidade) {
}

bool Pilha::empilhar(std::unique_ptr<Elemento> elemento) {
    if (pilhaCheia()) {
        return false;
    }
    
    lista.InserirNoFinal(std::move(elemento));
    return true;
}

std::unique_ptr<Elemento> Pilha::desempilhar() {
    if (pilhaVazia()) {
        return nullptr;
    }
    
    return lista.RemoverUltimo();
}

Elemento* Pilha::consultarTopo() const {
    if (pilhaVazia()) {
        return nullptr;
    }
    
    // O topo da pilha é o último elemento da lista
    int ultimoIndice = lista.getTamanho() - 1;
    return lista.obterElementoPorIndice(ultimoIndice);
}

bool Pilha::pilhaVazia() const {
    return lista.estaVazia();
}

bool Pilha::pilhaCheia() const {
    return lista.getTamanho() >= capacidadeMaxima;
}

int Pilha::getTamanho() const {
    return lista.getTamanho();
}

int Pilha::getCapacidadeMaxima() const {
    return capacidadeMaxima;
}

void Pilha::imprimirPilha() const {
    if (pilhaVazia()) {
        std::cout << "Pilha vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== PILHA (Topo -> Base) ===" << std::endl;
    // Imprime do topo (último) para a base (primeiro)
    for (int i = lista.getTamanho() - 1; i >= 0; i--) {
        Elemento* elem = lista.obterElementoPorIndice(i);
        if (elem) {
            if (i == lista.getTamanho() - 1) {
                std::cout << "[TOPO] ";
            }
            elem->imprimirInfo();
            std::cout << std::endl;
        }
    }
    std::cout << "=== FIM DA PILHA ===" << std::endl;
}

void Pilha::limpar() {
    lista.limpar();
}
