#include "aluno.hpp"
#include "algorithm"

float aluno::media(){
    float soma = 0;

    for(int n : this->notas){
        soma += n;
    }

    return soma/this->notas.size();

}

void aluno::addname(std::string nome){
    this->name = nome;
}

void aluno::addmatricula(int mat){
    this->matricula = mat;
}

void aluno::addnotas(std::vector<int> all){
    this->notas = all;
}

void aluno::impress(std::vector<aluno> alu){
    std::sort(alu.begin(), alu.end(), [](const aluno &a, const aluno &b) {
        return a.name < b.name;
    });

    for(aluno a : alu){
        std::cout << a.matricula << " " << a.name;
        int maior = 0;
        for(int n : a.notas){
            if(n > maior)
                maior = n;

            std::cout << " " << n;
        }
        std::cout << std::endl;

        std::cout << std::fixed << std::setprecision(2) << a.media() << ' ' << maior << std::endl;
    }
}
