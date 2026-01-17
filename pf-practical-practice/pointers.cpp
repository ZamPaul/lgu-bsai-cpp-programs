#include <iostream>
#include <vector>

using namespace std;

void changeA(int* ptr){ // pass by reference using pointers
    *ptr = 20;
}

int main(){
    int a = 10; // value = 10  
    int* ptr1 = &a; // value = address of a
    int** ptr2 = &ptr1; // value = address of pointer prt1
    ptr1 += 20;

    // changeA(ptr1);

    cout << "value of ptr 1: " << ptr1 << endl;

    // cout << "value of a: " << a << endl;
    // cout << "deferenced value of prt1: " << *ptr1 << endl;
    // cout << "double deferenced value of prt2: " << **ptr2 << endl;

    return 0;
}