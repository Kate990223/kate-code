#include<iostream>
using namespace std;

//考察函数模板

template<typename T>
 T average(T a, T b){
     T temp;
     temp = (a + b) / 2;
     return temp;
 }

int main(){
    int a, b;
    int temp1;

    cout << "enter two int:" << endl;
    cin >> a >> b;
    temp1 = average(a, b);
    cout << "the first answer is " << temp1 << endl;

    double c, d;
    double temp2;

    cout << "enter two double:" << endl;
    cin >> c >> d;
    temp2 = average(c, d);
    cout << "the second answer is " << temp2 << endl;

    system("pause");
    
}

