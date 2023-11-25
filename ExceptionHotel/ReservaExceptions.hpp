#include "Reserva.hpp"
namespace reserva_excp{
    class data_entrada_no_passado : std::exception{
        private:
            struct std::tm entrada;


        public:
            data_entrada_no_passado(struct std::tm data_entrada) : entrada(data_entrada) {}
            const char* what() const throw(){
                return "Data de entrada esta no passado";
            }
            struct std::tm *get_data_entrada(){
                return &this->entrada;
            }

    };

    class data_saida_antecede_entrada : std::exception{
        private:
            struct std::tm entrada;
            struct std::tm saida;



        public:

            data_saida_antecede_entrada(struct std::tm data_entrada, struct std::tm data_saida) : entrada(data_entrada), saida(data_saida){}
            const char* what() const throw(){
                return "Data saida nao pode ser menor que a data entrada";
            }
            struct std::tm *get_data_entrada(){
                return &entrada;
            }
            struct std::tm *get_data_saida(){
                return &saida;
            }

    };


    class periodo_muito_curto : std::exception{
        private:
            struct std::tm entrada;
            struct std::tm saida;

        public:
            periodo_muito_curto(struct std::tm data_entrada, struct std::tm data_saida) : entrada(data_entrada), saida(data_saida){}
            const char* what() const throw(){
                return "Reserva deve ter duracao minima de 1 dia";
            }
            struct std::tm *get_data_entrada(){
                return &entrada;
            }
            struct std::tm *get_data_saida(){
                return &saida;
            }

    };





}
