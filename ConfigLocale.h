#ifndef CONFIG_LOCALE_H
#define CONFIG_LOCALE_H

#include <iostream>
#include <locale>
#include <locale.h>

/**
 * @brief Configuração global de locale
 */

namespace ConfigLocale {
    /**
     * @brief Configura o locale para português brasileiro
     */
    inline void configurarPortugues() {
        try {
            setlocale(LC_ALL, "Portuguese");
            setlocale(LC_ALL, "pt_BR.UTF-8");
            setlocale(LC_ALL, "pt_BR");
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            
            // Configuração C++ streams
            std::locale::global(std::locale(""));
            std::cout.imbue(std::locale());
            std::cerr.imbue(std::locale());
            
        } catch (...) {
            setlocale(LC_ALL, "C");
        }
        
        #ifdef _WIN32
            system("chcp 65001 >nul 2>&1");
        #endif
    }
}

#define CONFIGURAR_PORTUGUES() ConfigLocale::configurarPortugues()

#endif
