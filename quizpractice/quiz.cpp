#include <iostream>
using namespace std;


// sum of an array

// int main(){
//     int scores[5] = {2,3,4,5,6};
//     int sum = 0;
//     float average;
//     float length = sizeof(scores) / sizeof(scores[0]);

//     char name[6] = {'h', 'e', 'l', 'l', 'o'};

//     for(int i = 0; i<length; i++)
//     {
//         sum += scores[i];
//     }

//     average = sum / length;

//     cout << "Sum: " << sum << endl;
//     cout << "Average: " << average << endl;
//     cout << name;

//     return 0;
// }

// swapping two numbers

// int main(){
//     int a = 10;
//     int b = 20;

//     swap(a,b);

//     cout << "After swapping: " << "a: " << a << "b: " << b;

//     return 0;
// }


void linearSearch(){
    int arr[5] = {2,4,5,7,10};
    int key = 7;
    int found = -1;

    for(int i = 0; i<5; i++){
        if(arr[i] == key){
            found = i;
        }
    }

    cout << "Found at: " << found;
}

void binarySearch(){

}

void mastiWithArray(){
    int arr[5] = {3,4,5,6,8};
    int newValue = 20;
    int pos = 2;
    // inserting
    // for(int i = 5; i < pos; i--){
    //     arr[i] = arr[i-1];
    // }
    // arr[pos] = newValue;

    // cout << arr[pos];

    // delete
    for(int i = 0; i < 5; i++){
        arr[i] = arr[i+1];
    }

    cout << arr[0];
}

int main(){
    // linearSearch();
    mastiWithArray();

    return 0;
}