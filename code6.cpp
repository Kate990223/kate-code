#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include "code6.h"

//使用链表来实现类,描述customer有关信息

using namespace std;

double Stack::sum = 0; //global variable

void Stack::count_sum(double money){
    sum += money;
    cout << "the sum of payment now is :" << sum << endl;
}

Stack::Stack(){
    head = new Node;
    head->next = nullptr;
    q = head;
    length = 0;
}

bool Stack::IsEmpty() const{
    if(length != 0){
        return false;
    }
    
    return true;
}

//头插法保证head->next就是top元素
void Stack::push(char* input_name, double pay_count){ //精度变低？
    Node* p = new Node;  //分配节点内存

    strcpy(p->data.fullname, input_name);
    p->data.payment = pay_count;

    if(head->next == nullptr){
        head->next = p;
        p->next = nullptr;
        q = p;
    }
    else
    {
        head->next = p;
        p->next = q;
        q = p;
    }

    length++;
    cout << "the length of stack is :" << length << endl;
}

void Stack::pop(){
    Node* p = head->next;

    //将payment加入总数
    double money = p->data.payment;
    //cout << "output the money successfully: " << money << endl;
    
    count_sum(money);

    head->next = p->next;

    delete p; //内存释放了吗
}

void Stack::printer(){
    cout << head->next->data.fullname << endl;
    cout << head->next->data.payment << endl;
}

int main(){

    Stack s; //调用默认构造函数

    //给链表中加入2个customer
    for(int i=0; i<2; i++){
        char *temp = new char [35];
        cout << "please input the " << (i+1) << "customer's fullname:" << endl;
        cin >> temp; 

        double money;
        cout << "please input the " << (i+1) << "customer's payment" << endl;
        cin >> money;

        s.push(temp, money);

       s.printer();
    }

    //弹出两个customer并计算sum_payment
    for(int i=0; i<2; i++){ //可用IsEmpty()
        s.pop();
    }


    system("pause");
    return 0;
}
