#ifndef _po
#define _po

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon{
    private:
        string nome;
        string tipo;
        double dano;
        double vida = 100;

    public:

        Pokemon(string nome, string tipo, double dano) : nome(nome), tipo(tipo), dano(dano){};

        int getdano();
        string getnome();
        void falar_nome();
        virtual void falar_tipo();
        void status();
        void pokedex();
        virtual double calcular_dano() = 0 ;
        void atacar(Pokemon* Pokemon);
        void receber_dano(double valor_dano);
        
};

#endif