#include <iostream>
#include <cstring>
#include "Banco.hpp"
#include <iomanip>
#include "ContaBancaria.hpp"


using namespace std;

int main(){
    Banco Banco_do_Brasil;
    char option = ' ';

    int id, dest;
    string name;
    float value;

    Banco_do_Brasil.start();

    while(option != 'F'){
        cin >> option;

        switch (option)
        {
        case 'C':
            cin >> id >> name;
            if(Banco_do_Brasil.AccCrea(id, name)){
                cout << "conta criada" << endl;
            }
            else{
                cout << "ERRO: conta repetida" << endl;
            }
            break;

        case 'D':
            cin >> id >> value;
            if(Banco_do_Brasil.search(id) != nullptr){
                Banco_do_Brasil.search(id)->deposit(value);
                cout << "deposito efetuado" << endl;
            }
            else{
                cout << "ERRO: conta inexistente" << endl;
            }
            break;

        case 'S':
            cin >> id >> value;
            if(Banco_do_Brasil.search(id) != nullptr){
                Banco_do_Brasil.search(id)->draft(value);
                cout << "saque efetuado" << endl;
            }
            else{
                cout << "ERRO: conta inexistente" << endl;
            }
            break;

        case 'P':
            cin >> id >> dest >> value;
            if((Banco_do_Brasil.search(id) != nullptr) && (Banco_do_Brasil.search(dest) != nullptr)){
                Banco_do_Brasil.search(id)->pix(Banco_do_Brasil.search(dest), value);
                cout << "pix efetuado" << endl;
            }
            else{
                cout << "ERRO: conta inexistente" << endl;
            }
            break;
        
        case 'I':
            Banco_do_Brasil.data();
            break;
        

        default:
            break;
        }


    }
     for (int i = 0; i < Banco_do_Brasil.Ncontas; i++)
    {
        delete Banco_do_Brasil.contas[i];
    }
}