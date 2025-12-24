#include <iostream>
#include <string>
#include <limits>

using namespace std;

// structs with arrays as well
struct Student {
    string name;
    int rollNo;
    int subjects[3];
    int total = 0;
};

// function to find topper with highest marks
int findTopper(Student students[], int n){
    int maxIndex = 0;
    int highestTotal = 0;

    // checking student with the highest
    for(int i = 0; i < n; i++){
        // calculating total marks
        int total = 0;

        for(int j = 0; j < 3; j++){
            total += students[i].subjects[j];
        }

        students[i].total = total;

        if(total > highestTotal){
            maxIndex = i;
            highestTotal = total;
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

        cout << "Enter Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, students[i].name);

        cout << "Enter Roll No: ";
        cin >> students[i].rollNo;

        // nested for loop for entering marks of every subject
        for(int j = 0; j <= 2; j++){
            cout << "Enter marks for subject " << j+1 << ": ";
            cin >> students[i].subjects[j];
        }
    }

    int maxIndex = findTopper(students, n);
    
    cout << "---------- Topper Details ---------" << endl;

    // student with the highest marks
    cout << "Student with the highest marks: " << endl;
    cout << "Name: " << students[maxIndex].name << endl;
    cout << "Roll No: " << students[maxIndex].rollNo << endl;
    cout << "Total Marks: " << students[maxIndex].total << endl;

    cout << "-----------------------------------" << endl;

    return 0;
}