#include <iostream>
#include "Hotel.hpp"
#include <iomanip>
#include <sstream>

int main() {
    Hotel hotel;

    char command;
    int n_quarto;
    struct std::tm data_entrada = {}, data_saida = {};

    while (std::cin >> command) {
        try {
            switch (command) {
            case 'a':
                {
                    std::string entrada_str, saida_str;
                    std::cin >> n_quarto >> entrada_str >> saida_str;

                    std::istringstream entrada_stream(entrada_str);
                    entrada_stream >> std::get_time(&data_entrada, FORMATO_DATA);

                    std::istringstream saida_stream(saida_str);
                    saida_stream >> std::get_time(&data_saida, FORMATO_DATA);

                    if (entrada_stream.fail() || saida_stream.fail()) {
                        throw std::runtime_error("Erro ao ler data.");
                    }

                    hotel.adiciona_reserva(n_quarto, data_entrada, data_saida);
                }
                break;
            case 'r':
                {
                    std::string entrada_str;
                    std::cin >> n_quarto >> entrada_str;

                    std::istringstream entrada_stream(entrada_str);
                    entrada_stream >> std::get_time(&data_entrada, FORMATO_DATA);

                    if (entrada_stream.fail()) {
                        throw std::runtime_error("Erro ao ler data.");
                    }

                    hotel.remove_reserva(n_quarto, data_entrada);
                }
                break;
            case 'p':
                hotel.print_info();
                break;
            }
        } catch (hotel_excp::quarto_nao_criado &ex) {
            std::cout << ex.what() << ": quarto " << ex.get_n_quarto() << std::endl;
        } catch (hotel_excp::quarto_nao_existe &ex) {
            std::cout << ex.what() << ": quarto " << ex.get_n_quarto() << std::endl;
        } catch (quarto_excp::reserva_indisponivel &ex) {
            std::cout << ex.what() << " de " << std::put_time(ex.get_data_entrada(), FORMATO_DATA) << " a " << std::put_time(ex.get_data_saida(), FORMATO_DATA) << std::endl;
        } catch (quarto_excp::reserva_nao_encontrada &ex) {
            std::cout << ex.what() << " no quarto " << ex.get_n_quarto() << ": " << std::put_time(ex.get_data_entrada(), FORMATO_DATA) << std::endl;
        } catch (reserva_excp::periodo_muito_curto &ex) {
            std::cout << ex.what() << ": " << std::put_time(ex.get_data_entrada(), FORMATO_DATA) << ", " << std::put_time(ex.get_data_saida(), FORMATO_DATA) << std::endl;
        } catch (reserva_excp::data_saida_antecede_entrada &ex) {
            std::cout << ex.what() << ": " << std::put_time(ex.get_data_entrada(), FORMATO_DATA) << ", " << std::put_time(ex.get_data_saida(), FORMATO_DATA) << std::endl;
        } catch (reserva_excp::data_entrada_no_passado &ex) {
            std::cout << ex.what() << ": " << std::put_time(ex.get_data_entrada(), FORMATO_DATA) << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Erro: " << ex.what() << std::endl;
        }
    }

    return 0;
}
