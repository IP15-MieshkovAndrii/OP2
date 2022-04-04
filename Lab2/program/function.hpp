#ifndef function_hpp
#define function_hpp
#include <string>
using namespace std;
//структура для запису часу
struct Time {
    int hours, minutes;
    
    Time() {}
    
    Time(string time_str) {
        this->hours = atoi(time_str.substr(0, 2).c_str());
        this->minutes = atoi(time_str.substr(3, 2).c_str());
    }
};
//структура для данних події
struct EList {
    string name;
    Time time_start, duration;
};

//структура для вільного часу
struct FreeList{
    Time start, finish, free_dur;
};


string to_do_list();
string verifyName(string);
string verifyTime(string, string, string);
string verifyDuration(string, string);
bool hours(string);
bool dur(string, string, string);
bool duration_normal(string, string);
int time_to_int(string);
vector <EList> file_to_text(string);
void next_event(vector <EList>);
string free_time(vector <EList>);
void output_first(string);
void output_second(string);
string int_to_time(int);
string int_to_time(Time);

#endif
