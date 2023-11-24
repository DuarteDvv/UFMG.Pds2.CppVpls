#include <iostream>
#include <vector>

using namespace std;

class Teste123 {
private:
    int cod;
    static int Nobj;

public:
    Teste123(int id) : cod(id) {
        Teste123::Nobj++;
    }

    ~Teste123() {
        Teste123::Nobj--;
    }

    int getId() {
        return this->cod;
    }

    static int getN() {
        return Nobj;
    }
};

int Teste123::Nobj = 0;

int main() {
    char input;
    int id = 0;
    int iaux;
    vector<Teste123*> lista;

    while (cin >> input) {
        switch (input) {
        case 'A': {
            Teste123* objeto = new Teste123(++id);
            lista.push_back(objeto);
            cout << objeto->getId() << " " << objeto << endl;
            break;
        }

        case 'R': {
            if (lista.empty()) {
                cout << "ERRO" << endl;
            } else {
                Teste123* aux = lista.front();
                cout << aux->getId() << " " << aux << endl;
                lista.erase(lista.begin());
                delete aux;
            }
            break;
        }

        case 'C': {
            cout << Teste123::getN() << endl;
            break;
        }

        case 'P': {
            cin >> iaux;
            if (iaux < 1 || iaux > static_cast<int>(lista.size())) {
                cout << "ERRO" << endl;
            } else {
                cout << lista[iaux - 1]->getId() << " " << lista[iaux - 1] << endl;
            }
            break;
        }

        case 'L': {
            for (Teste123* n : lista) {
                cout << n->getId() << " " << n << endl;
            }
            break;
        }

        case 'E': {
            for (Teste123* n : lista) {
                delete n;
            }
            lista.clear(); // Limpar a lista após deletar os objetos
            return 0;
        }
        
        default:
            cout << "ERRO" << endl;
            break;
        }
    }

    return 0;
}
