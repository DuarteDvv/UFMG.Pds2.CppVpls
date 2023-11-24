// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_pokemon.hpp" 
#include "Campeonato.hpp"


int main() {
    char input;

    Campeonato Champions;
    string nome, tipoatq;
    int idt,idp, idt0, idp0;
    double forca, skill;
    


    while (cin >> input) {
        switch (input) {
        case 't': {  //cad treinador no camp
            cin >> nome;
            Champions.cadastrar_treinador(nome);

            break;
        }

        case 'i': {
            cin >> idt;
            Champions.imprimir_informacoes_treinador(idt);
            
            break;
        }

        case 'e': {
            cin >> idt >> nome >> tipoatq >> forca >> skill ;
            Champions.cadastrar_pokemon_eletrico(idt,nome,tipoatq,forca,skill);

            break;
        }

        case 'q': {
            cin >> idt >> nome >> tipoatq >> forca >> skill ;
            Champions.cadastrar_pokemon_aquatico(idt,nome,tipoatq,forca,skill);
            
            break;
        }

        case 'x': {
            cin >> idt >> nome >> tipoatq >> forca >> skill ;
            Champions.cadastrar_pokemon_explosivo(idt,nome,tipoatq,forca,skill);

            break;
        }

        case 'h': {
            cin >> idt >> idp >> idt0 >> idp0;
            Champions.executar_batalha(idt,idp,idt0,idp0);

            break;
        }

        case 'b': {
            avaliacao_basica();
            return 0;
        }

        default:
            cout << "ERRO: Comando inválido" << endl;
            break;
        }
    }

    return 0;
}