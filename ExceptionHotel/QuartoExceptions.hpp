#include "Quarto.hpp"

namespace quarto_excp{
    class reserva_nao_encontrada : std::exception{
        private:

        int numero;
        struct std::tm entrada;


        public:
            reserva_nao_encontrada(int n_quarto, struct std::tm data_inicio) : numero(n_quarto), entrada(data_inicio){}
            const char* what() const throw(){
                return "Reserva nao encontrada";
            }
            int get_n_quarto(){
                return this->numero;
            }
            struct std::tm *get_data_entrada(){
                return &entrada;
            }
    };

    class reserva_indisponivel : std::exception{
        private:
            int numero;
            struct std::tm entrada;
            struct std::tm saida;

        public:

            reserva_indisponivel(struct std::tm data_inicio, struct std::tm data_saida) : entrada(data_inicio), saida(data_saida){}
            const char* what() const throw(){ 
                return "Existe uma reserva em alguns dos dias do periodo";
            }
            struct std::tm *get_data_entrada(){
                return &entrada;
            }
            struct std::tm *get_data_saida(){
                return &saida;
            }

    };






}
