#include "Quarto.hpp"

std::vector<Reserva*> * Quarto::get_reservas(){
    return &this->_reservas;
}

void Quarto::adiciona_reserva(struct std::tm data_entrada, struct std::tm data_saida){
    Reserva* R = new Reserva(data_entrada,data_saida);
    for(auto n : _reservas){
        if(R->comparar(*n) == 0){
            throw quarto_excp::reserva_indisponivel(data_entrada,data_saida);
        }


        
    }
        


}

void Quarto::remove_reserva(struct std::tm data_inicio){
    for(auto n : _reservas){
        time_t nData = mktime(n->get_data_entrada());
        time_t DataE = mktime(&data_inicio);
        if(nData == DataE){
            delete n;
            n = nullptr;
        }
    }

    throw quarto_excp::reserva_nao_encontrada(this->get_n_quarto(),data_inicio);

}

void Quarto::print_info(){
    std::cout << "Quarto " << _n_quarto << " ---------" << std::endl;
    for(auto n : _reservas){
        n->print_info();
    }

}

Quarto::Quarto(int n){
    this->_reservas = {};
    this->_n_quarto = n;
}

Quarto::~Quarto(){
    for(auto n : _reservas){
        delete n;
    }

}