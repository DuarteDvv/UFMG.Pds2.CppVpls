O objetivo deste VPL é praticar a definição, lançamento e captura de exceções.

Você deve implementar o sistema de reservas de quartos de um hotel, que utilizará captura e lançamento de exceções.

Nesse VPL é feita a manipulação de datas utilizando a biblioteca iomanip. Com ela será possível manipular a entrada e saída de datas em um formato definido por nós. Também será utilizado alguns recursos da biblioteca ctime, para poder calcular valores a partir das datas. Não deixe de consultar as referências no final da descrição.

Código de exemplo:

#include <iostream>
#include <iomanip> //std::get_time, std::put_time
#include <ctime> //struct std::tm, std::time, time_t

#define DATE_FORMAT "%d/%m/%Y" //DD/MM/YYYY

int main() {
    struct std::tm input_date = {};

    std::cin >> std::get_time(&input_date, DATE_FORMAT); //entrada
    std::cout << "date: " << std::put_time(&input_date, DATE_FORMAT) << std::endl; //saída

    time_t time = mktime(&input_date); //converte struct std::tm para time_t
    time_t now = std::time(0); //gera um time_t com a data atual da máquina
    time_t diff = time - now; //diferença entre time_t

    std::cout << diff << " seconds" << std::endl;
    return 0;
}

Dica: você precisar conhecer bem essa função para poder implementar o código, sugiro antes de começar o vpl criar um arquivo feito por você que faça essa manipulação.

Arquivos já disponíveis que NÃO DEVEM SER ALTERADOS: 
Hotel.hpp 
Quarto.hpp 
Reserva.hpp
Reserva
Métodos:
Reserva(struct std::tm data_entrada, struct std::tm data_saida)
caso a data_entrada seja um data menor que a data da máquina, deve lançar a exceção reserva_excp::data_entrada_no_passado
caso a data_entrada seja maior que a data_saida, deve lançar a exceção reserva_excp::data_saida_antecede_entrada
caso a diferença entra a data_saida e data_entrada seja menor que um dia, deve lançar a exceção reserva_excp::periodo_muito_curto
A implementação deve respeitar essa ordem.
struct std::tm *get_data_entrada() e struct std::tm *get_data_saida()
ambas devem retornar o endereço de data
int comparar(Reserva& other): compara um Reserva com outra Reserva
se a data_saida de this for menor que a data_entrada de other, retorne -1. Ou seja, this < other
se a data_saida de other for menor que a data_entrad de this, retorne 1. Ou seja, other < this
por padrão retorna 0. Ou seja, há uma sobreposição nas datas de reservas.
void print_info(): deve imprimir:
       Entrada: <_data_entrada>, Saida: <_data_saida>
Atenção: Utilize '\t' no início da linha.

Quarto
Métodos:
void Quarto::adiciona_reserva(struct std::tm data_entrada, struct std::tm data_saida)
adiciona um reserva na lista de reservas.
as reservas devem ser inseridas pela ordem das suas reservas. As reservas que começam primeiro estão no começo da lista.
ao tentar inserir um reserva, encontra uma sobreposição de reservas, deva lançar a exceção quarto_excp::reserva_indisponivel
void Quarto::remove_reserva(struct std::tm data_entrada)
remove a reserva que contém a data_entrada
caso não ache a reserva, lança a exceção quarto_excp::reserva_nao_encontrada
void print_info(): deve imprimir:
Quarto  <_n_quarto>  ---------
<todas as reservas desse quarto>
------------------

