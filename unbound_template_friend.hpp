#ifndef UNBOUND_TEMPLATE_FRIEND_HPP
#define UNBOUND_TEMPLATE_FRIEND_HPP

#include <iostream>
using namespace std;

template <typename T>
class ManyFriend{
private:
    T item;
public:
    ManyFriend(const T& i)
        :item(i){}
    template<typename C,typename D> friend void show2(C&,D&);
};
template<typename C,typename D> void show2(C& c,D& d)
{
    cout<<typeid (c).name()<<" "<<typeid (d).name();
    cout<<"c.item(): "<<c.item<<" , "<<"d.item(): "<<d.item<<endl;
}

void unbound_template_friend_test()
{
    cout<<"********unbound_template_friend_test********"<<endl;
    ManyFriend<int> hfi1(10);
    ManyFriend<int > hfi2(20);
    ManyFriend<double> hfdb(1.2);

    show2(hfi1,hfi2);

    show2(hfi2,hfdb);
}
#endif // UNBOUND_TEMPLATE_FRIEND_HPP
