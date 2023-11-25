#include "Hotel.hpp"

Quarto *Hotel::get_quarto_pelo_n(int n_quarto) {
    if (_quartos[n_quarto] == nullptr) {
        throw hotel_excp::quarto_nao_criado(n_quarto);
    }

    return _quartos[n_quarto];
}

Hotel::Hotel(){
    for(int i = 0; i < NUMERO_MAX_QUARTO; i++){
        _quartos[i] = nullptr;
    } 

}
Hotel::~Hotel(){
    for (auto n : _quartos){
        delete n;
    }
}

void Hotel::adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida){
    if(n_quarto < 0 || n_quarto >= 6){
        throw hotel_excp::quarto_nao_existe(n_quarto) ;
    }
    if(_quartos[n_quarto] == nullptr){
        _quartos[n_quarto] = new Quarto(n_quarto);
    }

    get_quarto_pelo_n(n_quarto)->adiciona_reserva(data_entrada, data_saida);

    

}

void Hotel::remove_reserva(int n_quarto, struct std::tm data_entrada){
    if(n_quarto < 0 || n_quarto >= 6){
        throw hotel_excp::quarto_nao_existe(n_quarto) ;
    }
    get_quarto_pelo_n(n_quarto)->remove_reserva(data_entrada);

}

void Hotel::print_info(){
    for (auto n : _quartos){
        n->print_info();
    }
}
