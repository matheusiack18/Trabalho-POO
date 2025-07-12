#include "ArvoreBinariaBusca.h"
#include "../../ConfigLocale.h"
#include <iostream>
#include <iomanip>

ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr), tamanho(0) {}

void ArvoreBinariaBusca::inserir(std::unique_ptr<Elemento> elemento) {
    if (!elemento) {
        return;  // Proteção contra elemento nulo
    }
    
    raiz = inserirRecursivo(std::move(raiz), std::move(elemento));
    tamanho++;
}

std::unique_ptr<ArvoreBinariaBusca::No> ArvoreBinariaBusca::inserirRecursivo(
    std::unique_ptr<No> no, std::unique_ptr<Elemento> elemento) {
    
    // Caso base: posição encontrada para inserção
    if (!no) {
        return std::make_unique<No>(std::move(elemento));
    }
    
    long idElemento = elemento->getID();
    long idNo = no->dados->getID();
    
    if (idElemento < idNo) {
        // Inserir na subárvore esquerda
        no->esquerdo = inserirRecursivo(std::move(no->esquerdo), std::move(elemento));
    } else if (idElemento > idNo) {
        // Inserir na subárvore direita
        no->direito = inserirRecursivo(std::move(no->direito), std::move(elemento));
    }
    // Se idElemento == idNo, não inserir (ID duplicado)
    
    return no;
}

Elemento* ArvoreBinariaBusca::buscarPeloId(long id) const {
    return buscarRecursivo(raiz.get(), id);
}

Elemento* ArvoreBinariaBusca::buscarRecursivo(No* no, long id) const {
    if (!no) {
        return nullptr;  // Elemento não encontrado
    }
    
    long idNo = no->dados->getID();
    
    if (id == idNo) {
        return no->dados.get();  // Elemento encontrado
    } else if (id < idNo) {
        return buscarRecursivo(no->esquerdo.get(), id);  // Buscar na esquerda
    } else {
        return buscarRecursivo(no->direito.get(), id);   // Buscar na direita
    }
}

std::unique_ptr<Elemento> ArvoreBinariaBusca::removerPeloId(long id) {
    auto resultado = removerRecursivo(std::move(raiz), id);
    raiz = std::move(resultado.first);
    
    if (resultado.second) {
        tamanho--;
    }
    
    return std::move(resultado.second);
}

std::pair<std::unique_ptr<ArvoreBinariaBusca::No>, std::unique_ptr<Elemento>>
ArvoreBinariaBusca::removerRecursivo(std::unique_ptr<No> no, long id) {
    
    if (!no) {
        return {nullptr, nullptr};  // Elemento não encontrado
    }
    
    long idNo = no->dados->getID();
    
    if (id < idNo) {
        // Remover da subárvore esquerda
        auto resultado = removerRecursivo(std::move(no->esquerdo), id);
        no->esquerdo = std::move(resultado.first);
        return {std::move(no), std::move(resultado.second)};
        
    } else if (id > idNo) {
        // Remover da subárvore direita
        auto resultado = removerRecursivo(std::move(no->direito), id);
        no->direito = std::move(resultado.first);
        return {std::move(no), std::move(resultado.second)};
        
    } else {
        // Nó encontrado para remoção
        auto elementoRemovido = std::move(no->dados);
        
        // Caso 1: Nó folha (sem filhos)
        if (!no->esquerdo && !no->direito) {
            return {nullptr, std::move(elementoRemovido)};
        }
        
        // Caso 2: Nó com apenas um filho
        if (!no->esquerdo) {
            return {std::move(no->direito), std::move(elementoRemovido)};
        }
        if (!no->direito) {
            return {std::move(no->esquerdo), std::move(elementoRemovido)};
        }
        
        // Caso 3: Nó com dois filhos
        // Encontrar o sucessor in-order (menor elemento da subárvore direita)
        No* sucessor = encontrarMinimo(no->direito.get());
        
        // Copiar os dados do sucessor para o nó atual
        // Aqui precisamos criar uma cópia do elemento do sucessor
        long idSucessor = sucessor->dados->getID();
        
        // Remover o sucessor da subárvore direita
        auto resultadoSucessor = removerRecursivo(std::move(no->direito), idSucessor);
        no->direito = std::move(resultadoSucessor.first);
        
        // Substituir dados do nó atual pelos dados do sucessor
        no->dados = std::move(resultadoSucessor.second);
        
        return {std::move(no), std::move(elementoRemovido)};
    }
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::encontrarMinimo(No* no) const {
    if (!no) {
        return nullptr;
    }
    
    while (no->esquerdo) {
        no = no->esquerdo.get();
    }
    
    return no;
}

void ArvoreBinariaBusca::emOrdem() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "🌳 Árvore vazia!\n";
        return;
    }
    
    std::cout << "🌳 Percurso Em Ordem (Esquerda → Raiz → Direita):\n";
    std::cout << "📊 Elementos em ordem crescente de ID:\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    
    int contador = 0;
    emOrdemRecursivo(raiz.get(), [&contador](Elemento* elemento) {
        std::cout << "[" << contador++ << "] ";
        elemento->imprimirInfo();
        std::cout << "\n";
    });
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}

