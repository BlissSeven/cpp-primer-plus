#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

void smart_ptr_test()
{
    cout<<endl<<string(8,'*')+"smart_ptr_test"+string(8,'*')<<endl;
    auto_ptr<string> films[5]={
        auto_ptr<string> (new string("Fowl Balls1")),
        auto_ptr<string> (new string("Fowl Balls2")),
        auto_ptr<string> (new string("Fowl Balls3")),
        auto_ptr<string> (new string("Fowl Balls4")),
        auto_ptr<string> (new string("Fowl Balls5"))
    } ;
    auto_ptr<string> pwin;
    pwin=films[2];

    try {
        cout<<*films[1]<<endl;
      //  cout<<*films[2]<<endl;

    }
    catch (runtime_error& e)
    {
        cout<<e.what()<<endl;
        return;
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
        return;
    }
    catch(...){
        cout<<"error"<<endl;
        return;
    }

}
#endif // SMART_PTR_HPP
