#ifndef HEAPINT_
#define HEAPINT_

#include <iostream>

class HeapInt {
private:
    int *data;

public:
    // Construtor sem parâmetros
    HeapInt();

    // Construtor que recebe um inteiro como parâmetro
    HeapInt(int);

    // Construtor de cópia
    HeapInt(const HeapInt &);

    // Destrutor
    ~HeapInt();

    // Sobrecarga do operador de atribuição para int
    HeapInt& operator=(int);

    // Sobrecarga do operador de atribuição para HeapInt
    HeapInt& operator=(const HeapInt &);

    // Sobrecarga da operação de soma
    HeapInt operator+(const HeapInt &) const;

    // Sobrecarga da operação de subtração
    HeapInt operator-(const HeapInt &) const;

    // Sobrecarga da operação de igualdade
    bool operator==(const HeapInt &o) const;

    // Sobrecarga do operador de saída
    friend std::ostream& operator<<(std::ostream &out, const HeapInt &heapInt);

    // Sobrecarga do operador de entrada
    friend std::istream& operator>>(std::istream &in, HeapInt &heapInt);
};

#endif 