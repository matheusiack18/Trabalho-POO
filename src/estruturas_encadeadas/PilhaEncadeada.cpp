#include "PilhaEncadeada.h"
#include "../../ConfigLocale.h"

void PilhaEncadeada::empilhar(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        return;  // Proteção contra elemento nulo
    }
    
    // Inserir no início da lista (topo da pilha)
    lista.inserirNoInicio(std::move(elemento));
}

std::unique_ptr<Elemento> PilhaEncadeada::desempilhar() {
    if (estaVazia()) {
        return nullptr;  // Pilha vazia
    }
    
    // Remover do início da lista (topo da pilha)
    return lista.removerPrimeiro();
}

Elemento* PilhaEncadeada::topo() const {
    if (estaVazia()) {
        return nullptr;  // Pilha vazia
    }
    
    // Buscar o primeiro elemento da lista (topo da pilha)
    return lista.getPrimeiro();
}

bool PilhaEncadeada::estaVazia() const {
    return lista.getTamanho() == 0;
}

int PilhaEncadeada::getTamanho() const {
    return lista.getTamanho();
}

void PilhaEncadeada::limpar() {
    lista.limpar();
}

void PilhaEncadeada::imprimirPilha() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "📥 Pilha vazia!\n";
        return;
    }
    
    std::cout << "📚 Pilha (do topo para a base):\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    
    // Usar o método de impressão da lista que já imprime do início ao fim
    // Como inserimos no início, isso mostra do topo para a base
    lista.imprimirLista();
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}
