#include "heapi.hpp"


int HeapInt::getInt() const {
    return *(this->inteiro);
}

void HeapInt::setInt(int a){
    *(this->inteiro) = a;
}

HeapInt& HeapInt::operator = (const HeapInt &a){
    this->setInt(a.getInt());
    return *this;
}

HeapInt& HeapInt::operator = (const int &a){
    return this->getInt() + a;
}

HeapInt& HeapInt::operator + (const HeapInt &a){
    return this->getInt() + a.getInt();

}

HeapInt& HeapInt::operator - (const HeapInt &a){
    return this->getInt() - a.getInt();
}

HeapInt& HeapInt::operator == (const HeapInt &a){
    return this->getInt() == a.getInt();
}

HeapInt& HeapInt::operator >> (const HeapInt &a){
                    >> a.getInt();
}

HeapInt& HeapInt::operator << (const HeapInt &a){
                    << a.getInt();
}





HeapInt::HeapInt(){
    this->inteiro = new int(0);

}

HeapInt::HeapInt(int &a){
    this->inteiro = new int(a);

}

HeapInt::HeapInt(const HeapInt &a){
    this& = a ;

}

HeapInt::~HeapInt(){
    delete this->inteiro;

}


