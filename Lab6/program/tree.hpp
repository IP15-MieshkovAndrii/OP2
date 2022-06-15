#ifndef tree_hpp
#define tree_hpp
#include "function.hpp"
#include <stdio.h>
#include <cmath>

struct Node{
    int data;
    Node *left, *right;
};

class Tree{
    Node *root;
    int num;
public:
    int k;
    Tree():root(NULL){};
    Tree(int n): num(n){
        int m=0;
        for(int i=0; i<n; i++){
            m+=pow(2,i);
        }
        root = new Node [m];
        root = this->makeTree(n);
    };
    ~Tree(){delete root;};
    Node* get(){return root;}
    Node* makeTree(int n, int x=1);
    void print_Tree(Node* p, int level);
    
    void printCurrentLevel(Node* r, int level, int width, bool& flag, int i);
    void printLevelOrder(Node* r, int n);
};
#endif
