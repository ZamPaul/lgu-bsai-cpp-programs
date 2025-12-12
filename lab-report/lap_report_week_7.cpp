#include <iostream>
using namespace std;

// question number 1:
int questionOne(){
    int num = 10;
    cout << "Enter numbers (0 to stop): ";
    cin >> num;

    while (num != 0) {
        cout << "You typed the number: " << num << endl;
        cout << "Enter next number: ";
        cin >> num;

        break;
    }

    cout << "Programmed stopped finally" << endl;
}

// question number 2 
int questionTwo() {
    int i = 1;

    // do {
    //     cout << "Number: " << i << endl;
    //     i++;
    // } while (i <= 5);
}

// question number 3
int questionThree(){
    int x = 2;

    while (x <= 12) {
        cout << "This is x's current value" << x << endl;
        x += 2;
    }

    cout << "12 Value reached";
}

// question number 4
int questionFour(){
    int x = 1;
    while (x <= 12) {
        cout << "\n this is positive odd number less than 12.. "<< x;
        x = x+2;
    };
}

// question number 5
int questionFive(){
    for (int i = 1; i <= 5; i++) {
        cout << "Count: " << i << endl;
    }
}

// question number 6
int questionSix(){
    for (int i = 1; i<=3; i++) {
        for (int j = 1; j<=2; j++){
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
}

int main(){
    // questionOne();
    // questionTwo();
    // questionThree();
    // questionFour();
    // questionFive();
    questionSix();

    return 0;
}