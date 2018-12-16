#ifndef MEMBER_TEMPLATE_HPP
#define MEMBER_TEMPLATE_HPP

#include <iostream>
using namespace std;
template<typename T>
class beta{
private:
    template<typename V>
    class hold{
    private:
        V val;
    public:
        hold(V v=0):val(v){}
        void show()const{cout<<val<<endl;}
        V value()const {return val;}
    };
    hold<T> q;
    hold<int> n;
public:
    beta(T t,int i):q(t),n(i){}
    template<typename U>
    U blab(U u,T t){return (n.value()+q.value()*u/t);}
    void show()const{q.show();n.show();}
};
void member_template_test()
{
    cout<<"*********member_template_test********"<<endl;
    beta<double> guy(3.5,3);

    guy.show();

    guy.blab(10,2.3);

    guy.blab(10.0,2.3);
}
#endif // MEMBER_TEMPLATE_HPP
