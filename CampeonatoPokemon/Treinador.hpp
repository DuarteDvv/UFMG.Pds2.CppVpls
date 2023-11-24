#ifndef _t
#define _t
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"

class treinador {
    private:
        string nome;
        vector<Pokemon*> pokemons;



    public:

    treinador(string nome) : nome(nome) { pokemons = {}; };
    
    string getNome();
    void cadastrar_pokemon_eletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio);
    void cadastrar_pokemon_aquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato);
    void cadastrar_pokemon_explosivo(string nome, string tipo_ataque, double forca_ataque, double temperatura_explosao);
    void imprimir_informacoes();
    Pokemon* usar_pokemon(int idpk);


};

#endif