#include <iostream>

using namespace std;

int fac_iterative(int x);
int fac_recursive(int x);


int main(){
    fac_iterative(5);
    cout << fac_recursive(5);
    return 0;
}

int fac_iterative(int x){
    int result = 1;
    for(int i = x; i > 1; i--){
        result *= i;
    }
    cout<< result;
}

int fac_recursive(int x){
    if(x == 0){
        return 1;
    }else{
        return  x * fac_recursive(x-1);
    }
}