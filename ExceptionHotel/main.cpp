#include <iostream>
#include "Hotel.hpp"


int main() {
    Hotel hotel;

    try {
        char command;
        int n_quarto;
        struct std::tm data_entrada, data_saida;

        while (std::cin >> command) {
            switch (command) {
                case 'a':
                    std::cin >> n_quarto >> std::get_time(&data_entrada, FORMATO_DATA) >> std::get_time(&data_saida, FORMATO_DATA);
                    hotel.adiciona_reserva(n_quarto, data_entrada, data_saida);
                    break;
                case 'r':
                    std::cin >> n_quarto >> std::get_time(&data_entrada, FORMATO_DATA);
                    hotel.remove_reserva(n_quarto, data_entrada);
                    break;
                case 'p':
                    hotel.print_info();
                    break;
                default:
                    throw 
            }
        }
    } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}




