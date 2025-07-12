#include "FilaEncadeada.h"
#include "../../ConfigLocale.h"

void FilaEncadeada::enfileirar(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        return;  // Proteção contra elemento nulo
    }
    
    // Inserir no final da lista (final da fila)
    lista.inserirNoFim(std::move(elemento));
}

std::unique_ptr<Elemento> FilaEncadeada::desenfileirar() {
    if (estaVazia()) {
        return nullptr;  // Fila vazia
    }
    
    // Remover do início da lista (frente da fila)
    return lista.removerPrimeiro();
}

Elemento* FilaEncadeada::frente() const {
    if (estaVazia()) {
        return nullptr;  // Fila vazia
    }
    
    // Buscar o primeiro elemento da lista (frente da fila)
    return lista.getPrimeiro();
}

bool FilaEncadeada::estaVazia() const {
    return lista.getTamanho() == 0;
}

int FilaEncadeada::getTamanho() const {
    return lista.getTamanho();
}

void FilaEncadeada::limpar() {
    lista.limpar();
}

void FilaEncadeada::imprimirFila() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "📭 Fila vazia!\n";
        return;
    }
    
    std::cout << "🚶 Fila (da frente para trás):\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│ FRENTE                         FINAL │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    
    // Usar o método de impressão da lista que imprime do início ao fim
    // Como inserimos no fim e removemos do início, isso mostra FIFO corretamente
    lista.imprimirLista();
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}
