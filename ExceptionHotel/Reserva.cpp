#include "Reserva.hpp"

Reserva::Reserva(struct std::tm data_entrada, struct std::tm data_saida)
    : _data_entrada(data_entrada), _data_saida(data_saida) {

    std::time_t entrada;
    std::time_t saida;
    std::time_t now = std::time(nullptr);
    
    struct std::tm entrada_copy = _data_entrada;
    struct std::tm saida_copy = _data_saida;

    entrada = std::mktime(&entrada_copy);
    saida = std::mktime(&saida_copy);

    if (entrada < now) {
        
        throw reserva_excp::data_entrada_no_passado(data_entrada);
    } else if (entrada > saida) {
        
        throw reserva_excp::data_saida_antecede_entrada(data_entrada, data_saida);
    } else if (saida - entrada < 86400) {
        throw reserva_excp::periodo_muito_curto(data_entrada, data_saida);
    }
}

struct std::tm* Reserva::get_data_entrada() {
    return &_data_entrada;
}

struct std::tm* Reserva::get_data_saida() {
    return &_data_saida;
}

int Reserva::comparar(Reserva& other) {
    time_t thisE = std::mktime(const_cast<struct std::tm*>(get_data_entrada()));
    time_t thisS = std::mktime(const_cast<struct std::tm*>(get_data_saida()));
    time_t E = std::mktime(const_cast<struct std::tm*>(other.get_data_entrada()));
    time_t S = std::mktime(const_cast<struct std::tm*>(other.get_data_saida()));

    if (thisS < E) { // Nova esta depois
        return -1;
    }
    if (S < thisE) { // Nova esta antes
        return 1;
    }

    return 0;
}

void Reserva::print_info() {
    std::cout << "\tEntrada: " << std::put_time(get_data_entrada(), FORMATO_DATA)
              << ", Saida: " << std::put_time(get_data_saida(), FORMATO_DATA) << std::endl;
    std::cout << "------------------" << std::endl;
}
