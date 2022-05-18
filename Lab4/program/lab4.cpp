#include <iostream>

#include "function.hpp"
using namespace std;
int main() {
    
    VectorInSpace M1(0), M2(0), M3(0);
    
    M1=new_vector1();
    cout<<"M1 = ";
    M1.getVector();
    
    M2=new_vector2();
    cout<<"M2 = ";
    M2.getVector();
    
    M3=M1+M2;
    cout<<"M3 = M1 + M2 = ";
    M3.getVector();
    
    cout<<"|M3| = "<< M3.module()<<endl<<endl;

    cout<<"M1 * M2 = "<<M1*M2<<endl<<endl;
    
}
