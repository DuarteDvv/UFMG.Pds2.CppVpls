#include <string>
#include <vector>
#include <iostream>
#include "aluno.hpp"

int main(){
    std::string input;
    std::vector<aluno> allunos = {};
    int nota, matricula;
    std::vector<int> cjn;
    aluno x;

    while (input != "END"){
        
        std::getline(std::cin,input);
        if (input == "END")
            break;
        x.addname(input);
        std::cin >> matricula;
        x.addmatricula(matricula);
        while (std::cin >> nota && nota != -1)
        {
            cjn.push_back(nota);
        }

        x.addnotas(cjn);
        cjn.clear();
        input.clear();
        std::cin.ignore();
        allunos.push_back(x);
    }

    x.impress(allunos);
    
}

