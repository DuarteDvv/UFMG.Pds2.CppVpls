#include "Quarto.hpp"
#include <algorithm>

Quarto::Quarto(int n) : _n_quarto(n) {
    _reservas = {};
}

Quarto::~Quarto() {
    for (auto n : _reservas) {
        delete n; 
    }
}

int Quarto::get_n_quarto() {
    return this->_n_quarto;
}

std::vector<Reserva *> *Quarto::get_reservas() {
    return &this->_reservas;
}

void Quarto::adiciona_reserva(struct std::tm data_entrada, struct std::tm data_saida) {
    Reserva *novaReserva = new Reserva(data_entrada, data_saida);

    for (auto it = _reservas.begin(); it != _reservas.end(); it++) {
        if ((*it)->comparar(*novaReserva) == 0) {
            throw quarto_excp::reserva_indisponivel(data_entrada, data_saida);
        } else if ((*it)->comparar(*novaReserva) == 1) {
            _reservas.insert(it, novaReserva);
            return; // Reserva adicionada, encerra a função
        }
    }

    // Se chegou aqui, significa que a nova reserva é a mais recente
    _reservas.push_back(novaReserva);
}

void Quarto::remove_reserva(struct std::tm data_inicio) {
    auto it = std::remove_if(_reservas.begin(), _reservas.end(),
                             [&data_inicio](Reserva *r) {
                                 time_t nData = mktime(r->get_data_entrada());
                                 time_t DataE = mktime(&data_inicio);
                                 return nData == DataE;
                             });

    if (it != _reservas.end()) {
        _reservas.erase(it, _reservas.end());
    } else {
        throw quarto_excp::reserva_nao_encontrada(this->get_n_quarto(), data_inicio);
    }
}

void Quarto::print_info() {
    std::cout << "Quarto " << _n_quarto << " ---------" << _reservas.size() << std::endl;
    for (auto n = _reservas.begin(); n != _reservas.end(); n++) {
        (*n)->print_info();
    }
}
