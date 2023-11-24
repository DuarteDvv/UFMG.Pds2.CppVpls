#ifndef B_H
#define B_H

#include <iostream>
#include <cstring>
#include "ContaBancaria.hpp"
using namespace std;

struct Banco
{
    int Ncontas;
    Conta *contas[20];

    void start();
    bool AccCrea(int,string);
    Conta* search(int);
    void data();

};


#endif