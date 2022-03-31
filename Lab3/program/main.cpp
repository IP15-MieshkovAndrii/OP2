#include "function.hpp"
#include <iostream>
#include <string>

using namespace std;



int main() {
    setlocale (LC_ALL, "Russian");
    int num_st;
    int old_number;
    char flag = 'y';
    cout<<"Введите количество студентов: ";
    cin>>num_st;
    cout<<endl;
    
    Student *catalog = new Student [num_st];
    catalog = array_objects(catalog, num_st);
    while(flag == 'y'){
        old_number = oldest(catalog, num_st);
        cout<<catalog[old_number].name<<endl;
        cout<<"\nХотите еще найти студента? (y/n): ";
        cin>>flag;
    }
    
    delete [] catalog;

}

