#include <iostream>
#include "Hotel.hpp"


int main() {
    Hotel hotel;

    
        char command;
        int n_quarto;
        struct std::tm data_entrada, data_saida;

        while (std::cin >> command) {

            try{
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
                        
                }
            }
            catch (hotel_excp::quarto_nao_criado &ex) {
                std::cout << ex.what() <<": quarto "<< ex.get_n_quarto() << std::endl;
            }
            catch (hotel_excp::quarto_nao_existe &ex){
                std::cout << ex.what() <<": quarto "<< ex.get_n_quarto() << std::endl;
            }
            catch (quarto_excp::reserva_indisponivel &ex){
                std::cout << ex.what() <<" de"<< ex.get_data_entrada() << " a " << ex.get_data_saida() << std::endl;
            }
            catch (quarto_excp::reserva_nao_encontrada &ex){
                std::cout << ex.what() <<" no quarto "<< ex.get_n_quarto() << ": " << ex.get_data_entrada() << std::endl;
            }
            catch (reserva_excp::periodo_muito_curto &ex){
                std::cout << ex.what() <<": "<< ex.get_data_entrada() << ", " << ex.get_data_saida() << std::endl;
            }
            catch(reserva_excp::data_saida_antecede_entrada &ex){
                std::cout << ex.what() <<": "<< ex.get_data_entrada() << ", " << ex.get_data_saida() << std::endl;
            }
            catch(reserva_excp::data_entrada_no_passado &ex){
                std::cout << ex.what() <<": "<< ex.get_data_entrada() << std::endl;
            }


        }
     


    return 0; 
}




