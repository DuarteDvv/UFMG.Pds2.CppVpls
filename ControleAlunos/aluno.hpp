#ifndef AL
#define AL

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class aluno
{
    private:
        std::string name;
        int matricula;
        std::vector<int> notas;

    public:
        float media();
        void addname(std::string);
        void addmatricula(int);
        void addnotas(std::vector<int>);
        void impress(std::vector<aluno>);

};

#endif
