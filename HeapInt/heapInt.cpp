#include "HeapInt.hpp"


HeapInt::HeapInt() {
    data = new int(0);
}


HeapInt::HeapInt(int value) {
    data = new int(value);
}


HeapInt::HeapInt(const HeapInt &other) {
    data = new int(*other.data);
}


HeapInt::~HeapInt() {
    delete data;
}


HeapInt& HeapInt::operator=(int value) {
    *data = value;
    return *this;
}


HeapInt& HeapInt::operator=(const HeapInt &other) {
    if (this != &other) {
        *data = *other.data;
    }
    return *this;
}


HeapInt HeapInt::operator+(const HeapInt &other) const {
    return HeapInt(*data + *other.data);
}


HeapInt HeapInt::operator-(const HeapInt &other) const {
    return HeapInt(*data - *other.data);
}


bool HeapInt::operator==(const HeapInt &other) const {
    return *data == *other.data;
}


std::ostream& operator<<(std::ostream &out, const HeapInt &heapInt) {
    out << *heapInt.data;
    return out;
}


std::istream& operator>>(std::istream &in, HeapInt &heapInt) {
    int value;
    in >> value;
    *heapInt.data = value;
    return in;
}
