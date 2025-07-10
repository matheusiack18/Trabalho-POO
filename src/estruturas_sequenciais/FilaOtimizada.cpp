#include "FilaOtimizada.h"
#include <iostream>

FilaOtimizada::FilaOtimizada(int capacidade) 
    : capacidade(capacidade), inicio(0), fim(0), tamanho(0) {
    buffer = new std::unique_ptr<Elemento>[capacidade];
}

FilaOtimizada::~FilaOtimizada() {
    limpar();
    delete[] buffer;
}

FilaOtimizada::FilaOtimizada(const FilaOtimizada& outra) 
    : capacidade(outra.capacidade), inicio(0), fim(0), tamanho(0) {
    buffer = new std::unique_ptr<Elemento>[capacidade];
    
    // NOTA: Para cópia com unique_ptr, precisaríamos de um método clone
    // Por simplicidade, esta versão não suporta cópia completa
    // Em uma implementação completa, seria necessário implementar clone()
    std::cout << "Aviso: Cópia de FilaOtimizada resulta em fila vazia" << std::endl;
}

FilaOtimizada& FilaOtimizada::operator=(const FilaOtimizada& outra) {
    if (this != &outra) {
        // Limpa a fila atual
        limpar();
        delete[] buffer;
        
        // Recria com a nova capacidade
        capacidade = outra.capacidade;
        inicio = 0;
        fim = 0;
        tamanho = 0;
        buffer = new std::unique_ptr<Elemento>[capacidade];
        
        // NOTA: Para cópia com unique_ptr, precisaríamos de um método clone
        // Por simplicidade, esta versão não suporta cópia completa
        std::cout << "Aviso: Atribuição de FilaOtimizada resulta em fila vazia" << std::endl;
    }
    return *this;
}

int FilaOtimizada::proximoIndice(int indice) const {
    return (indice + 1) % capacidade;
}

bool FilaOtimizada::enfileirar(std::unique_ptr<Elemento> elemento) {
    if (filaCheia()) {
        return false;
    }
    
    buffer[fim] = std::move(elemento);
    fim = proximoIndice(fim);
    tamanho++;
    return true;
}

std::unique_ptr<Elemento> FilaOtimizada::desenfileirar() {
    if (filaVazia()) {
        return nullptr;
    }
    
    std::unique_ptr<Elemento> elemento = std::move(buffer[inicio]);
    inicio = proximoIndice(inicio);
    tamanho--;
    return elemento;
}

Elemento* FilaOtimizada::consultarFrente() const {
    if (filaVazia()) {
        return nullptr;
    }
    
    return buffer[inicio].get();
}

bool FilaOtimizada::filaVazia() const {
    return tamanho == 0;
}

bool FilaOtimizada::filaCheia() const {
    return tamanho == capacidade;
}

int FilaOtimizada::getTamanho() const {
    return tamanho;
}

int FilaOtimizada::getCapacidade() const {
    return capacidade;
}

void FilaOtimizada::imprimirFila() const {
    if (filaVazia()) {
        std::cout << "Fila otimizada vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== FILA OTIMIZADA (Frente -> Final) ===" << std::endl;
    int indiceAtual = inicio;
    for (int i = 0; i < tamanho; i++) {
        if (buffer[indiceAtual]) {
            if (i == 0) {
                std::cout << "[FRENTE] ";
            }
            buffer[indiceAtual]->imprimirInfo();
            std::cout << std::endl;
        }
        indiceAtual = proximoIndice(indiceAtual);
    }
    std::cout << "=== FIM DA FILA OTIMIZADA ===" << std::endl;
}

void FilaOtimizada::limpar() {
    while (!filaVazia()) {
        desenfileirar();
    }
}
