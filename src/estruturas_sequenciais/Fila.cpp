#include "Fila.h"
#include <iostream>

Fila::Fila(int capacidade) 
    : lista(capacidade), capacidadeMaxima(capacidade) {
}

bool Fila::enfileirar(std::unique_ptr<Elemento> elemento) {
    if (filaCheia()) {
        return false;
    }
    
    lista.InserirNoFinal(std::move(elemento));
    return true;
}

std::unique_ptr<Elemento> Fila::desenfileirar() {
    if (filaVazia()) {
        return nullptr;
    }
    
    return lista.RemoverPrimeiro();
}

Elemento* Fila::consultarFrente() const {
    if (filaVazia()) {
        return nullptr;
    }
    
    // A frente da fila é o primeiro elemento da lista
    return lista.obterElementoPorIndice(0);
}

bool Fila::filaVazia() const {
    return lista.estaVazia();
}

bool Fila::filaCheia() const {
    return lista.getTamanho() >= capacidadeMaxima;
}

int Fila::getTamanho() const {
    return lista.getTamanho();
}

int Fila::getCapacidadeMaxima() const {
    return capacidadeMaxima;
}

void Fila::imprimirFila() const {
    if (filaVazia()) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== FILA (Frente -> Final) ===" << std::endl;
    // Imprime da frente (primeiro) para o final (último)
    for (int i = 0; i < lista.getTamanho(); i++) {
        Elemento* elem = lista.obterElementoPorIndice(i);
        if (elem) {
            if (i == 0) {
                std::cout << "[FRENTE] ";
            }
            elem->imprimirInfo();
            std::cout << std::endl;
        }
    }
    std::cout << "=== FIM DA FILA ===" << std::endl;
}

void Fila::limpar() {
    lista.limpar();
}
