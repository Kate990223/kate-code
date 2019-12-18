#include "code7.h"
#include<iostream>
#include<cstring>

//对复数进行操作
//考察运算符重载

using namespace std;

Complex::Complex(int x, int y): a(x), b(y){} //成员初始化列表
Complex::Complex(){}

int Complex::show_a(int temp1){
    a = temp1;
    return a;
}

int Complex::show_b(int temp2){
    b = temp2;
    return b;
}

Complex Complex::operator+(const Complex& c1){
    Complex temp;
    temp.a = this->a + c1.a;
    temp.b = this->b + c1.b;

    return temp;
} 

Complex Complex::operator-(const Complex& c1){
    Complex temp;
    temp.a = this->a - c1.a;
    temp.b = this->b - c1.b;

    return temp;
}

Complex Complex::operator*(const Complex& c1){
    Complex temp;
    temp.a = (this->a * c1.a) - (this->b * c1.b);
    temp.b = (this->a * c1.b) + (this->b * c1.a);

    return temp;
}

Complex Complex::operator~(){
    Complex temp;
    temp.a = this->a;
    temp.b = -this->b;

    return temp;
}

Complex operator*(int x, const Complex& c1){ //friend不属于类，不要在函数名加限定，否则错误
    Complex temp;
    temp.a = c1.a * x;  //访问了私有数据，应调用函数return该数据的值
    temp.b = c1.b * x;

    return temp;
}

void operator<<(ostream& os, const Complex& c1){
    os << "(" << c1.a << "," << c1.b << "i)" << endl;
}

void operator>>(istream& is, Complex& c1){
    int temp1, temp2;
    is >> temp1;
    is >> temp2;

    c1.show_a(temp1);
    c1.show_b(temp2);
}

int main(){
    Complex a(3, 4);
    Complex c;

    cout << "enter a complex number: " << endl;
    cin >> c;
    
    cout << "c is " << c;
    cout << endl;

    cout << "complex conjuate is " << ~c;
    cout << endl;

    cout << "a is " << a;
    cout << endl;

    cout << "a + c is " << a+c;
    cout << endl;

    cout << "a - c is " << a-c;
    cout << endl;

    cout << "a * c is " << a*c;
    cout << endl;

    cout << "2 * c is " << 2*c;
    cout << endl;

    cout << "Done!" << '\n';

    system("pause");
    return 0;

}
