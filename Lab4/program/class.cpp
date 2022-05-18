#include "class.hpp"
#include "cmath"
using namespace std;


void VectorInSpace::getVector(){
    cout<<"("<<x<<", "<< y<< ", "<<z<<")"<<endl<<endl;
}

double VectorInSpace::module(){
    return sqrt(x*x + y*y + z*z);
}

VectorInSpace VectorInSpace::operator+(const VectorInSpace obj){
    VectorInSpace tmp(0);
    tmp.x = x + obj.x;
    tmp.y = y + obj.y;
    tmp.z = z + obj.z;
    return tmp;
}
double VectorInSpace::operator*(const VectorInSpace obj){
    return x * obj.x + y * obj.y + z * obj.z;
}

