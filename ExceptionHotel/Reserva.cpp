#include "Reserva.hpp"


Reserva::Reserva(struct std::tm data_entrada, struct std::tm data_saida) : _data_entrada(data_entrada), _data_saida(data_saida){
    time_t now = std::time(0);
    time_t entrada = mktime(get_data_entrada());
    time_t saida = mktime(get_data_saida());

    if(entrada < now){
        throw reserva_excp::data_entrada_no_passado(data_entrada);
    }

    if(entrada > saida){
        throw reserva_excp::data_saida_antecede_entrada(data_entrada,data_saida);

    }

    if(saida - entrada < 86400 ){
        throw reserva_excp::periodo_muito_curto(data_entrada,data_saida);

    }
}

struct std::tm *Reserva::get_data_entrada(){
    return &_data_entrada;
}
struct std::tm *Reserva::get_data_saida(){
    return &_data_saida;

}
int Reserva::comparar(Reserva& other){
    time_t thisE = mktime(this->get_data_entrada());
    time_t thisS = mktime(this->get_data_saida());
    time_t E = mktime(other.get_data_entrada());
    time_t S = mktime(other.get_data_saida());


    if(thisS < E){
        return -1;
    }
    if(S < thisE){
        return 1;
    }

    return 0;

}
void Reserva::print_info(){
    std::cout << "\tEntrada: " << get_data_entrada() <<", Saida: " << get_data_saida() << std::endl;
    std::cout << "------------------";
}
