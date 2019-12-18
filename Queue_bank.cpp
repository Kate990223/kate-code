#include "Queue_bank.h"

using namespace std;



static int consist_time=3;//即队列要循环几小时
static int perhour_circle=4;//队列每小时循环几次
static int perhour_customer[3];//每小时队列中有几人

static int anhour_customer=0; //一小时内获得服务的客户数目
static int wait_time=0;//即顾客的处理时间

//int Queue::wait_time=0;//即每个顾客的processing time

static int flag=0; //0表示目前没有人在交易，1表示有人在交易，后面的人需要等待
Customer::Customer(double a){
    arrive = a;
}

Queue::Queue(){
    front = new Node;
    front->next = nullptr;
    rear = front;
    max_len = 3;
    cur_len = 0;
}


bool Queue::IsEmpty() const{
    if(cur_len > 0)
        return false;
    return true;
}

bool Queue::IsFull() const{
    if(cur_len == max_len)
        return true;
    return false;
}

Node* Queue::show_first(){
    return front->next;
}

int Queue::queuecount() const{
    return cur_len;
}

bool Queue::enQueue(const Item& c){
    if(!IsFull()){
        Node* p = new Node;
        if(front->next == nullptr){
            front->next = p;
            p->next = nullptr;
            p->data = c; //对象给对象赋值，调用复制构造函数，没用指针，不用考虑深浅复制
            rear = p;
        }
        else
        {//队列：尾插法
            rear->next = p;
            p->next = nullptr;
            p->data = c;
            rear = p;
        }
        
        cout << "enqueue successfully." << endl;
        return true; //返回什么东西？
    }

    return false;
}

bool Queue::deQueue(){
    if(!IsEmpty()){
        //头出
        Node* temp = front->next;
        front->next = temp->next;
        delete temp;
        
        return true;
    }

    return false;
}

Queue::~Queue(){
    Node* temp;
    
    while(front->next != nullptr){
        temp = front;
        front = front->next;
        
        delete temp;    
    }

    // delete front;
    // delete rear; 此时front,rear指向的内存已被释放，所以不需要加这两句，但是front，rear变为nullptr
}
