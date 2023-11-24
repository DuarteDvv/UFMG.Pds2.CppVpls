#include "Campeonato.hpp"

void Campeonato::cadastrar_treinador(string nome){
    treinador* t = new treinador(nome);
    this->treiadores.push_back(t);
}

void Campeonato::imprimir_informacoes_treinador(int idt){
    this->treiadores[idt]->imprimir_informacoes();
}

void Campeonato::cadastrar_pokemon_eletrico(int idt,string nome, string tipo_ataque, double forca_ataque, double potencia_raio){
    this->treiadores[idt]->cadastrar_pokemon_eletrico(nome,tipo_ataque,forca_ataque,potencia_raio);
}

void Campeonato::cadastrar_pokemon_aquatico(int idt, string nome, string tipo_ataque, double forca_ataque, double litros_jato){
    this->treiadores[idt]->cadastrar_pokemon_aquatico(nome,tipo_ataque,forca_ataque,litros_jato);

}

 void Campeonato::cadastrar_pokemon_explosivo(int idt, string nome, string tipo_ataque, double forca_ataque, double temperatura_explosao){
    this->treiadores[idt]->cadastrar_pokemon_explosivo(nome,tipo_ataque,forca_ataque,temperatura_explosao);
 }

 void Campeonato::executar_batalha(int idt1, int idpk1, int idt2, int idpk2){
    cout << "### Batalha ###" << endl;
    cout << treiadores[idt1]->getNome() << " (" << treiadores[idt1]->usar_pokemon(idpk1)->getnome() << ")" << " vs. " << treiadores[idt2]->getNome() << " (" << treiadores[idt2]->usar_pokemon(idpk2)->getnome() << ")" << endl;
    treiadores[idt1]->usar_pokemon(idpk1)->atacar(treiadores[idt2]->usar_pokemon(idpk2));
    treiadores[idt2]->usar_pokemon(idpk2)->status();
    cout << "#########" << endl;
 }