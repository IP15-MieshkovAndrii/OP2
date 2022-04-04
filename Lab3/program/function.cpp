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
        number = verify_n(name_st);//перевірка вводу
        cout<<"Введите номер вашей группы(в формате ББ-ЦЦ): ";
        getline(cin, number);
        number = verify_gr(number);//перевірка вводу
        cout<<"Введите вашу дату рождения(в формате ММ-ДД-ГГГГ): ";
        getline(cin, dOb);
        dOb = verify_d(dOb);//перевірка вводу
        
        catalog[i] = Student(name_st, number, dOb);//запис обʼєкту у масив
    }
    cout<<endl;
    return catalog;
}


string verify_n(string name){
    bool flag_not_lit = is_Liter(name);//перевірка, що імʼя має тільки літери, виключно дефіс
    bool three_word = three(name);//перевірка, що має три слова роздільні пробілами

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
        if(name[i] > 32 && name[i] < 45 || name[i] > 45 && name[i] < 65){//перевірка на літери та дефіс
            flag = true;
            break;
        }
    }
    return flag;
}

bool three(string name){
    bool flag = false;
    int x = count(name.begin(), name.end(), ' ');//шукаємо два пробіли
    if(x != 2){
        flag = true;
    }
    return flag;
}

string verify_gr(string number){
    bool flag_liter_dig = upper_dig(number);//перевірка формату

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
    //перші два символи - великі латинські, два останні - цифри
    if(!isupper(num[0]) || !isupper(num[1]) || !isdigit(num[3]) || !isdigit(num[4])){
        flag = true;
    }
    return flag;
}

string verify_d(string date){
    bool flag_time = time_d(date);//перевірка дати

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
    if(y>=1900 && y<=2019){//рік народження з 1900 до 2019
        if(m>=1 && m<=12){//перевірка на місяці
            if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){//місяці з 31 днем
                if(d>=1 && d<=31){
                    flag = false;
                }
            }
            if(m == 4 || m == 6 || m == 9 || m == 11){
                if(d>=1 && d<=30){//місяці з 30 днями
                    flag = false;
                }
            }
            else{//лютий у звичайний та високосний рік
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
            older = who_older(catalog[i].dOb, oldest);//порівнюємо вік
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
    if(y<y_o){//порівняння років
        flag = true;
    }
    if(y=y_o){
        if(m<m_o){//порівняння місяців
            flag = true;
        }
        if(m=m_o){
            if(d<d_o){//порівняння днів
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
