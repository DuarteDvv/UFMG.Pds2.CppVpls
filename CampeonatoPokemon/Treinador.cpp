#include "Treinador.hpp"

void treinador::imprimir_informacoes(){
    if(this->pokemons.empty()){
        cout << "Nome: " << this->nome << endl << "----------" << endl;
        cout << "Nenhum Pokemon cadastrado!" << endl << "----------" << endl;
    }
    else{
        cout << "Nome: " << this->nome << endl << "----------" << endl;
        for(Pokemon* n : pokemons){
            n->pokedex();
            cout << "----------";
        }

    }


}

void treinador::cadastrar_pokemon_eletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio){

    Pokemon* p = new PokemonEletrico(nome,tipo_ataque,forca_ataque,potencia_raio);
    this->pokemons.push_back(p);
}

void treinador::cadastrar_pokemon_aquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato){

    Pokemon* p = new PokemonAquatico(nome,tipo_ataque,forca_ataque,litros_jato);
    this->pokemons.push_back(p);
}

void treinador::cadastrar_pokemon_explosivo(string nome, string tipo_ataque, double forca_ataque, double temperatura_explosao){

    Pokemon* p = new PokemonExplosivo(nome,tipo_ataque,forca_ataque,temperatura_explosao);
    this->pokemons.push_back(p);
}

Pokemon* treinador::usar_pokemon(int idpk){
    return pokemons[idpk];

}

string treinador::getNome(){
    return this->nome; 
}

