#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// searching algorithms

void linearSearch(int key){
    int arr[4] = {3,4,11,99};
    // represents null
    int idx = -1;
    
    for(int i = 0; i<4; i++){
        if(arr[i] == key){
            idx = i;
            break;
        }
    }

    (idx == -1) ? cout << "Element not found" : cout << "Element found at: " << idx;
}

int binarySearch(int key){
    int arr[6] = {3,1,0,12,15,17};
    int low = 0, high = 5, mid;

    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            cout << "Key found at index number: " << mid;
            break;
        }else if(arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return mid;
}

// sorting algorithms

void bubbleSort(){
    int arr[8] = {12,1,3,2,77,44,100,181};
    // int length = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<8-1; i++){
        for(int j = 0; j<8-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    };

    cout << "Sorted Array: ";
    for (int x = 0; x < length; x++) {           // FIXED : arr is not printable directly
        cout << arr[x] << " ";
    }
}

void selectionSort(){
    int arr[8] = {12,1,3,2,77,44,100,181};
    int length = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<length-1; i++){
        int min = i;

        for(int j=i+1; j<length; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }

    cout << "Sorted Array: ";
    for (int x = 0; x < length; x++) {           // FIXED : arr is not printable directly
        cout << arr[x] << " ";
    }
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
    // linearSearch(100);
    // binarySearch(15);
    // bubbleSort();


    return 0;
}
