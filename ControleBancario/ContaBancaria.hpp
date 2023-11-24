#ifndef CB_H
#define CB_H

#include <iostream>
#include <cstring>
using namespace std;

struct Conta
{
    int id;
    string name;
    float Balance;


    Conta* NewAcc(int,string);
    void deposit(float);
    void draft(float);
    void pix(Conta*, float);
    void print(); //2 casas decimais
};


#endif

