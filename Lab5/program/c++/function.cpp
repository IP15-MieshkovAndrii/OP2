#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "function.hpp"
using namespace std;

IndustrialTovar* recordIndTov(IndustrialTovar* catalog, int n){
    IndustrialTovar Obj;
    string name;
    string dateOfManufacture;
    double price;
    int number;
    string conditions;
    string place;
    int n_pl;
    
    for(int i=0; i<n; i++){
        cin.ignore();
        cout<<"Name: ";getline(cin, name);
        name = verifyName(name);
        cout<<"Date of manufacture(DD.MM.YYYY): ";cin>>dateOfManufacture;
        dateOfManufacture = verifyDate(dateOfManufacture);
        cout<<"Price: ";cin>>price;
        cout<<"Number of units: ";cin>>number;
        cin.ignore();
        cout<<"Terms of transportation: ";getline(cin, conditions);
        cout<<"Location\n1 - in stock\n2 - in the trading hall\n";cin>>n_pl;
        while(n_pl != 1 && n_pl != 2){
            cout<<"You can only choose 1 or 2\nEnter again: ";cin>>n_pl;
        }
        if(n_pl == 1){place = "stock";}
        else {place = "hall";}
        Obj.setIT(name, dateOfManufacture, price, number, conditions, place);
        catalog[i] = Obj;
        cout<<endl;
    }
    return catalog;
}

Foodstuff* recordFood(Foodstuff* catalog , int m){
    Foodstuff Obj;
    string name;
    string dateOfManufacture;
    double price;
    int number;
    string term;
    
    for(int i=0; i<m; i++){
        cin.ignore();
        cout<<"Name: ";getline(cin, name);
        name = verifyName(name);
        cout<<"Date of manufacture(DD.MM.YYYY): ";cin>>dateOfManufacture;
        dateOfManufacture = verifyDate(dateOfManufacture);
        cout<<"Price: ";
        cin>>price;
        cout<<"Number of units: ";
        cin>>number;
        cout<<"Expiration date(DD.MM.YYYY): ";cin>>term;
        term = verifyDate(term);
        term = verifyTerm(term, dateOfManufacture);
        Obj.setF(name, dateOfManufacture, price, number, term);
        catalog[i] = Obj;
        cout<<endl;
    }
    return catalog;
}

void overdue(Foodstuff* catalog, int m){
    Foodstuff Obj;
    double OverSum = 0;
    struct tm * timeinfo;
    time_t rawtime;
    time( &rawtime );
    timeinfo = localtime ( &rawtime );
    int dNow = timeinfo->tm_mday;
    int mNow = timeinfo->tm_mon + 1;
    int yNow = timeinfo->tm_year + 1900;
    for(int i=0; i<m; i++){
        catalog[i].get();
        cout<<endl;
        Obj = catalog[i];
        if(!Obj.who_stale(dNow, mNow, yNow, Obj.getTerm())){
            OverSum+=Obj.sum();
        }
    }
    if(OverSum != 0){
        cout<<"The total amount of expired foodstuffs: "<<OverSum<<"₴"<<endl;
    }
    else cout<<"No expired foodstuffs."<<endl;
    cout<<endl;
}

void goodsStock(IndustrialTovar* catalog, int n){
    IndustrialTovar Obj;
    double OverSum = 0;
    for(int i=0; i<n; i++){
        catalog[i].get();
        cout<<endl;
        Obj = catalog[i];
        if(Obj.in_stock()){
            OverSum+=Obj.sum();
        }
    }
    if(OverSum != 0){
        cout<<"The total amount of goods in stock: "<<OverSum<<"₴"<<endl;
    }
    else cout<<"No goods in stock."<<endl;
}


