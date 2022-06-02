#ifndef function_hpp
#define function_hpp
#include "class.hpp"
#include "verify.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

IndustrialTovar* recordIndTov(IndustrialTovar* , int);
Foodstuff* recordFood(Foodstuff* , int);
void overdue(Foodstuff*, int);
void goodsStock(IndustrialTovar* , int);
#endif 
