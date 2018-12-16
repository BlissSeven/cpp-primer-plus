#ifndef RTTI_TEST_HPP
#define RTTI_TEST_HPP

#include <iostream>
using namespace std;
class Grand{
private:
    int hold;
public:
    Grand(int h=0):hold(h){}
    virtual void speak () const {cout<<"grand class speak"<<endl;}
    virtual int value() const {return  hold;}
};
class Superb:public Grand
{
public:
    Superb(int h=0):Grand (h){}
    virtual void speak () const {cout<<"Superb class speak"<<endl;}
    virtual void say() const {cout<<"Superb class say "<<endl;}
};

class Magnificant:public Superb
{
public:
    Magnificant(int h=0):Superb (h){}
    virtual void speak () const {cout<<"Magnificant class speak"<<endl;}
    virtual void say() const {cout<<"Magnificant class say "<<endl;}
};
Grand* Getone()
{
    Grand* p;
    switch (rand()%3) {
        case 0: p=new Grand(rand()%100);  break;
        case 1: p=new Superb(rand()%100);  break;
        case 2: p=new Magnificant(rand()%100);  break;
    }
    return p;
}
void rtti_test()
{
    cout<<endl<<"********rtti_test********"<<endl;
    Grand* pg;
    Superb* ps;
    for(int i=0;i<5;i++)
    {
        pg=Getone();
        pg->speak();
        if(ps=dynamic_cast<Superb*>(pg))
            ps->say();
        if(typeid (Magnificant)==typeid (*pg))
            cout<<"real Magnificant object"<<endl;
    }
}
#endif // RTTI_TEST_HPP
