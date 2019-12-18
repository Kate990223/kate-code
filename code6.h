#ifndef CODE6_H
#define CODE6_H

typedef struct{
    char fullname[35];
    double payment;
}customer;  //作为栈中节点中数据的数据结构

struct Node
{
    customer data;
    Node* next;
};//作为栈中的节点


class Stack{
    private:
        Node* head; 
        Node* q;     
        int length;
        static double sum; //count the sum of payment

    public:
    

    //default constructor
    Stack();
    bool IsEmpty() const;
    void push(char * input_name, double pay_count);
    void pop();
    void printer();
    static void count_sum(double money);
};

#endif