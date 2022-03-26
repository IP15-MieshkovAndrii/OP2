#include "function.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;



string to_do_list(){
    string name;
    EList text;
    string task_name, time_start, duration = "0", preTime="";

    
//  вводимо імʼя файлу
    cout << "Enter input file: ";
    cin >> name;
    name = name + ".dat";
    
    ofstream fout(name, ios::binary);

    char new_line = 'y';
    while(new_line == 'y'){
        cout<<"Enter a name of task(maximum number of characters - 20): ";
        cin>>task_name;
        task_name = verifyName(task_name);
        text.name = task_name;
        
        cout<<"Enter an event start time in this format HH:MM: ";
        cin>>time_start;
        time_start = verifyTime(time_start, duration, preTime);
        preTime = time_start;
        text.time_start = time_start;
        
        
        cout<<"Enter a duration in this format HH:MM: ";
        cin>>duration;
        duration = verifyDuration(duration, time_start);
        text.duration = duration;
        
        
        fout.write((char*)&text, sizeof(EList));

        if(duration_normal(duration, time_start)){
            cout << "\nDo you want to continue input task?[y/n]: ";
            cin >> new_line;
        }
        else{
            new_line = 'n';
        }
        cout<<endl;
    }


    fout.close();

    return name;
}


string verifyName(string name){
    while (name.size()>20 || name.size()<1){
        cout << "Enter a name again: ";
        cin >> name;
    }
    return name;
}

string verifyTime(string time, string duration, string preTime){
    bool flag_hours = hours(time);
    bool flag_duration = dur(time, duration, preTime);

    while(time.size()!=5 || time[2]!=':' || flag_hours || flag_duration){
        cout << "Enter a time again: ";
        cin >> time;
        flag_hours = hours(time);
        flag_duration = dur(time, duration, preTime);
    }
    return time;
}

string verifyDuration(string duration, string time){
    bool flag_hours = hours(duration);
    bool flag_dif = false;
    if(time_to_int(duration)+time_to_int(time) > 1440) flag_dif = true;
    while(duration.size()!=5 || duration[2]!=':' || flag_hours || flag_dif){
        cout << "Enter a duration again: ";
        cin >> duration;
        flag_hours = hours(duration);
        flag_dif = false;
        if(time_to_int(duration)+time_to_int(time) > 1440) flag_dif = true;
    }
    return duration;
}

bool hours(string time){
    bool flag = true;
    string h, m;
    h = time.substr(0, 2);
    m = time.substr(3, 2);
    int number_h = atoi(h.c_str()), number_m = atoi(m.c_str());

    if(number_h>=0 || number_h<=23){
        if(number_m>=0 || number_m<=59){
            flag = false;
        }
    }
    return flag;
}

bool dur(string time, string duration, string preTime){
    bool flag = false;
    int number = time_to_int(time);
    if(preTime!=""){
        int time_before = time_to_int(preTime);
        int d = time_to_int(duration);
        if(time_before + d > number){
            flag = true;
        }
    }
    return flag;
}

int time_to_int(string time){
    string h, m;
    h = time.substr(0, 2);
    m = time.substr(3, 2);
    int number = atoi(h.c_str())*60 + atoi(m.c_str());
    return number;
}

bool duration_normal(string duration, string time){
    bool flag = true;
    if(time_to_int(duration) + time_to_int(time) == 1440) flag = false;
    return flag;
}

void output_first(string name){//виводимо текст файлу
    EList text;
    ifstream fin(name, ios::binary);
    
    cout<<"File "<< name <<": \n";
    
    while (fin.read((char*)&text, sizeof(EList))){
        cout<< text.name <<", "<<  int_to_time(text.time_start)<<", "<<"duration: "<< int_to_time(text.duration)<< ";"<<endl;
    }
    fin.close();
    cout<<endl;
}

void output_second(string name){//виводимо текст файлу
    FreeList text;
    ifstream fin(name, ios::binary);
    
    cout<<"File "<< name <<": \n";
    
    while (fin.read((char*)&text, sizeof(FreeList))){
        cout<< int_to_time(text.start) <<"-"<< int_to_time(text.finish)<<", "<<"duration: "<< int_to_time(text.free_dur)<< ";"<<endl;
    }
    
    fin.close();
    cout<<endl;
}

