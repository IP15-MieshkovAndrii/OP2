#ifndef class_hpp
#define class_hpp
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Tovar{
protected:
    string name;
    string dateOfManufacture;
    double price;
    int number;
public:
    Tovar(){}
    Tovar(string n, string d, double pr, int num): name(n), dateOfManufacture(d), price(pr), number(num){}
    
    ~Tovar(){};
    void setT(string n, string d, double pr, int num){
        name = n;
        dateOfManufacture = d;
        price = pr;
        number = num;
    }
    virtual void get(){
        cout<<name<<" - "<< dateOfManufacture<<", "<<price<<"₴, "<<number<<" units\n";
    }
    string getDate(){return dateOfManufacture;}

    bool who_stale(string date1, string date2);
    bool who_stale(int d, int m, int y, string date);
    double sum(){
        return price*number;
    }
    int days(string date);
    int month(string date);
    int years(string date);
    int days();
    int month();
    int years();
};
class IndustrialTovar : public Tovar{
    string conditions;
    string place;
public:
    IndustrialTovar(){}
    IndustrialTovar(string n, string d, double pr, int num, string c, string pl){
        setT(n,d,pr,num);
        conditions = c;
        place = pl;
    }
    IndustrialTovar(IndustrialTovar &tovar){
        setT(tovar.name, tovar.dateOfManufacture, tovar.price, tovar.number);
        conditions = tovar.conditions;
        place = tovar.place;
    }
    void setIT(string n, string d, double pr, int num, string c, string pl){
        setT(n,d,pr,num);
        conditions = c;
        place = pl;
    }
    void get(){
        Tovar::get();
        cout<<"Storage conditions: "<<conditions<<"\nLocation of goods: "<<place<<endl;
    }
    bool in_stock(){
        if(place=="stock")return true;
        else return false;
    }
    
};

class Foodstuff : public Tovar{
    string term;
public:
    Foodstuff(){}
    Foodstuff(string n, string d, double pr, int num, string t){
        setT(n,d,pr,num);
        term = t;
    }
    Foodstuff(Foodstuff &food){
        setT(food.name, food.dateOfManufacture, food.price, food.number);
        term = food.term;
    }
    void setF(string n, string d, double pr, int num, string t){
        setT(n,d,pr,num);
        term = t;
    }
    void get(){
        Tovar::get();
        cout<<"Shelf life until "<<term<<endl;
    }
    string getTerm(){return term;}
    int daysT();
    int monthT();
    int yearsT();
};



#endif
