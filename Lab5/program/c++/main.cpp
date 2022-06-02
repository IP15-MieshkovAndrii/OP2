#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "function.hpp"

int main() {
    int n,m;
    cout<<"Enter number of industrial goods: ";cin>>n;
    IndustrialTovar *CatalogPT = new IndustrialTovar [n];
    CatalogPT = recordIndTov(CatalogPT, n);
    
    cout<<"Enter number of foodstuffs: ";cin>>m;
    Foodstuff *CatalogF = new Foodstuff [m];
    CatalogF = recordFood(CatalogF, m);
    
    overdue(CatalogF, m);
    
    goodsStock(CatalogPT, n);
    
    delete [] CatalogPT;
    delete [] CatalogF;
    
    
}
