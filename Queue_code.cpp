#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include "Queue_bank.h"

using namespace std;
//用队列实现银行排队，交易功能
//设置两层循环，外层表示循环几个小时，内层表示每小时循环几次
//着重队列，static，节点的运用
//long为long int型，在debug时一开始以为是小数型，输入1.2导致部分不能循环
//记得为新节点分配空间！


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

int main(){
    Queue q;
    int i;

    for(i=0; i<consist_time; i++){ //竟然忘了加{}，我fo了，肯定是不小心删了。。。
        cout << endl;
        cout << " it is the " << i+1 << "hour now." << endl;

        
        for(int j=0; j<perhour_circle; j++){ //每次循环中都要做以下工作
            cout << endl;
            cout << "it the " << j+1 << "circle in an hour. " << endl;
            
            //1.判断有没有新客户，有则在队列未满时入队
            char ch;
            cout << "Is there a new guy who want to come in?(y or n):" << endl;
            cin >> ch; 
            //Sleep(2000);//毫秒  谁能告诉我为啥要停2秒，然后停两秒的时候还得觉得是卡了多按几个回车
            //是啥吧 一开始这有问题 我以为是我输入有问题 然后我设置sleep让他停两秒我看看情况，微笑，那我再试一下

            if(ch == 'y'){
                if(!q.IsFull()){
                    //给新到用户初始化
                    double a;

                    cout << "please tell me when the customer arrive:" << endl;
                    cin >> a;

                    Customer customer = Customer(a);
                    //新用户初始化完成，开始入队

                    q.enQueue(customer);

                    perhour_customer[i]++; //每小时入队多少人
                }
            }
            else{
                cout << "ch:" << ch << endl;
            }
                
        
           
            //2.没有客户在进行交易时，选择队列第一个用户进行服务,将wait_time计数器设置为用户proccesing time
            if(flag == 0){
                cout << "now nothing is processed, so choose the first customer in the queue." << endl;
                Node* temp = q.show_first(); //得到队列的一个节点
                wait_time = temp->data.set_pt();

                cout << "the proccessing time is :" << wait_time << endl;

                anhour_customer += 1;
                flag = 1; //设置锁，此时有客户在交易
            }
            else{   
                wait_time -= 1;
                cout << "now wait time is :" << wait_time << endl;

                if(wait_time == 0){//此时当前用户完成交易
                    q.deQueue();//删除此节点
                    flag = 0;
                }
            }
        }

        cout << "in the " << i+1 << "hour, the sum of customer who come in is :" << perhour_customer[i] << endl; 
        cout << "in the " << i+1 << "hour, the sum of customer serviced is :" << anhour_customer << endl; 

        anhour_customer = 0;

        
    }

    system("pause");
    return 0;
}
