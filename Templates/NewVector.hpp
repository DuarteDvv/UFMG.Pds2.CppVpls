template <typename T>
class Vetor{
    private:
        T* Vet;

    public:

        Vetor(int a){
            T* A = new T[a];
        }

        Vetor(const Vetor& v){
            int size = sizeof(v.Vet) / sizeof(v.Vet[0]);
            Vet = new T[size];

            for (int i = 0; i < size; ++i) {
                Vet[i] = v.Vet[i];
            }
            
        }

        ~Vetor(){
            delete [] Vet;

        }

};
