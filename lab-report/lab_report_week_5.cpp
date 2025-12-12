#include <iostream>
using namespace std;


void verifyVoter(){
    int age = -2893;
    char selection = 'Z';

    while (age < 0) {
        cout << "Please enter an age greater than 0: ";
        cin >> age;
    }

    if (age >= 18) {
        while (!(selection == 'y' || selection == 'Y' || selection == 'n' || selection == 'N')) {
            cout << "Do you have a voter ID (Enter Y/N): ";
            cin >> selection;
        }

        if (selection == 'y' || selection == 'Y') {
            cout << "Congrats! You are Eligible for voting!" << endl;
        } else {
            cout << "Sorry! You are not Eligible for voting (no voter ID)!" << endl;
        }
    } else {
        cout << "Sorry! You are too young for voting!" << endl;
    }
}

void checkEvenOddNumber(){
    int num;

    cout << "Enter a number to check: ";
    cin >> num;

    while (num <= 0){
        cout << "Enter a number to check: ";
        cin >> num;
    }

    if(num % 2 == 0){
        // number is even
        cout << "Number is even";

        if(num % 4 == 0){
            cout << " and also divisible by four";
        }else{
            cout << ", but not divisible by four";
        }
    }else {
        cout << "Number is odd";
        
        if(num % 3 == 0){
            cout << " and also divisible by three";
        }else{
            cout << ", but not divisible by three";
        }
    }
}

int main() {
    verifyVoter();

    checkEvenOddNumber();

    return 0;
}
