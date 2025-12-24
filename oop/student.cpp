#include <iostream>
#include <string>

using namespace std;

// structs and arrays(2d arrays) as well

struct Student {
    string name;
    int rollNo;
    // float marks;
    array subjects[3][3];
}

// function to find topper with highest marks
int findTopper(Student students[], int n){
    int maxIndex = 0;

    // checking student with the highest
    for(int i = 1; i < n; i++){
        if(students[i].marks > students[maxIndex].marks){
            maxIndex = i;
        }
    }
    
    return maxIndex;
}

int main(){
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    while(n <= 0){
        cout << "Enter positive number of students: ";
        cin >> n;
    }

    Student students[n];
    
    for(int i = 0; i < n; i++){
        cout << "Enter details of Student " << i + 1 << ": " << endl;

        // clearBuffer();
        cout << "Enter Name: ";
        cin >> students[i].name;

        cout << "Enter Roll No: ";
        cin >> students[i].rollNo;

        cout << "Enter marks: ";
        cin >> students[i].marks;
    }

    int maxIndex = findTopper(students, n);

    // cout << students;
    cout << "---------- Topper Details ---------" << endl;

    // student with the highest marks
    cout << "Student with the highest marks: " << endl;
    cout << "Name: " << students[maxIndex].name << endl;
    cout << "Roll No: " << students[maxIndex].rollNo << endl;
    cout << "Marks: " << students[maxIndex].marks << endl;

    cout << "-----------------------------------" << endl;

    return 0;
}