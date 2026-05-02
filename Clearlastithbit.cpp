#include <iostream>
using namespace std;

int clearLastIBits(int n, int i){
    return (n & (~0 << i));
}

int main(){
    int n = 29, i = 3;
    cout << clearLastIBits(n, i); // Output -> 24
}