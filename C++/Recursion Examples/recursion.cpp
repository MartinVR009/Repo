#include <iostream>

using namespace std;

void walk_iterative(int steps);
void walk_recursive(int steps);


int main(){
    //walk_iterative(50);
    walk_recursive(50);
    return 0;
}

void walk_iterative(int steps){
    for(int i = 0; i < steps; i++){
        cout<< "step #" <<i <<"\n";
    }
}

void walk_recursive(int steps){
    if(steps == 0){
        return;
    }else{
        cout<<"step #" <<steps <<"\n";
        walk_recursive(steps-1);
    }
}