Hotel
Métodos:
Quarto *get_quarto_pelo_n(int n_quarto)
Retorna o quarto com número correspondente, caso não encontre deve lançar a exceção hotel_excp::quarto_nao_criado 
void adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida)
adiciona uma reserva a quarto correspondente
caso o quarto não exista, deve ser criado e adicionar a reserva. Os números dos quartos vão de 0 a 5.
caso o número do quarto não pertença ao domínio de números de quarto, deve lançar a exceção hotel_excp::quarto_nao_existe
Dica: use try catch para controlar o fluxo de execução
void remove_reserva(int n_quarto, struct std::tm data_entrada)
remove a reserva do quarto correspondente
caso o número do quarto não pertença ao domínio de números de quarto, deve lançar a exceção hotel_excp::quarto_nao_existe
void print_info()
deve imprimir as informações de todos os quartos que tem reservas
ReservaExceptions
deve herdar de std::exception
declare e implemente todas as exceções dentro do namespace reserva_excp
data_entrada_no_passado
Métodos públicos
data_entrada_no_passado(struct std::tm data_entrada): construtor 
const char* what() const throw(): retorna "Data de entrada esta no passado"
struct std::tm *get_data_entrada()
data_saida_antecede_entrada
Métodos públicos
data_saida_antecede_entrada(struct std::tm data_entrada, struct std::tm data_saida): construtor
const char* what() const throw(): retorna "Data saida nao pode ser menor que a data entrada"
struct std::tm *get_data_entrada()
struct std::tm *get_data_saida()
periodo_muito_curto
Métodos públicos
periodo_muito_curto(struct std::tm data_entrada, struct std::tm data_saida): construtor
const char* what() const throw(): retorna "Reserva deve ter duracao minima de 1 dia"
struct std::tm *get_data_entrada()
struct std::tm *get_data_saida()

QuartoExceptions
deve herdar de std::exception
declare e implemente todas as exceções dentro do namespace quarto_excp
reserva_nao_encontrada
Métodos públicos
reserva_nao_encontrada(int n_quarto, struct std::tm data_inicio): construtor
const char* what() const throw(): retorna "Reserva nao encontrada"
int get_n_quarto()
struct std::tm *get_data_entrada()
reserva_indisponivel
Métodos públicos
reserva_indisponivel(struct std::tm data_inicio, struct std::tm data_saida): construtor
const char* what() const throw(): retorna "Existe uma reserva em alguns dos dias do periodo"
struct std::tm *get_data_entrada()
struct std::tm *get_data_saida()
HotelExceptions
deve herdar de std::exception
declare e implemente todas as exceções dentro do namespace hotel_excp
quarto_nao_existe
Métodos públicos
quarto_nao_existe(int n_quarto): construtor
const char* what() const throw(): retorna "Numero do quarto informado nao pertence a colecao"
int get_n_quarto()
quarto_nao_criado
Métodos públicos
quarto_nao_criado(int n_quarto): construtor
const char* what() const throw(): retorna "Quarto ainda nao foi adicionado a lista"
int get_n_quarto()

main.cpp
 deve receber comandos pela entrada padrão. Comandos:
'a quarto data_entrada data_saida':adiciona uma reserva no para o quarto informado
'r quarto data_entrada': remove uma reserva para o quarto informado
'p': imprimir informações do hotel
Captura de exceções
caso reserva_excp::data_entrada_no_passado: imprime "<what>:  <data_entrada>"
caso reserva_excp::data_saida_antecede_entrada: imprime "<what>:  <data_entrada>,  <data_saida>"
caso reserva_excp::periodo_muito_curto: imprime "<what>:  <data_entrada>,  <data_saida>"
caso quarto_excp::reserva_nao_encontrada: imprime "<what>  no quarto  <n_quarto>:  <data_entrada>"
caso quarto_excp::reserva_indisponivel: imprime "<what>  de  <data_entrada>  a  <data_sainda>"
caso hotel_excp::quarto_nao_existe: imprime "<what>:  quarto <n_quarto>"
caso hotel_excp::quarto_nao_criado: imprime "<what>:  quarto <n_quarto>"
Exemplo de entrada/saída:
input =
a 0 08/06/2024 11/06/2024
a 2 22/06/2024 26/06/2024
a 2 27/06/2024 30/06/2024
a 4 27/06/2024 04/07/2024
p
output =
Quarto 0 ---------
        Entrada: 08/06/2024, Saida: 11/06/2024
------------------
Quarto 2 ---------
        Entrada: 22/06/2024, Saida: 26/06/2024
        Entrada: 27/06/2024, Saida: 30/06/2024
------------------
Quarto 4 ---------
        Entrada: 27/06/2024, Saida: 04/07/2024
------------------

Referências:
https://cplusplus.com/reference/iomanip/
https://cplusplus.com/reference/ctime/tm/
https://cplusplus.com/reference/ctime/time_t/
https://cplusplus.com/reference/iomanip/get_time/
https://cplusplus.com/reference/iomanip/put_time/