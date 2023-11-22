#include "heapi.hpp"
#include <iostream>

HeapInt::HeapInt() {
    this->inteiro = new int(0);
}

HeapInt::HeapInt(int &a) {
    this->inteiro = new int(a);
}

HeapInt::HeapInt(const HeapInt &a) {
    this->inteiro = new int(a.getInt());
}

HeapInt::~HeapInt() {
    delete this->inteiro;
}

int HeapInt::getInt() const {
    return *(this->inteiro);
}

void HeapInt::setInt(int a) {
    *(this->inteiro) = a;
}

HeapInt& HeapInt::operator=(const HeapInt &a) {
    this->setInt(a.getInt());
    return *this;
}

HeapInt& HeapInt::operator=(const int &a) {
    this->setInt(a);
    return *this;
}

HeapInt& HeapInt::operator+(const HeapInt &a) {
    this->setInt(this->getInt() + a.getInt());
    return *this;
}

HeapInt& HeapInt::operator-(const HeapInt &a) {
    this->setInt(this->getInt() - a.getInt());
    return *this;
}

bool HeapInt::operator==(const HeapInt &a) {
    return this->getInt() == a.getInt();
}

std::istream& operator>>(std::istream &is, HeapInt &a) {
    int value;
    is >> value;
    a.setInt(value);
    return is;
}

std::ostream& operator<<(std::ostream &os, const HeapInt &a) {
    os << a.getInt();
    return os;
}
