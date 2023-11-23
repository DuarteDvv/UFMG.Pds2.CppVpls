#ifndef _VET 
#define _VET

#include <iostream>

using namespace std;

template <typename T>
class Vetor{
    private:
        T* Vet;

    public:

        Vetor(int a){
            T* A = new T[a]{};
        }

        Vetor(const Vetor& v){
            int size = sizeof(v.Vet) / sizeof(v.Vet[0]);
            Vet = new T[size]{};

            for (int i = 0; i < size; ++i) {
                Vet[i] = v.Vet[i];
            }
            
        }

        ~Vetor(){
            delete [] Vet;

        }


        void SetElemento(int n, T dado){
            Vetor[n+1] = dado;
        }
        T GetElemento(int n){
            return Vetor[n+1];
        }

        void AdicionaElemento(T elemento){
            int size = sizeof(v.Vet) / sizeof(v.Vet[0]);
            for(int i = 0; i < size ; i++){
                if(Vet[i] == nullptr){
                    Vet[i] = elemento;
                    break;
                }

            }
            
        }

        void Imprime(){
            int size = sizeof(v.Vet) / sizeof(v.Vet[0]);
            for(int i = 0; i < size ; i++){
                cout << Vet[i] << " ";

            }

        }

};

#endif