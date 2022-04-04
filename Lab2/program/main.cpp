#include <iostream>
#include <ctime>
#include "function.hpp"
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main()
{

    
    string name_in = to_do_list();//створення вихідного файлу
    cout<<endl;
    output_first(name_in);//вивід вихідного файлу
    
    vector <EList> text = file_to_text(name_in);//перенесення тексту файлу у змінну
    
    next_event(text);//знаходження наступної події
    
    string name_out = free_time(text);//створення другого файлу
    output_second(name_out);//вивід створеного файлу
    cout<<endl;
    cin.get();
    

}
