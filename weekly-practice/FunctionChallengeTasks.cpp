#include <iostream>
using namespace std;

// challenge 1:
// write a function that returns true in a number is prime otherwise false
int isPrime(){
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(num <= 1){
        // 0 and 1 are not prime number;
        return false;
    }

    // looping from 2 to half of the original number
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            return false; 
        }
    }

    // no divisible numbers found
    return true;
}

int convertToFarenheit(float temp){
    float farenheitValue = (temp * 9/5) + 32;
    
    return farenheitValue;
}

int main(){
    // prime number code here =>
    bool result = isPrime();

    if(result){
        cout << "Number is Prime" << endl;
    }else{
        cout << "Number is not Prime" << endl;
    }

    // celcius coversion code here =>
    // float celciusValue;
    // float newValue;
    // cout << "Enter temperature to convert: ";
    // cin >> celciusValue;

    // newValue = convertToFarenheit(celciusValue);

    // cout << "Temparature in Celcius: " << celciusValue << endl;
    // cout << "Temparature in Farenheit: " << newValue << endl;

    return 0;
}