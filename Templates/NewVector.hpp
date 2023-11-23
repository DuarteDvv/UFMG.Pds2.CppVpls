#ifndef _VET
#define _VET

#include <iostream>

template <typename T>
class Vetor {
private:
    T* vetor;
    int tamanho;
    int elementos;

public:
    // Construtor que recebe um inteiro n como parâmetro
    Vetor(int n) : tamanho(n), elementos(0) {
        vetor = new T[tamanho];
    }

    // Construtor de cópia
    Vetor(const Vetor& v) : tamanho(v.tamanho), elementos(v.elementos) {
        vetor = new T[tamanho];
        for (int i = 0; i < elementos; ++i) {
            vetor[i] = v.vetor[i];
        }
    }

    // Destrutor
    ~Vetor() {
        delete[] vetor;
    }

    // Método SetElemento
    void SetElemento(int i, T x) {
        if (i >= 0 && i < tamanho) {
            vetor[i] = x;
            elementos = std::max(elementos, i + 1);
        }
    }

    // Método GetElemento
    T GetElemento(int i) const {
        if (i >= 0 && i < elementos) {
            return vetor[i];
        }
        return T();  // Retorna valor padrão para tipos primitivos
    }

    // Método AdicionaElemento
    void AdicionaElemento(T x) {
        if (elementos < tamanho) {
            vetor[elementos] = x;
            ++elementos;
        }
    }

    // Método Imprime
    void Imprime() const {
        for (int i = 0; i < elementos; ++i) {
            std::cout << vetor[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif 
