#ifndef CODE7_H
#define CODE7_H

#include<iostream>

using std::ostream;

class Complex
{
private:
    int a;
    int b;

public:

    Complex(int x, int y);
    Complex();

    int show_a(int temp1);
    int show_b(int temp2);

    Complex operator+(const Complex& c1);
    Complex operator-(const Complex& c1);
    Complex operator*(const Complex& c1);
    Complex operator~();

    friend Complex operator*(int x, const Complex& c1);
    friend void operator<<(ostream& os, const Complex& c1);
    friend void operator>>(ostream& os, Complex& c1);

};

#endif

