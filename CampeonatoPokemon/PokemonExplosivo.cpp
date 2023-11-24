#include "PokemonExplosivo.hpp"

void PokemonExplosivo::falar_tipo(){
    Pokemon::falar_tipo();
    cout << "Boom!" << endl;
}

double PokemonExplosivo::calcular_dano(){
    return this->ataque_explosivo();

}

double PokemonExplosivo::ataque_explosivo(){
    return this->getdano()/ this->temperatura_explosao;
}