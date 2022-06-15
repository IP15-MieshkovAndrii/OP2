#include "function.hpp"
#include <iostream>
using namespace std;

void space(int count) {
    for (int i = 0; i < count; i++) {
        cout << ' ';
    }
}

void newTree(int n){
    int l;
    if(n>0){
        Tree binTree(n);
        cout<<"What tree do you want?\nHorizontal(1) or Vertical(2)?\n";
        cin>>l;
        switch (l) {
            case 1:
                binTree.print_Tree(binTree.get(), 0);
                break;
                
            case 2:
                binTree.printLevelOrder(binTree.get(), n);
                break;
                
            default:
                break;
        }
        cout<<endl;
        
    }
    else cout<<"Impossible to create TREE"<<endl;
}
