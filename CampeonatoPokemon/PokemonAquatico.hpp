#ifndef _a
#define _a

#include "Pokemon.hpp"

class PokemonAquatico : public Pokemon{
    private:
        double litros_jato;
    public:
        PokemonAquatico(std::string nome, std::string tipo, double dano, double litros_jato) : Pokemon(nome, tipo, dano), litros_jato(litros_jato){};
        void falar_tipo() override;
        virtual double calcular_dano() override;
        double ataque_aquatico();
        
};

#endif