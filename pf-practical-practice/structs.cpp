#include <iostream>
using namespace std;

struct Student{
    string name;
    int marks;
};

int findTopper(Student arr[], int size){
    int highest = 0, maxIndex = 0;

    for(int i = 0; i<size; i++){
        if(arr[i].marks > highest){
            highest = arr[i].marks;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main(){
    Student students[5] = {
        {"Zamiel", 55},
        {"Asad", 88},
        {"Yurrajj", 99},
        {"MastiMoon", 66},
        {"Shakiman", 22}
    };

    int maxIndex = findTopper(students, 5);

    cout << "The topper is " << students[maxIndex].name << " with marks " << students[maxIndex].marks;

    return 0;
}