vector <EList> file_to_text(string name){
    vector<EList> pack;
    EList text;
    ifstream fin(name, ios::binary);
    
    while (fin.read((char*)&text, sizeof(EList))){
        pack.push_back(text);
    }
    fin.close();
    cout<<endl;
    
    return pack;
}

void next_event(vector <EList> text){
    int j;
    int hour_task, minute_task;
    time_t rawtime;
    int time_now, time_task;
    int dif, min = 1440;
    string m;
    struct tm * timeinfo;
    time( &rawtime );
    timeinfo = localtime ( &rawtime );
    int hour = timeinfo->tm_hour, minute = timeinfo->tm_min;
    if(hour>=10 && minute<10) cout<<"Time now: "<< hour << ":" << "0"<< minute <<endl;
    if(hour<10 && minute<10) cout<<"Time now: "<< "0" << hour << ":" << "0"<< minute <<endl;
    if(hour<10 && minute>=10) cout<<"Time now: "<< "0" << hour << ":" << minute <<endl;
    if(hour>=10 && minute>=10) cout<<"Time now: "<< hour << ":" << minute <<endl;
    time_now = hour * 60 + minute;
    for(int i = 0; i < text.size(); i++){
        hour_task = text[i].time_start.hours;
        minute_task = text[i].time_start.minutes;
        time_task = hour_task * 60 + minute_task;
        dif = time_task - time_now;
        if(dif>0 && dif<min){
            j = i;
            min = dif;
        }
    }
    if(dif>0){
        cout<<"Next event: "<< text[j].name <<", "<<  int_to_time(text[j].time_start)<<", "<<"duration: "<< int_to_time(text[j].duration)<< ";"<<endl<<endl;
    }
    else cout<<"Today you have no more business!!!"<<endl<<endl;
}

string free_time(vector <EList> text){
    FreeList file;
    string s, i;
    int time_n, dur_n;
    string start = "13:00", finish = "23:59", free_dur = "10:59";
    bool task_flag = false;
    string name2;
    cout<<"Enter output file: "; cin>>name2;//називаємо другий файл

    name2+=".dat";
    ofstream fout(name2, ios::binary);
    
    for(int i = 0; i < text.size(); i++){
        time_n = text[i].time_start.hours * 60 + text[i].time_start.minutes;
        dur_n = text[i].duration.hours * 60 + text[i].duration.minutes;
        if(time_n + dur_n>=780){
            start = int_to_time(time_n + dur_n);
            if(i + 1 < text.size()){
                finish = int_to_time(text[i+1].time_start.hours * 60 + text[i+1].time_start.minutes);
            }
            else finish = "23:59";
            free_dur = int_to_time(time_to_int(finish) - time_to_int(start));
            file.start = start;
            file.finish = finish;
            file.free_dur = free_dur;
            fout.write((char*)&file, sizeof(FreeList));
            task_flag = true;
        }
    }
    if(!task_flag){
        file.start = start;
        file.finish = finish;
        file.free_dur = free_dur;
        fout.write((char*)&file, sizeof(FreeList));
    }
    
    fout.close();
    
    return name2;
        
}

string int_to_time(int num){
    string time;
    int h, m;
    h = num/60;
    m = num%60;
    if(h<10 && m<10) time ="0" + to_string(h) + ":" + "0" + to_string(m);
    if(m<10 && h>=10) time = to_string(h) + ":" + "0" + to_string(m);
    if(h<10 && m>=10) time = "0" + to_string(h) + ":" + to_string(m);
    if(h>=10 && m>=10) time = to_string(h) + ":" + to_string(m);
    return time;
}

string int_to_time(Time num){
    string time;
    int h, m;
    h = num.hours;
    m = num.minutes;
    if(h<10 && m<10) time ="0" + to_string(h) + ":" + "0" + to_string(m);
    if(m<10 && h>=10) time = to_string(h) + ":" + "0" + to_string(m);
    if(h<10 && m>=10) time = "0" + to_string(h) + ":" + to_string(m);
    if(h>=10 && m>=10) time = to_string(h) + ":" + to_string(m);
    return time;
}
       

