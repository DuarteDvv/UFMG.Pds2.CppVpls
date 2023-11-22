#ifndef _heapi
#define _heapi

#include <iostream>

class HeapInt {
private:
    int* inteiro;

public:
    HeapInt();
    HeapInt(int &);
    HeapInt(const HeapInt &);
    ~HeapInt();

    HeapInt& operator=(const HeapInt &a);
    HeapInt& operator=(const int &a);
    HeapInt& operator+(const HeapInt &a);
    HeapInt& operator-(const HeapInt &a);
    bool operator==(const HeapInt &a);

    int getInt() const;
    void setInt(int);
};

std::istream& operator>>(std::istream &is, HeapInt &a);
std::ostream& operator<<(std::ostream &os, const HeapInt &a);

#endif

