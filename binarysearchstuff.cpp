#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

// binary search

int program(){
    int scores[] = {80, 90, 10, 22, 100};
    int sum = 0;

    for(int i = 0; i < 5; i++){
        sum += scores[i];
    }

    float average = sum / 5;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return average;
}

int selectionSort(){
    int arr[] = {64,25,12,22,11};
    int min;

    for(int i = 0; i<4
        
        
        ; i++){
        min = i;

        for(int j=i+1; j<5; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        // swap after finding minimun index
        swap(arr[i], arr[min]);
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) {           // FIXED : arr is not printable directly
        cout << arr[i] << " ";
    }
    cout << endl;

    return min;
}

int binarySearch(){
    int arr[6] = {2, 4, 6, 8, 10, 12};
    int low = 0, high = 5, key = 8, mid;

    while (low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            cout << "Your key is at index number " << mid << " of the array" << endl;
            break;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return mid;
}

int findMinMax(){
    int arr[] = {2, 100, 6, 21, -20, 20, 21, 34, 24, 5};
    int min = arr[0], max = arr[0];
    int length = sizeof(arr) / sizeof(arr[0]);

    for(int i = 1; i <= length; i++){
        if(min > arr[i]){
            max = min;
            min = arr[i];
        }else{
            max = arr[i];
        }
    }

    cout << "Min" << min << endl;
    cout << "Max" << max << endl;

    return min;
}

int main(){
    // binarySearch();
    // findMinMax();
    // program();
    selectionSort();


    return 0;
}
