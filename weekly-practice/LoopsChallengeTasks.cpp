#include <iostream>
using namespace std;

// challenge question 1: Use a for loop to print all even numbers from 2 to 50

void printAllEvenNumbers(){
    for(int i = 2; i <= 50; i++){
        if(i % 2 == 0){
            cout << "Even Number: " << i << endl;
        }
    }
}
 
// challenge task 2: Use a while loop to repeatedly ask for input until the user enters a negative number.

void inputNegativeNumber(){
    int num = 1;

    cout << "Please enter a negative number: ";
    cin >> num;
 
    while (num >= 0) {
        cout << "Wrong!! Please enter a negative number: ";
        cin >> num;
    }
}

int main(){
    printAllEvenNumbers();

    inputNegativeNumber();

    return 0;
}