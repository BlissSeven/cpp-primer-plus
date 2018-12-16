#ifndef TEMPLATE_PARAMETER_HPP
#define TEMPLATE_PARAMETER_HPP
#include <iostream>
#include<mystack.hpp>
using namespace std;
//将模板用作参数
//template <typename T> class 为类型 Thing 为参数
template <template <typename T> class Thing>
class Crab{
private:
    Thing <int> s1;
    Thing<double> s2;
public:
    Crab(){}
    bool push(int a,double x){return s1.push(a)&& s2.push(x);}
    bool pop(int &a,double &x){return s1.pop(a)&&s2.pop(x);}
};

void template_parameter_test()
{
    Crab<Stack> nebula;
    int ni;
    double nb;
    cout<<"enter int && double pairs"<<endl;
    while(cin>>ni>>nb&& ni>0 && nb>0)
    {
        if(!nebula.push(ni,nb))
            break;
    }
    while(nebula.pop(ni,nb))
        cout<<ni<<" "<<nb<<endl;
}
#endif // TEMPLATE_PARAMETER_HPP
