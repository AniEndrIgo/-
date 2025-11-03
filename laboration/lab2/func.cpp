#include "func.hpp"
#include <cmath>

bool IsPrime(int x){
    if (x<=1){
        return false;
    }
    for (int d=2;d<=sqrt(x);++d){
        if (x%d==0){
            return false; 
        }
    }
    return true;
}