void ArvoreBinariaBusca::emOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const {
    if (!no) {
        return;
    }
    
    emOrdemRecursivo(no->esquerdo.get(), funcao);  // Esquerda
    funcao(no->dados.get());                       // Raiz
    emOrdemRecursivo(no->direito.get(), funcao);   // Direita
}

void ArvoreBinariaBusca::preOrdem() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "🌳 Árvore vazia!\n";
        return;
    }
    
    std::cout << "🌳 Percurso Pré-Ordem (Raiz → Esquerda → Direita):\n";
    std::cout << "📊 Ordem de construção da árvore:\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    
    int contador = 0;
    preOrdemRecursivo(raiz.get(), [&contador](Elemento* elemento) {
        std::cout << "[" << contador++ << "] ";
        elemento->imprimirInfo();
        std::cout << "\n";
    });
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}

void ArvoreBinariaBusca::preOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const {
    if (!no) {
        return;
    }
    
    funcao(no->dados.get());                       // Raiz
    preOrdemRecursivo(no->esquerdo.get(), funcao); // Esquerda
    preOrdemRecursivo(no->direito.get(), funcao);  // Direita
}

void ArvoreBinariaBusca::posOrdem() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "🌳 Árvore vazia!\n";
        return;
    }
    
    std::cout << "🌳 Percurso Pós-Ordem (Esquerda → Direita → Raiz):\n";
    std::cout << "📊 Ordem de liberação de memória:\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    
    int contador = 0;
    posOrdemRecursivo(raiz.get(), [&contador](Elemento* elemento) {
        std::cout << "[" << contador++ << "] ";
        elemento->imprimirInfo();
        std::cout << "\n";
    });
    
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "📊 Total de elementos: " << getTamanho() << "\n";
}

void ArvoreBinariaBusca::posOrdemRecursivo(No* no, std::function<void(Elemento*)> funcao) const {
    if (!no) {
        return;
    }
    
    posOrdemRecursivo(no->esquerdo.get(), funcao); // Esquerda
    posOrdemRecursivo(no->direito.get(), funcao);  // Direita
    funcao(no->dados.get());                       // Raiz
}

bool ArvoreBinariaBusca::estaVazia() const {
    return tamanho == 0;
}

int ArvoreBinariaBusca::getTamanho() const {
    return tamanho;
}

int ArvoreBinariaBusca::calcularAltura() const {
    return calcularAlturaRecursivo(raiz.get());
}

int ArvoreBinariaBusca::calcularAlturaRecursivo(No* no) const {
    if (!no) {
        return 0;
    }
    
    int alturaEsquerda = calcularAlturaRecursivo(no->esquerdo.get());
    int alturaDireita = calcularAlturaRecursivo(no->direito.get());
    
    return 1 + std::max(alturaEsquerda, alturaDireita);
}

void ArvoreBinariaBusca::limpar() {
    raiz.reset();
    tamanho = 0;
}

void ArvoreBinariaBusca::imprimirArvore() const {
    CONFIGURAR_PORTUGUES();
    
    if (estaVazia()) {
        std::cout << "🌳 Árvore vazia!\n";
        return;
    }
    
    std::cout << "🌳 Estrutura da Árvore Binária de Busca:\n";
    std::cout << "📊 Altura: " << calcularAltura() << " | Tamanho: " << getTamanho() << "\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    
    // Implementação simplificada da visualização
    std::cout << "📊 Visualização por percurso em ordem:\n";
    emOrdemRecursivo(raiz.get(), [](Elemento* elemento) {
        std::cout << "ID: " << elemento->getID() << " ";
    });
    std::cout << "\n";
    
    std::cout << "└─────────────────────────────────────┘\n";
}

Elemento* ArvoreBinariaBusca::encontrarMinimo() const {
    if (estaVazia()) {
        return nullptr;
    }
    
    No* minimo = encontrarMinimo(raiz.get());
    return minimo ? minimo->dados.get() : nullptr;
}

Elemento* ArvoreBinariaBusca::encontrarMaximo() const {
    if (estaVazia()) {
        return nullptr;
    }
    
    No* atual = raiz.get();
    while (atual->direito) {
        atual = atual->direito.get();
    }
    
    return atual->dados.get();
}
