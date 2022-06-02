#include "verify.hpp"

string verifyName(string name){
    bool letter = true;
    string str;
    for(int i=0; i<name.size(); i++){
        if(!isalpha(name[0])){
            letter = false;
            str = "The name must start with a letter.\nEnter again: ";
            break;
            
        }
        if(!isspace(name[i]) && !isalpha(name[i])){
            letter = false;
            str = "The name consists only of letters.\nEnter again: ";
            break;
        }
    }
    
    if(!letter){
        cout<<str;getline(cin, name);
        name = verifyName(name);
    }
    return name;
}

string verifyDate(string date){
    string str;
    bool format = true;
    bool time;
    
    for(int i=0; i<date.size(); i++){
        if(date.size() > 10){
            format = false;
            str="Too many characters.\nEnter again: ";
            break;
        }
        if(date.size() < 10){
            format = false;
            str="Too few characters.\nEnter again: ";
            break;
        }
        if(i == 2 || i == 5){
            if(date[i] != '.'){
                format = false;
                str="Not the right format.\nEnter again: ";
                break;
            }
        }
        if(i != 2 && i != 5){
            if(!isdigit(date[i])){
                format = false;
                str="Not the right format.\nEnter again: ";
                break;
            }
        }
    }
    
    if(format){
        time = verifyTime(date);
        if(!time) str = "Non-existent date.\nEnter again: ";
    }
    if(!format || !time){
        cout<<str;getline(cin, date);
        date = verifyDate(date);
    }
    return date;
}
bool verifyTime(string date){
    Tovar obj;
    int d, m, y;
    bool flag = false;
    d = obj.days(date);
    m = obj.month(date);
    y = obj.years(date);
    
    if(m>=1 && m<=12){//перевірка на місяці
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){//місяці з 31 днем
            if(d>=1 && d<=31){
                flag = true;
            }
        }
        if(m == 4 || m == 6 || m == 9 || m == 11){
            if(d>=1 && d<=30){//місяці з 30 днями
                flag = true;
            }
        }
        else{//лютий у звичайний та високосний рік
            if(y%4 == 0){
                if(d>=1 && d<=29){
                    flag = true;
                }
            }
            else{
                if(d>=1 && d<=28){
                    flag = true;
                }
            }
        }
    }
    return flag;
}

string verifyTerm(string term, string dateM){
    Tovar obj;
    int dT, mT, yT, dM, mM, yM;
    bool flag = true;
    dT = obj.days(term);
    mT = obj.month(term);
    yT = obj.years(term);
    dM = obj.days(dateM);
    mM = obj.month(dateM);
    yM = obj.years(dateM);
    if(yT<yM)flag = false;
    else if (yT==yM){
        if(mT<mM)flag = false;
        else if (mT==mM){
            if(dT<=dM)flag = false;
            }
        }
    
    if(!flag){
        cin.ignore();
        cout<<"The expiration date may not be less than the date of manufacture.\nEnter again: ";
        getline(cin, term);
        term = verifyTerm(term, dateM);
    }
    return term;
}
