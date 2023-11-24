#ifndef _e
#define _e

#include "Pokemon.hpp"

class PokemonEletrico : public Pokemon{
    private:
        double potencia_raio;
    public:
        PokemonEletrico(std::string nome, std::string tipo, double dano, double potencia_raio) : Pokemon(nome, tipo, dano),potencia_raio(potencia_raio){};
        void falar_tipo() override;
        virtual double calcular_dano() override;
        double ataque_eletrico();
        
};

#endif