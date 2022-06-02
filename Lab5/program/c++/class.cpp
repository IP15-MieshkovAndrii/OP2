#include "class.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int Tovar::days(string date){
    return atoi(date.substr(0, 2).c_str());
}
int Tovar::month(string date){
    return atoi(date.substr(3, 2).c_str());
}
int Tovar::years(string date){
    return atoi(date.substr(6, 4).c_str());
}
int Tovar::days(){
    return atoi(dateOfManufacture.substr(0, 2).c_str());
}
int Tovar::month(){
    return atoi(dateOfManufacture.substr(3, 2).c_str());
}
int Tovar::years(){
    return atoi(dateOfManufacture.substr(6, 4).c_str());
}
int Foodstuff::daysT(){
    return atoi(term.substr(0, 2).c_str());
}
int Foodstuff::monthT(){
    return atoi(term.substr(3, 2).c_str());
}
int Foodstuff::yearsT(){
    return atoi(term.substr(6, 4).c_str());
}
bool Tovar::who_stale(string date1, string date2){
    bool fresh = true;
    int nd, nm, ny, td, tm, ty;
    nd = days(date1);
    td = days(date2);
    nm = month(date1);
    tm = month(date2);
    ny = years(date1);
    ty = years(date2);
    if(ny > ty){fresh = false;}
    else if (ny == ty){
        if(nm > tm){fresh = false;}
        else if (nm == tm){
            if(nd >= td){fresh = false;}
        }
    }
    return fresh;
}
bool Tovar::who_stale(int d, int m, int y, string date){
    bool fresh = true;
    int td, tm, ty;
    td = days(date);
    tm = month(date);
    ty = years(date);
    if(y > ty){fresh = false;}
    else if (y == ty){
        if(m > tm){fresh = false;}
        else if (m == tm){
            if(d >= td){fresh = false;}
        }
    }
    return fresh;
}


