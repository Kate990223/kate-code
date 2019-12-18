#include<iostream>
#include<cstdio>
#include<string>
#include<ctype.h>

using namespace std;

void ToUp(string & a);

int main(){
    string flag;
    
    while(true){
        string str;
        cout << "enter a string(q to quit) :" << endl;
        cin >> str;
        
        ToUp(str);
        cout << "the new string is :" << str << endl;

        cout << "would you want to continue?" << endl;
        flag = cin.get();
        switch (flag == "yes")
        {
        case 1:
            // system("pause");
            continue;
            break;
        
        default:
            return 0;
        }
    }
}

void ToUp(string & a){
    string p = a;
    int i = 0;

    while(p[i] != '\0'){
        a[i] = toupper(p[i]);
        i++;
    }
}