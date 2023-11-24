#include "Hotel.hpp"

Quarto *Hotel::get_quarto_pelo_n(int n_quarto) {
    if (n_quarto < 0 || n_quarto >= _quartos.size()) {
        throw hotel_excp::quarto_nao_criado(n_quarto);
    }

    return _quartos[n_quarto];
}

Hotel::Hotel(){
    _quartos = {};

}
Hotel::~Hotel(){
    for (auto n : _quartos){
        delete n;
    }
}

void adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida){
    if(n_quarto < 0 || n_quarto >= 6){
        throw hotel_excp::quarto_nao_existe(n_quarto) ;
    }

}

void remove_reserva(int n_quarto, struct std::tm data_entrada){

}

void print_info(){

}
