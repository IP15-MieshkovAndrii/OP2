#include "function.hpp"
#include <iostream>
#include <string>

using namespace std;

Student* array_objects(Student* catalog, int num_st){
    setlocale (LC_ALL, "Russian");
    string name_st, number, dOb;
    for(int i=0; i<num_st; i++){
        cin.ignore();
        cout<<"Введите ваше ФИО: ";
        getline(cin, name_st);
        number = verify_n(name_st);
        cout<<"Введите номер вашей группы(в формате ББ-ЦЦ): ";
        getline(cin, number);
        number = verify_gr(number);
        cout<<"Введите вашу дату рождения(в формате ММ-ДД-ГГГГ): ";
        getline(cin, dOb);
        dOb = verify_d(dOb);
        
        catalog[i] = Student(name_st, number, dOb);
    }
    cout<<endl;
    return catalog;
}


string verify_n(string name){
    bool flag_not_lit = is_Liter(name);
    bool three_word = three(name);

    while(name.size()>50 || flag_not_lit || three_word){
        cin.ignore();
        cout << "Введите еще раз: ";
        getline(cin, name);
        flag_not_lit = is_Liter(name);
        three_word = three(name);

  }
    return name;
}

bool is_Liter(string name){
    bool flag = false;
    for(int i=0; i<name.size(); i++){
        if(name[i] > 32 && name[i] < 45 || name[i] > 45 && name[i] < 65){
            flag = true;
            break;
        }
    }
    return flag;
}

bool three(string name){
    bool flag = false;
    int x = count(name.begin(), name.end(), ' ');
    if(x != 2){
        flag = true;
    }
    return flag;
}

string verify_gr(string number){
    bool flag_liter_dig = upper_dig(number);

    while(number.size()!=5 || number[2]!='-' || flag_liter_dig){
        cin.ignore();
        cout << "Введите еще раз: ";
        getline(cin, number);
        flag_liter_dig = upper_dig(number);
    }
    return number;
}

bool upper_dig(string num){
    bool flag = false;
    if(!isupper(num[0]) || !isupper(num[1]) || !isdigit(num[3]) || !isdigit(num[4])){
        flag = true;
    }
    return flag;
}

string verify_d(string date){
    bool flag_time = time_d(date);

    while(date.size()!=10 || date[2]!='-' || date[5]!='-' || flag_time){
        cin.ignore();
        cout << "Введите еще раз: ";
        getline(cin, date);
        flag_time = time_d(date);
  }
    return date;

}
bool time_d(string date){
    bool flag = true;
    int m, d, y;
    m = atoi(date.substr(0, 2).c_str());
    d = atoi(date.substr(3, 2).c_str());
    y = atoi(date.substr(6, 4).c_str());
    if(y>=1900 && y<=2019){
        if(m>=1 && m<=12){
            if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                if(d>=1 && d<=31){
                    flag = false;
                }
            }
            if(m == 4 || m == 6 || m == 9 || m == 11){
                if(d>=1 && d<=30){
                    flag = false;
                }
            }
            else{
                if(y%4 == 0){
                    if(d>=1 && d<=29){
                        flag = false;
                    }
                }
                else{
                    if(d>=1 && d<=28){
                        flag = false;
                    }
                }
            }
        }
    }
    return flag;
}

int oldest(Student* catalog, int num){
    int n_st;
    string oldest="01-01-2020";
    bool older;
    string group;
    cout<<"В какой группе найти старшего студента? ";
    cin>>group;
    for(int i=0; i<num; i++){
        if(catalog[i].number == group){
            older = who_older(catalog[i].dOb, oldest);
            if(older){
                oldest = catalog[i].dOb;
                n_st = i;
            }
        }
    }
    return n_st;
}

bool who_older(string date, string oldest){
    bool flag = false;
    int m, d, y, m_o, d_o, y_o;
    m = atoi(date.substr(0, 2).c_str());
    d = atoi(date.substr(3, 2).c_str());
    y = atoi(date.substr(6, 4).c_str());
    m_o = atoi(oldest.substr(0, 2).c_str());
    d_o = atoi(oldest.substr(3, 2).c_str());
    y_o = atoi(oldest.substr(6, 4).c_str());
    if(y<y_o){
        flag = true;
    }
    if(y=y_o){
        if(m<m_o){
            flag = true;
        }
        if(m=m_o){
            if(d<d_o){
                flag = true;
            }
            if(d=d_o){
                if(oldest == "01-01-2020"){
                    flag = true;
                }
            }
        }
    }
    return flag;
}
