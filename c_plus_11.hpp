#ifndef C_PLUS_11_HPP
#define C_PLUS_11_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <functional>
using namespace std;

bool f3(int x){return x%3==0;}
bool f13(int x){return x%13==0;}

template<typename T,typename F>
T use_f(T v,F f)
{
    static int count=0;
    count++;
    cout<<"use_f count= "<<count<<" &count= "<<&count<<" typeid(f)= "<<typeid (f).name()<<endl;
    return f(v);
}
class Fp{
private:
    double z;
public:
    Fp(double z_=1.0):z(z_){}
    double operator()(double p){return z*p;}
};
class Fq{
private:
    double z;
public:
    Fq(double z_=1.0):z(z_){}
    double operator()(double p){return z+p;}
};
double dub(double x){return x*2;}
double square(double x){return x*x;}

void show_list(){}
template <typename T>
void show_list(const T&value)
{
    cout<<value<<endl;
}
template <typename T,typename... Args>
void show_list(const T&value,const Args&... args)
{
    cout<<value<<" , ";
    show_list(args...);
}

void c_plus_11_test()
{
    cout<<endl<<string(8,'*')+"c_plus_11_test"+string(8,'*')<<endl;

    vector<int> numbers(10);
    vector<int> numbers2{10};
    generate(numbers.begin(),numbers.end(),rand);

    int count3=count_if(numbers.begin(),numbers.end(),f3);
    cout<<"count3=: "<<count3<<endl;
    int count13=count_if(numbers.begin(),numbers.end(),f13);
    cout<<"count13=: "<<count13<<endl;

    class f_mod{
    private:
        int dv;
    public:
        f_mod(int d=1):dv(d){}
        bool operator()(int x){return x%dv==0;}
    };
     count3=count_if(numbers.begin(),numbers.end(),f_mod(3));
    cout<<"f_mod(3) count3=: "<<count3<<endl;
     count13=count_if(numbers.begin(),numbers.end(),f_mod(13));
    cout<<"f_mod(13) count13=: "<<count13<<endl;

    count3=count_if(numbers.begin(),numbers.end(),[](int x){return x%3==0;});
   cout<<"lambda(3) count3=: "<<count3<<endl;
    count13=count_if(numbers.begin(),numbers.end(),[](int x){return x%13==0;});
   cout<<"lambda(13) count13=: "<<count13<<endl;
   count3=0;
   count13=0;
   for_each(numbers.begin(),numbers.end(),[&](int x){count3+= x%3==0; count13+= x%13==0;});
    cout<<"super lambda count3=: "<<count3<<endl;
    cout<<"super lambda count13=: "<<count13<<endl;

    double y=1.21;
    cout<<"use_f(y,dub): "<<use_f(y,dub)<<endl;
    cout<<"use_f(y,square): "<<use_f(y,square)<<endl;
    cout<<"use_f(y,Fp(5.0)): "<<use_f(y,Fp(5.0))<<endl;
    cout<<"use_f(y,Fq(5.0)): "<<use_f(y,Fq(5.0))<<endl;


    function<double(double)> ef1=dub;
    function<double(double)> ef2=square;
    function<double(double)> ef3=Fq(10.0);
    function<double (double)> ef4=Fp(10.0);
    function<double(double)> ef5=[](double x){return x*x;};
    function<double (double)> ef6=[](double x){return x+x/2.0;};

    cout<<"function<double(double)> "<<use_f(y,ef1)<<endl;
    cout<<"function<double(double)> "<<use_f(y,ef2)<<endl;
    cout<<"function<double(double)> "<<use_f(y,ef3)<<endl;
    cout<<"function<double(double)> "<<use_f(y,ef4)<<endl;
    cout<<"function<double(double)> "<<use_f(y,ef5)<<endl;
    cout<<"function<double(double)> "<<use_f(y,ef6)<<endl;

    using  fdd=function<double(double)>;
    typedef function<double(double)> fdd2;
    cout<<"fdd(dub)"<<use_f(y,fdd(dub))<<endl;

    show_list('v','a',"riadic","template",'t','e','s','t',"!!!");
}
#endif // C_PLUS_11_HPP
