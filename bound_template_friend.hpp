#ifndef BOUND_TEMPLATE_FRIEND_HPP
#define BOUND_TEMPLATE_FRIEND_HPP
#include <iostream>
using namespace std;
//模板类的友元 函数 为函数模板
template <typename T> void counts();
template<typename T> void report(T&);

template <typename TT>
class HasFriendT{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT& i)
        :item(i){ct++;}
    ~HasFriendT(){ct--;}
    friend void counts<TT> ();
    //friend void report<>(HasFriendT<TT>&);
    friend void report<HasFriendT<TT> >(HasFriendT<TT>&);
};
template<typename T>
int HasFriendT<T>::ct=0;

template <typename T>
void counts(){
    cout<<"template size: "<<sizeof(HasFriendT<T>)<<" ; ";
    cout<<"template counts: "<<HasFriendT<T>::ct<<endl;
}
template <typename T>
void report(T& hf)
{
    cout<<typeid (hf).name();
    cout<<" hf.item: "<<"";
    cout<<hf.item<<endl;
}

void bound_template_friend_test()
{
    cout<<"***********bound_template_friend_test**************"<<endl;
    counts<int>();//
    HasFriendT<int> hfi1(19);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(1.2);

    report(hfi1);
    report(hfi2);
    report(hfdb);

    cout<<"counts<int>(): ";
    counts<int>();

    cout<<"counts<double>(): ";
    counts<double>();

}
#endif // BOUND_TEMPLATE_FRIEND_HPP
