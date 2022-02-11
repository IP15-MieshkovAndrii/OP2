#include "function.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name_in = input();//створення вихідного файлу
    output(name_in);//вивід вихідного файлу
    cout<<endl;
    string name_out = changefile(name_in);//переписання вихідного файлу
    output(name_out);//вивід створеного файлу
    cin.get();
}
