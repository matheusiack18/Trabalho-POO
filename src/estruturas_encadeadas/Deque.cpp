#include "Deque.h"
#include "../../ConfigLocale.h"

void Deque::inserirInicio(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        return;  // Proteção contra elemento nulo
    }
    
    // Inserir no início da lista dupla (frente do deque)
    lista.inserirNoInicio(std::move(elemento));
}

void Deque::inserirFim(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        return;  // Proteção contra elemento nulo
    }
    
    // Inserir no final da lista dupla (final do deque)
    lista.inserirNoFim(std::move(elemento));
}

std::unique_ptr<Elemento> Deque::removerInicio() {
    if (estaVazio()) {
        return nullptr;  // Deque vazio
    }
    
    // Remover do início da lista dupla (frente do deque)
    return lista.removerPrimeiro();
}

std::unique_ptr<Elemento> Deque::removerFim() {
    if (estaVazio()) {
        return nullptr;  // Deque vazio
    }
    
    // Remover do final da lista dupla (final do deque)
    // VANTAGEM da lista dupla: remoção do final em O(1)!
    return lista.removerUltimo();
}

Elemento* Deque::inicio() const {
    if (estaVazio()) {
        return nullptr;  // Deque vazio
    }
    
    // Buscar o primeiro elemento da lista (frente do deque)
    return lista.getPrimeiro();
}

Elemento* Deque::fim() const {
    if (estaVazio()) {
        return nullptr;  // Deque vazio
    }
    
    // Buscar o último elemento da lista (final do deque)
    return lista.getUltimo();
}

bool Deque::estaVazio() const {
    return lista.getTamanho() == 0;
}

int Deque::getTamanho() const {
    return lista.getTamanho();
}

void Deque::limpar() {
    lista.limpar();
}

void Deque::imprimirDeque() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazio()) {
        std::cout << "📦 Deque vazio!\n";
        return;
    }
    
    std::cout << "⬌ Deque (do início ao fim):\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│ INÍCIO                         FIM │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    
    // Usar o método de impressão da lista dupla
    lista.imprimirLista();
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}

void Deque::imprimirDequeReverso() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazio()) {
        std::cout << "📦 Deque vazio!\n";
        return;
    }
    
    std::cout << "⬌ Deque (do fim ao início - ordem reversa):\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│ FIM                         INÍCIO │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    
    // Usar o método de impressão reversa específico da lista dupla
    // VANTAGEM da lista duplamente encadeada!
    lista.imprimirListaReversa();
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}
