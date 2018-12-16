#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#include <tuple>
using namespace std;

#include <ctime>

#include "mystack.hpp"
#include "no_template_friend_function.hpp"
#include "bound_template_friend.hpp"
#include "unbound_template_friend.hpp"
#include "exception_class_throw.hpp"
#include "rtti_test.hpp"
#include "smart_ptr.hpp"
#include "stl_test.hpp"
#include "c_plus_11.hpp"
int main()
{
    string str(10,'*');
    string::iterator its=str.begin();

 cout<<string(its,str.end())<<endl;
 cout<<string::npos<<endl;
 cout<<"str.capacity(): "<<str.capacity()<<endl;


    no_template_friend_function_test();
    bound_template_friend_test();

    unbound_template_friend_test();
    exception_class_throw_test();
    rtti_test();
    smart_ptr_test();
    stl_test();
    c_plus_11_test();

    const char *ch{"123"};
    string str2(ch,ch+3);
    cout<<(void*)ch<<"  "<<&str<<endl;

    tuple <string,int ,int> t1{"1",2,3};


    cout<<get<0>(t1);
    map<string,tuple<int,int> > m1;
    m1["1"]=make_tuple(1,2);

    cout<<get<0>(m1["1"])<<endl;

      long accesslevel=3;
      const long long OPC_READABLE	=	0x1;
     cout<< "access level "<<bool(accesslevel & OPC_READABLE)<<endl ;


    cout<<"sizeof test "<<endl;
    cout<<"atan2: "<<atan2(3,4)<<endl;
    cout<<"atan2: "<<atan2(0,4)<<endl;
    cout<<"atan2: "<<atan2(0,0)<<endl;


    /*
    cout << "Hello World!" << endl;

    int tell[10]={1,2,3,4,5,6,7,8,9,0};
    cout<<"tell: "<<tell<<endl;
    int (*pas)[10]=&tell;
    printf("sizeof(int): %d",sizeof(tell[0]));

    printf("tell: %p &tell: %p\n",tell,&tell);
    printf("tell+1: %p &tell+1: %p diff:%d\n",tell+1,&tell+1,int(&tell+1)-int(tell+1));
    //cout<<<"&tell: "<< &tell <endl;
     cout<<0xd0-0xac<<endl;
     int* p=new int[4];
     cout<<p<<endl;
     cout<<p+1<<endl;
    return 0;*/

    int a=4;
    decltype (a) b;

    cout<<typeid (b).name()<<endl;

    std::string s = "This is an example";
    std::cout << s << '\n';

    s.erase(0, 5); // Erase "This "
    std::cout << s << '\n';

    auto it=std::find(s.begin(), s.end(), ' ');
    cout<<typeid(it).name()<<endl;

    s.erase(std::find(s.begin(), s.end(), ' ')); // Erase ' '
    std::cout << s << '\n';



    s.erase(s.find(' ')); // Trim from ' ' to the end of the string
    std::cout << s << '\n';
    cout<<'\0'<<" : "<<int('\0')<<endl;

    clock_t delay=10*CLOCKS_PER_SEC;
    clock_t start=clock();
    cout<<CLOCKS_PER_SEC <<endl;



    cout<< "over "<<endl;

    char word[50];
    cin>>word;

    cout<<word<<endl;
    cout<<word[0]<<endl;
}
