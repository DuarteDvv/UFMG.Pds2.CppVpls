#include <iostream>
#include <iomanip>
#include "ContaBancaria.hpp"

Conta* Conta::NewAcc(int id,string name){
    Conta* A = new Conta;
    A->id = id;
    A->name = name;
    A->Balance = 0;
    
    return A;
}

void Conta::deposit(float value){
    this->Balance += value;

}

void Conta::draft(float value){
    this->Balance -= value;

}

void Conta::pix(Conta* destino, float value){
    this->Balance -= value;
    destino->Balance += value;
}

void Conta::print(){
    cout << fixed << this->id << ' ' << this->name << setprecision(2) << ' ' << this->Balance << endl;

}