#include <iostream>
#include <string>
using namespace std;

// function defined by user for a specific task
void inputArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << "Enter marks for student number " << i + 1 << ": ";
        cin >> arr[i];
    }
}

float calculateAverage(int arr[], int size){
    int total = 0;

    for(int i = 0; i < size; i++){
        total += arr[i];
    }

    float avg = total / size;

    return avg;
}

void displayResult(float avg){
    cout << "Average of all Marks is: " << avg;
}

int main(){
   int size = 5;
   int marks[5];
   float avg; 

   inputArray(marks, size);

   avg = calculateAverage(marks, size);

   displayResult(avg);
   
   return 0;
};