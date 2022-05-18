#include "function.hpp"
#include <iostream>
#include <string>
using namespace std;

VectorInSpace new_vector1(){
    double x,y,z;
    cout<<"M1"<<endl;
    cout<< "x = ";cin>>x;
    cout<< "y = ";cin>>y;
    cout<< "z = ";cin>>z;
    VectorInSpace v(x,y,z);
    return v;
}
VectorInSpace new_vector2(){
    cin.ignore();
    string vector;
    cout<<"M2"<<endl;
    cout<< "(x, y, z) = ";
    getline(cin, vector);
    
    VectorInSpace v(vector);
    return v;
}
