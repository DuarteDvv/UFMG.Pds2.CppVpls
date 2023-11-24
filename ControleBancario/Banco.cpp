#include "Banco.hpp"
#include <iostream>

void Banco::start(){
    Ncontas = 0;
    for(int i = 0; i < 20; i++){
        contas[i] = nullptr;
    }
}

bool Banco::AccCrea(int id, string name){
    for(int i = 0; i < Ncontas; i++){
        if(contas[i]->id == id){
            return false;
        }
    }

    contas[Ncontas] = contas[Ncontas]->NewAcc(id,name);
    Ncontas++;
    return true;
}

Conta* Banco::search(int id){
    for(int i = 0; i < Ncontas; i++){
        if(contas[i]->id == id){
            return contas[i];
        }
    }
    
    return nullptr;
}

void Banco::data(){
    for(int i = 0;i<Ncontas; i++){
        contas[i]->print();
    }

}