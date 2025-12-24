#include <iostream>
#include <fstream>

usign namespace std;

int sumofNatural(int n){
    if(n == 0){
        return 0;
    }
    return n + sumOfNumbers(n - 1);
}


int printNto1(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    printNto1(n - 1);
}

int factorial(int n){
    // base case
    if(n == 1){
        return 1;
    }
    // recursive case
    return n * factorial(n - 1);
}
