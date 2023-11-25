#ifndef _HE
#define _HE

#include "Hotel.hpp"
#include <stdexcept>

namespace hotel_excp{

    class quarto_nao_existe : std::exception {
        private:
            int numero;

        public:
            quarto_nao_existe(int n){
                this->numero = n;

            }

            const char* what() const throw(){
                return "Numero do quarto informado nao pertence a colecao";
            } 

            int get_n_quarto(){
                return numero;
            }

    };


    class quarto_nao_criado : std::exception {
        private:
            int numero;

        public:
            quarto_nao_criado(int n){ 
                this->numero = n;
            }

            const char* what() const throw(){
                return "Quarto ainda nao foi adicionado a lista";
            }

            int get_n_quarto(){
                return numero;
            }


    };


}
#endif