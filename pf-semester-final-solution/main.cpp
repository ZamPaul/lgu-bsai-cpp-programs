#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Student{
    int roll_number;
    string name;
    float marks;
};

void q1Solution(){
    ifstream inFile("D:/c++/pf-semester-final-solution/students.txt");

    if(!inFile){
        cout << "Error opening the file";
        return;
    }

    Student students[3];
    float highest_marks = -99999.0;
    Student topper;

    string line, token;
    int count = 0;

    while(getline(inFile, line) && count<3){
        Student s;

        stringstream ss(line);

        getline(ss, token, ' ');
        s.roll_number = stoi(token);

        getline(ss, token, ' ');
        s.name = token;

        getline(ss, token, ' ');
        s.marks = static_cast<float>(stoi(token));

        students[count] = s;

        if(s.marks > highest_marks){
            topper = s;
            highest_marks = topper.marks;
        }

        count++;
    }

    inFile.close();

    cout << "--- Topper Student ----\n";
    cout << "Name: " << topper.name << endl;
    cout << "Marks: " << topper.marks << endl;
}

void q2Solution(){
    int n;
    cout << "Enter size of the traingle: ";
    cin>>n;

    for(int i = 1; i<=n; i++){
        for(int j=i; j>=1; j--){
            cout << j;
        }
        cout << endl;
    }
}

void q3Solution(){
    int arr[10];

    for(int i=0; i<10; i++){
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    for(int i=0; i<10-1; i++){
        for(int j = 0; j<10-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    };

    cout << "Second largest element in the array: " << arr[8];
}

int main(){
    q1Solution();
    q2Solution();
    q3Solution();

    return 0;
}