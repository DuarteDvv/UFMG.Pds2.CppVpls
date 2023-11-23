#include "Hotel.hpp"

namespace hotel_excp{

class quarto_nao_existe : std::exception {

};


class quarto_nao_criado : std::exception {

    public:
        quarto_nao_criado(int n){

        }


};


}