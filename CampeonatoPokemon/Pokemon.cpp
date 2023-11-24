#include "Pokemon.hpp"

void Pokemon::pokedex(){
    cout << "Pokemon: " << this->nome << endl;
    cout << "Tipo ataque: " << this->tipo << endl;
    cout << "Dano: " << this->calcular_dano() << endl;
    cout << "Energia: " << this->vida << endl;
}

string Pokemon::getnome(){
    return this->nome;
}

int Pokemon::getdano(){
    return dano;
}

void Pokemon::status(){
    this->falar_nome();
    cout << "Energia: " << this->vida << endl;
}

void Pokemon::falar_nome(){
    cout << this->nome << "!" << endl;
}

void Pokemon::falar_tipo(){
    cout << this->tipo << "!" << endl;
}

void Pokemon::receber_dano(double dano){
    if(this->vida - dano <= 0){
        cout << this->nome <<  " morreu!" << endl;
    }
    else{
        this->vida -= dano;
    }

}

void Pokemon::atacar(Pokemon* Pokemon){
    this->falar_nome();
    this->falar_tipo();
    cout << "Dano: "<< this->calcular_dano() << endl;
    Pokemon->receber_dano(calcular_dano());
}
