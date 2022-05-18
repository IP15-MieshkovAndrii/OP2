#ifndef class_hpp
#define class_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class VectorInSpace{
    double x, y, z;
public:
    VectorInSpace(){}
    VectorInSpace(double xx=0, double yy=0, double zz=0): x(xx), y(yy), z(zz){}
    VectorInSpace(string vector){
        size_t num1 = vector.find(', ');
        size_t num2 = vector.rfind(', ');
        x=atof(vector.substr(0, num1).c_str());
        y=atof(vector.substr(num1+1, num2).c_str());
        z=atof(vector.substr(num2+1).c_str());
    }
    VectorInSpace(VectorInSpace& obj){
        x=obj.x;
        y=obj.y;
        z=obj.z;
    }
    void getVector();
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}
    double module();
    VectorInSpace operator+(const VectorInSpace obj);
    double operator*(const VectorInSpace obj);
    ~VectorInSpace(){}

    
};

#endif 
