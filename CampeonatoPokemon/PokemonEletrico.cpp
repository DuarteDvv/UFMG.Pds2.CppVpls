#include "PokemonEletrico.hpp"

void PokemonEletrico::falar_tipo(){
    Pokemon::falar_tipo();
    cout << "Bzzzz!" << endl;
}

double PokemonEletrico::calcular_dano(){
    return this->ataque_eletrico();

}

double PokemonEletrico::ataque_eletrico(){
    return  this->potencia_raio * this->getdano();
}