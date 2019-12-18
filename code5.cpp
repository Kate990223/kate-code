#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

typedef struct 
{
    char dross[20];
    int slag;
}T;

int main(){
    T* p = new T [2]; //remember to delete
    

    T* buffer = new T [2];
    T* pTemp =  buffer;

    for(int i=0; i<2; i++){
        char* temp = new char [20];
        
        cout << "input the " << (i+1) << "string" << endl;
        cin >> temp;

        //sstr = temp;
        strcpy(pTemp->dross, temp);
        pTemp->slag = 0;

        pTemp++;
    }

    cout << "initialized successfully." << endl;

    cout << p->dross << endl;

    p++;

    cout << "the second " << endl;

    cout << p->dross << endl;

    //delete memery
    delete [] p;
    p = nullptr;

    system("pause");
    return 0;
}

