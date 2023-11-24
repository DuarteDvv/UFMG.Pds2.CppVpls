#include "PokemonAquatico.hpp"

void PokemonAquatico::falar_tipo(){
    Pokemon::falar_tipo();
    cout << "Splash!" << endl;

}double PokemonAquatico::calcular_dano(){
    return this->ataque_aquatico();

}

double PokemonAquatico::ataque_aquatico(){
    return  this->litros_jato + this->getdano();
}