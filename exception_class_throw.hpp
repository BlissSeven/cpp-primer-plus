#ifndef EXCEPTION_CLASS_THROW_HPP
#define EXCEPTION_CLASS_THROW_HPP

#include <iostream>
using namespace std;
#include <stdexcept>
#include <string>

class Sales{
public:
    enum {MONTHS=12};
    class bad_index :public logic_error
    {
    private:
        int bi;
    public:
        explicit bad_index(int ix,const string& s="index error in sales object");
        int bi_val () const {return  bi;}
        //virtual ~bad_index() throw(){}
        virtual ~bad_index() {}
    };
    explicit Sales (int yy=0);
    Sales(int yy,const double * gt,int n);
    virtual ~ Sales(){}
    int Year() const {return  year;}
    virtual double operator[](int i)const;
    virtual double operator[](int i);
private:
    double gross[MONTHS];
    int year;
};
//************************************************************//
class LabeledSales:public Sales
{
public:
    class nbad_index:public Sales::bad_index
    {
    private:
        string lbl;
    public:
        nbad_index(const string& lb,int ix,const string& s ="index error in labeledsales object");
        const string& label_val() const {return lbl;}
        //virtual ~nbad_index() throw(){}
       // virtual ~nbad_index() {}
    };
    explicit LabeledSales(const string& lb="none",int yy=0);
    LabeledSales(const string& lb,int yy,const double * gr,int n);
    virtual ~LabeledSales(){}

    const string& Label() const {return  label;}
    virtual double operator[](int i)const;
    virtual double operator[](int i);
private:
    string label;
};
//************************************************************//
Sales::bad_index::bad_index(int ix,const string& s)
    :std::logic_error(s),bi(ix)
{
}
Sales::Sales(int yy)
    :year(yy)
{
    for(int i=0;i<MONTHS;i++)
        gross[i]=0;
}
Sales::Sales(int yy,const double * gr,int n)
    :year(yy)
{
    int lim=(n<MONTHS) ? n:MONTHS;
    int i;
    for(i=0;i<lim;i++)
        gross[i]=gr[i];
    for(;i<MONTHS;i++)
        gross[i]=0;
}
double Sales::operator[](int i)const
{
    if(i<0 ||i>=MONTHS)
        throw bad_index(i);
    return gross[i];
}
double Sales::operator[](int i)
{
    if(i<0 ||i>=MONTHS)
        throw bad_index(i);
    return gross[i];
}

//***************************************//
LabeledSales::nbad_index::nbad_index(const string& lb,int ix,const string&s)
    :Sales::bad_index (ix,s),lbl(lb)
{}
LabeledSales::LabeledSales(const string& lb,int yy)
    :Sales (yy)
{
    label=lb;
}
LabeledSales::LabeledSales(const string& lb,int yy,const double * gr,int n)
    :Sales (yy,gr,n)
{
    label=lb;
}
double LabeledSales::operator[](int i)const
{
    if(i<0 || i>MONTHS)
        throw nbad_index(Label(),i);
    return Sales::operator[](i);
}
double LabeledSales::operator[](int i)
{
    if(i<0 || i>MONTHS)
        throw nbad_index(Label(),i);
    return Sales::operator[](i);
}
//************************************************************//
void exception_class_throw_test()
{
    cout<<endl<<"********exception_class_throw_test********"<<endl;
    double vals1[12]={1220,1,2,3,4,5,6,7,8,9,10,11};
    double vals2[12]={12,11,10,9,8,7,6,5,4,3,2,1};

    Sales sales1(2011,vals1,12);
    LabeledSales sales2("blogstar",2012,vals2,12);

    cout<<"first try: "<<endl;
    try{
        cout<<"sales2[12]: "<<sales2[20];
    }
    catch(LabeledSales::nbad_index& bad)
    {
        cout<<"catch(LabeledSales::nbad_index& bad)"<<endl;
        cout<<bad.what()<<endl;
        cout<<"compant: "<<bad.label_val()<<endl;
        cout<<"index: "<<bad.bi_val()<<endl;
    }
    catch(Sales::bad_index& bad)
    {
        cout<<"Sales::bad_index& bad)"<<endl;
        cout<<bad.what()<<endl;

        cout<<"index: "<<bad.bi_val()<<endl;
    }

    cout<<"second try: "<<endl;
    try {
        cout<<"sales1[12]: "<<endl<<sales1[12];

    }
    catch(LabeledSales::nbad_index& bad)
    {
        cout<<"catch(LabeledSales::nbad_index& bad)"<<endl;
        cout<<bad.what()<<endl;
        cout<<"compant: "<<bad.label_val()<<endl;
        cout<<"index: "<<bad.bi_val()<<endl;
    }
    catch(Sales::bad_index& bad)
    {
        cout<<"Sales::bad_index& bad)"<<endl;
        cout<<bad.what()<<endl;

        cout<<"index: "<<bad.bi_val()<<endl;
    }

}
#endif // EXCEPTION_CLASS_THROW_HPP
