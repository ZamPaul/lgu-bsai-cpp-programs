#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    
    // Taking input from user
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    // Comparing the two numbers
    cout << "\nComparison Results:" << endl;
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;
    
    if (num1 > num2) {
        cout << num1 << " is GREATER THAN " << num2 << endl;
    } else if (num1 < num2) {
        cout << num1 << " is LESSER THAN " << num2 << endl;
    } else {
        cout << num1 << " is EQUAL TO " << num2 << endl;
    }
    
    return 0;
}