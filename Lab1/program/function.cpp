#include "function.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input(){
    string name;
    int num;
    string line;
    string text="";
    bool isFirst = true;
    
    cout<<"Enter input file: ";
    cin>>name;
    name = name + ".txt";
    ofstream out(name);
    
    cout<<"\nEnter your text\nPress Enter to go to the next line\nPress Ctrl + D + Enter - to end writing:\n";

    string ascii_code = "^D";
    getline(cin, line);
    while(line.find(ascii_code)==string::npos){
            getline(cin, line);
            if (isFirst) {
                isFirst = false;
            }
            else {
                text +='\n';
            }
            text += line;
        }
    text = text.substr(0, text.size()-2);
    out<<text;
    out.close();
    return name;
}

void output(string name){
    ifstream in(name);
    string s;
    cout<<"File "<<name<<": \n";
    while(!in.eof()){
        getline(in,s);
        cout<<s<<endl;
    }
    in.close();
}

string changefile(string name){
    string s, i, anti;
    string sep=" ";
    size_t n;
    ifstream in(name);
    string name2;
    cout<<"Enter output file: "; cin>>name2;
    name2+=".txt";
    ofstream out(name2);
    bool isFirst = true;
    while(!in.eof()){
        getline(in, s);
        if (s == "") {
            continue;
        }
        while(1){
            n=s.rfind(sep);
            if(n+1 != string::npos){
                i=s.substr(n+1, 1);
                break;
            }
            else{
                s.erase(n,1);
            }
        }
        if (isFirst) {
            isFirst = false;
        } else {
            out << endl;
        }
        out<<i<<s;
    }
    out.close();
    in.close();
    return name2;
}

