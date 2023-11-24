#ifndef _x
#define _x
#include "Pokemon.hpp"

class PokemonExplosivo : public Pokemon{
    private:
        double temperatura_explosao;
    public:
        PokemonExplosivo(std::string nome, std::string tipo, double dano, double temperatura_explosao) : Pokemon(nome, tipo, dano), temperatura_explosao(temperatura_explosao){};

        void falar_tipo() override;
        virtual double calcular_dano() override;
        double ataque_explosivo();

};
#endif