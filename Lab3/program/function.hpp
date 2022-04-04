#ifndef function_hpp
#define function_hpp
#include <string>

#include <stdio.h>

using namespace std;

class Student{//клас Студент
public:
    Student() {}
    Student(string name, string number, string dOb){
        this->name = name;
        this->number = number;
        this->dOb = dOb;
    }
    string name;//імʼя
    string number;//номер групи
    string dOb;//дата народження
};

Student* array_objects(Student*, int);
string verify_n(string);
bool is_Liter(string);
bool three(string);
string verify_gr(string);
bool upper_dig(string);
string verify_d(string);
bool time_d(string);
int oldest(Student*, int);
bool who_older(string, string);

#endif
