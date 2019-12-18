#ifndef PORT_H
#define PORT_H

#include<iostream>
#include<cstring>
using namespace std;

class Port
{
private:
    char* brand;
    char styles[20];//tawny, ruby, vintage
    int bottles;//有几瓶酒

public:
    Port(const char* br="none", const char* st="none", int b=0);
    Port(const Port& p);
    virtual ~Port(){delete [] brand;};

    Port& operator=(const Port& p);
    Port& operator+=(int b);//增加酒的数目
    
    int bottlecount() const{return bottles;};
    virtual void show() const;//显示对象数据成员信息

    friend ostream& operator<<(ostream& os, const Port& b);

};


Port::Port(const Port& p){
    int len = strlen(p.brand);
    brand = new char [len+1];
    strcpy(brand, p.brand);
    strcpy(styles, p.styles);
    bottles = p.bottles;
}

class VintagePort:public Port
{
private:
    char* nickname;
    int year;

public:
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort(){delete [] nickname;};

    VintagePort& operator=(const VintagePort& vp);
    void show() const;

};



#endif
