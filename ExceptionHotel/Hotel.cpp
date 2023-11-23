#include "Hotel.hpp"

Quarto *Hotel::get_quarto_pelo_n(int n_quarto) {
    if (n_quarto < 0 || n_quarto >= _quartos.size()) {
        throw hotel_excp::quarto_nao_criado(n_quarto);
    }

    return _quartos[n_quarto];
}

Hotel::Hotel(){
    _quartos.push_back(new Quarto*);

}
Hotel::~Hotel(){
    for (auto n : _quartos){
        delete n;
    }
}
