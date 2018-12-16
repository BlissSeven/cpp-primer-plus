#ifndef NO_TEMPLATE_FRIEND_FUNCTION_HPP
#define NO_TEMPLATE_FRIEND_FUNCTION_HPP
//模板类的非模板友元函数
#include <iostream>
using namespace std;
template <typename T>
class HasFriend{
private:
    T item;
    static int ct;
public:
    HasFriend(const T& i)
        :item(i){ct++;}
    ~HasFriend(){ct--;}
    friend void counts();//友元函数没有参数
    friend void reports(HasFriend<T>&);//为友元函数提供模板类参数
};
template <typename T >
  int HasFriend<T>::ct=0;
void counts()
{
    cout<<"int: "<<HasFriend<int>::ct<<endl;
    cout<<"double: "<<HasFriend<double>::ct<<endl;
}
void reports(HasFriend<int>& hf)
{
    cout<<"HasFriend<int>& "<<hf.item<<endl;
}
void reports(HasFriend<double>& hf)
{
    cout<<"HasFriend<double>& "<<hf.item<<endl;
}
void no_template_friend_function_test()
{
    cout<<"**********no_template_friend_function_test******** "<<endl;
        counts();
        HasFriend<int> hfil(10);
        counts();
        HasFriend<int> hfil2(20);
        counts();
        HasFriend<double> hfdb(1.2);
        counts();

        reports(hfil);
        reports(hfil2);
        reports(hfdb);
}
#endif // NO_TEMPLATE_FRIEND_FUNCTION_HPP
