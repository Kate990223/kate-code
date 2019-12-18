#include<iostream>
#include "code1.h"
using std::cout;
using std::cin;
using std::endl;

//考察函数重载
//function definition

void repeat(int n, string str){
    for(int i=0; i < n; i++){
        cout<< "it is the " << i << " time" << endl;
        cout<< str << endl;
    }
}

void repeat(string str){
    for(int i=0; i < 5; i++){
        cout<< "it is the " << i << " time" << endl;
        cout<< str << endl;
    }
}

int main(){
    int a;
    cout << "input the num:" << endl;
    cin >> a;

    string temp1;
    cout << "input the first string" << endl;
    cin >> temp1;

    string temp2;
    cout << "input the second string" << endl;
    cin >> temp2;

    cout << "using the first function" << endl;
    repeat(a, temp1);

    cout << "using the second function" << endl;
    repeat(temp2);

    system("pause");

    return 0;
}
