#include "Hotel.hpp"

Hotel::Hotel() {
    for (int i = 0; i < 6; i++) {
        _quartos.push_back(nullptr);
    }
}

Hotel::~Hotel() {
    for (auto n : _quartos) {
        if (n != nullptr) {
            delete n;
        }
    }
}

std::vector<Quarto *> *Hotel::get_quartos() {
    return &_quartos;
}

Quarto *Hotel::get_quarto_pelo_n(int n_quarto) {
    for (auto i : _quartos) {
        if(i != nullptr){
            if (i->get_n_quarto() == n_quarto) {
                return i;
            }
        }
    }
    return nullptr;
}

void Hotel::adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida) {
    if (n_quarto < 0 || n_quarto >= 6) {
        throw hotel_excp::quarto_nao_existe(n_quarto);
    }

    Quarto* Q = get_quarto_pelo_n(n_quarto);
    if (Q == nullptr) {
        Q = new Quarto(n_quarto);
        Q->adiciona_reserva(data_entrada, data_saida);
        _quartos.push_back(Q);
    }
    else{
        Q->adiciona_reserva(data_entrada, data_saida);
    }
}

void Hotel::remove_reserva(int n_quarto, struct std::tm data_entrada) {
    if (n_quarto < 0 || n_quarto >= 6) {
        throw hotel_excp::quarto_nao_existe(n_quarto);
    }

    Quarto* Q = get_quarto_pelo_n(n_quarto);
    if (Q == nullptr) {
        Q = new Quarto(n_quarto);
        _quartos.push_back(Q);
        throw hotel_excp::quarto_nao_criado(n_quarto);
    }

    Q->remove_reserva(data_entrada);
}

void Hotel::print_info() {
    for (auto n : _quartos) {
        if (n != nullptr && !n->get_reservas()->empty()) {
            n->print_info();
        }
    }
}
