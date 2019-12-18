#ifndef QUEUE_BANK_H
#define QUEUE_BANK_H
#include<stdlib.h>

#define Q_size 5 //限定队列人数
#define circle 10 //每小时循环几次

class Customer
{
private:
    double arrive;
    int processtime;
    
public:
    Customer(){arrive = processtime = 0;}
    Customer(double a);
    int set_pt(){return processtime = rand()%3 + 1;} //将到达时间设置为参数,inline
    long when() const{return arrive;} //inline function
    int ptime() const{return processtime;}
};


typedef Customer Item;

struct Node
{
    Item data; //数据类型为类
    Node* next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;
        int cur_len;
        int max_len; //应该设置为const
        //static int wait_time;

    public:
        Queue();

        bool IsEmpty() const;
        bool IsFull() const;
        Node* show_first();
        int queuecount() const;//访问当前队列中有几个人
        bool enQueue(const Item& c);
        bool deQueue();
        ~Queue();
};



#endif