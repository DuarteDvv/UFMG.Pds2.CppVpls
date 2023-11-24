#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class figura {
private:
    int x;
    int y;

public:
    figura(int x, int y) : x(x), y(y) {};

    virtual ~figura() {} 

    virtual void Desenha() {
        cout << this->x << " " << this->y;
    }

    virtual float Area() = 0;
};

class triangulo : public figura {
private:
    int base;
    int altura;

public:
    triangulo(int p1, int p2, int p3, int p4) : figura(p1, p2), base(p3), altura(p4) {};

    void Desenha() override {
        figura::Desenha();
        cout << " TRIANGULO" << endl;
    }

    float Area() override {
        return (base * altura) / 2.0;
    }
};

class retangulo : public figura {
private:
    int largura;
    int comprimento;

public:
    retangulo(int p1, int p2, int p3, int p4) : figura(p1, p2), largura(p3), comprimento(p4) {};

    void Desenha() override {
        figura::Desenha();
        cout << " RETANGULO" << endl;
    }

    float Area() override {
        return largura * comprimento;
    }
};

class circulo : public figura {
private:
    int raio;

public:
    circulo(int p1, int p2, int p3) : figura(p1, p2), raio(p3) {};

    void Desenha() override {
        figura::Desenha();
        cout << " CIRCULO" << endl;
    }

    float Area() override {
        return M_PI * raio * raio;
    }
};

int main() {
    char input;
    int p1, p2, p3, p4;
    vector<figura*> lista;

    while (cin >> input) {
        switch (input) {
        case 'R': {
            cin >> p1 >> p2 >> p3 >> p4;
            retangulo* ret = new retangulo(p1, p2, p3, p4);
            lista.push_back(ret);
            break;
        }

        case 'C': {
            cin >> p1 >> p2 >> p3;
            circulo* cir = new circulo(p1, p2, p3);
            lista.push_back(cir);
            break;
        }

        case 'T': {
            cin >> p1 >> p2 >> p3 >> p4;
            triangulo* tri = new triangulo(p1, p2, p3, p4);
            lista.push_back(tri);
            break;
        }

        case 'D': {
            for (figura* n : lista) {
                n->Desenha();
            }
            cout << endl;
            break;
        }

        case 'A': {
            float soma = 0;
            for (figura* n : lista) {
                soma += n->Area();
            }
            cout << fixed << setprecision(2) << soma << endl;
            break;
        }

        case 'E': {
            for (figura* n : lista) {
                delete n;
            }
            lista.clear();
            return 0;
        }

        default:
            cout << "ERRO" << endl;
            break;
        }
    }

    return 0;
}
