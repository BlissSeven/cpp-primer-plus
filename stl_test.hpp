#ifndef STL_TEST_HPP
#define STL_TEST_HPP
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <initializer_list>
using namespace std;



void output(const string&s){cout<<s<<" ";}
void stl_test()
{
    cout<<endl<<string(8,'*')<<"stl test "<<string(8,'*')<<endl;
    // iterator test
    {
        ostream_iterator <int,char> out_iter(cout," ");
        *out_iter++=15;

        string str="stl_test demo";
         ostream_iterator <char,char> out_iter2(cout," ");
        copy(&str[0],&str[str.size()],out_iter2);


        string s1[4]={"fine","fish","fashion","fate"};
        string s2[2]={"busy","living"};
        string s3[2]={"silly","singers"};

        vector<string> words(4);
        copy(s1,s1+4,words.begin());
        for_each(words.begin(),words.end(),output);
        cout<<endl;

        copy(s2,s2+2,back_insert_iterator<vector<string> > (words));
        for_each(words.begin(),words.end(),output);
        cout<<endl;

        copy(s3,s3+2,insert_iterator<vector<string> >(words,words.begin()));
        for_each(words.begin(),words.end(),output);
        cout<<endl;
   }
    // set test
    {
        string s1[6]={"buffoon","thickers","for","heavy","can","for"};
        string s2[6]={"metal","any","food","elegant","deliver","for"};
        set<string> A(s1,s1+6);
        set<string> B(s2,s2+6);
        ostream_iterator<string,char> out(cout," ");

        cout<<"Set A: ";
        copy(A.begin(),A.end(),out);
        cout<<endl;
        cout<<"Set B: ";
        copy(B.begin(),B.end(),out);
        cout<<endl;

        cout<<"set_union ";
        set_union(A.begin(),A.end(),B.begin(),B.end(),out);
        cout<<endl;

        cout<<"set_intersection ";
        set_intersection(A.begin(),A.end(),B.begin(),B.end(),out);
        cout<<endl;


        set<string> C;
        cout<<"set_union =C: ";
        set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string> >(C,C.begin()));
        copy(C.begin(),C.end(),out);

         cout<<endl;
    }
    {
        typedef int KeyType;
        typedef pair<const KeyType,string> Pair;
        typedef multimap<KeyType,string> MapCode;

        MapCode codes;
        codes.insert(Pair(415,"San Francisco"));
        codes.insert(Pair(510,"Oakland"));
        codes.insert(Pair(718,"Brooklyn"));
        codes.insert(Pair(718,"Staten Francisco"));
        codes.insert(Pair(415,"San Rafel"));
        codes.insert(Pair(510,"San Francisco"));

        cout<<"codes.count(415): "<<codes.count(415)<<endl;
        cout<<"codes.count(718): "<<codes.count(718)<<endl;

        for(auto it=codes.begin();it!=codes.end();it++)
            cout<<"(*it).first "<<(*it).first<<"(*it).second "<<(*it).second<<endl;

        cout<<"codes.equal_range(415): "<<endl;
        pair<MapCode::iterator,MapCode::iterator> range=codes.equal_range(415);
        for(auto it=range.first;it!=range.second;it++)
            cout<<(*it).second<<endl;
    }

    {
        vector<double> gr8={28,29,30,35,38,59};
        vector<double >m8={63,65,69,75,80,99};

        cout.setf(ios_base::fixed);
        cout.precision(2);

        ostream_iterator <double,char> out(cout," ");
        cout<<"gr8    ";
        copy(gr8.begin(),gr8.end(),out);
        cout<<endl;

        cout<<"m8    ";
        copy(m8.begin(),m8.end(),out);
        cout<<endl;

        vector<double> sum(6);

        transform(gr8.begin(),gr8.end(),m8.begin(),sum.begin(),plus<double>());

        cout<<"sum    ";
        copy(sum.begin(),sum.end(),out);
        cout<<endl;

        vector<double> prod(6);

        transform(gr8.begin(),gr8.end(),prod.begin(),bind1st(multiplies<double>(),2.5));

        cout<<"prod    ";
        copy(prod.begin(),prod.end(),out);
        cout<<endl;

    }
    {
       cout<<endl<<string(8,'*')<<"initializer_list test"<<string(8,'*')<<endl;
        initializer_list<double> d1={1.1,2.2,3.3,4.4};
        for(auto it=d1.begin();it!=d1.end();it++)
            cout<<typeid (it).name()<<"  "<<*it<<" ";
        cout<<endl;
    }


    cout<<endl;
}
#endif // STL_TEST_HPP
