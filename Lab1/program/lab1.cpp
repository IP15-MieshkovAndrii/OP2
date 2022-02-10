#include "function.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name_in = input();
    output(name_in);
    cout<<endl;
    string name_out = changefile(name_in);
    output(name_out);
    cin.get();
    
}
