#include "tree.hpp"
#include <iostream>
using namespace std;

Node* Tree::makeTree(int n, int x){
    if(n==0)return NULL;
    if(x==n+1)return NULL;
    int z;
    if(x==1)z=n;
    else z=x;
    Node* p = new Node;
    p->data = z;
    p->left = makeTree(n, x+1);
    p->right = makeTree(n, x+1);
    return p;
}

void Tree::print_Tree(Node* p, int level){
    if(p)
        {
            print_Tree(p->left,level + 1);
            for(int i = 0;i< level;i++) cout<<"   ";
            cout << p->data << endl;
            print_Tree(p->right,level + 1);
        }
}

void Tree::printCurrentLevel(Node* r, int level, int width, bool& flag, int heigh) {
    if (r == NULL) {
        space(2 * width + 1);
        if (level != 0) flag = false;
        if (!k) k = width;
        return;
    }
    if (level == 0) {
        if (!flag) {
            space(heigh * k - heigh * 3 / 2);
            cout << r->data;
            flag = true;
        }
        else {
            space(width);
            cout << r->data;
            space(width);
        }
    }
    else if (level > 0) {
        printCurrentLevel(r->left, level - 1, width, flag, heigh);
        space(1);
        printCurrentLevel(r->right, level - 1, width, flag, heigh);
    }
}

void Tree::printLevelOrder(Node* r, int n) {
    int h = n;
    int w = pow(2, h);
    int fullWidth = (2 * w - 1) / 2;
    bool flag;

    for (int i = 0; i <= h; i++) {
        flag = true;
        printCurrentLevel(r, i, fullWidth, flag, i);
        fullWidth /= 2;
        cout << endl;
    }
}
