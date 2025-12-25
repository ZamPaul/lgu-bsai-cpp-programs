#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

struct Subject{
    string code;
    string name;
    string credits;
    int internalMarks;
    int semesterMarks;
};

struct Student{
    int rollNo;
    string name;
    Subject subjects[2];
    string grade;
    int totalMarks;
};

void printBoard(Student students[], int size, int subjects){
    cout << "--------Academic Board--------\n";
    for(int i=0; i<size; i++){
        cout << "Student Roll No: " << students[i].rollNo << "\n";
        cout << "Name: " << students[i].name << "\n"; 
        cout << "Student Grade: " << students[i].grade << "\n";
        cout << "Total: " << students[i].totalMarks << "\n";

        cout << "---Subjects Details---\n";
        for(int j=0; j<subjects; j++){
            cout << "Subject Name: " << students[i].subjects[j].name << ", Internal Marks: " << students[i].subjects[j].internalMarks << ", End Semester Marks: " << students[i].subjects[j].semesterMarks << "\n";
        }
        cout << "----------------------\n";
    }
    cout << "--------------------------------\n";
}

int calculateTotal(Subject subjects[], int size){
    int total = 0;

    for(int i=0; i<size; i++){
        total += subjects[i].internalMarks + subjects[i].semesterMarks;   
    }

    return total;
}

float calculatePercentage(int total){
    return static_cast<float>(total)/200 * 100;
}

int main(){
    int size;
    int numOfSubjects = 2;
    cout << "Enter the number of students: ";
    cin >> size;

    while(size <= 0){
        cout << "Enter positive number of students: ";
        cin >> size;
    }

    Student students[size];

    int countA = 0, countB = 0, countC = 0, countF = 0;

    // inputing data from user
    for(int i=0; i<size; i++){
        cout << "Enter details of Student " << i+1 << ": \n"; 

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, students[i].name);

        students[i].rollNo = i+1;

        // input data for all the subjects
        // let's take 5 as an example here
        cout << "-------Subject Details-------\n";
        for(int j=0; j<numOfSubjects; j++){
            cout << "Enter details of Subject " << j+1 << ": \n"; 

            cout << "Enter subject name: ";
            cin.ignore();
            getline(cin, students[i].subjects[j].name);

            cout << "Enter subject code: ";
            cin.ignore();
            getline(cin, students[i].subjects[j].code);

            cout << "Enter subject credits: ";
            cin.ignore();
            getline(cin, students[i].subjects[j].credits);

            cout << "Enter internal marks: ";
            cin >> students[i].subjects[j].internalMarks;

            cout << "Enter end semester marks: ";
            cin >> students[i].subjects[j].semesterMarks;
            
            cout << "   \n";
        }

        // calculate marks for the currect student
        int totalMarks = calculateTotal(students[i].subjects, numOfSubjects);
        
        // save total marks in the structure
        students[i].totalMarks = totalMarks;

        // retrieve percentage for grade
        float per = calculatePercentage(totalMarks);

        if(per >= 80){
            countA += 1;
            students[i].grade = "A";
        }else if(per >= 65){
            countB += 1;
            students[i].grade = "B";
        }else if(per >= 50){
            countC += 1;
            students[i].grade = "C";
        }else{
            countF += 1;
            students[i].grade = "F";
        }

    }

    printBoard(students, size, numOfSubjects);

    // finding topper student
    int highest = -1;
    Student topper;

    for(int i=0; i<size; i++){
        if(students[i].totalMarks > highest){
            highest = students[i].totalMarks;
            topper = students[i];
        }
    }

    cout << "--------Academic Results--------\n";
    cout << countA << " students got Grade A\n";
    cout << countB << " students got Grade B\n";
    cout << countC << " students got Grade C\n";
    cout << countF << " students got Grade F\n";
    cout << "--------Top Position Holder Details--------\n";
    cout << "Roll No: " << topper.rollNo << "\n";
    cout << "Name: " << topper.name << "\n";
    cout << "Total Marks: " << topper.totalMarks << "\n";
    cout << "Grade: " << topper.grade << "\n";
    cout << "-------------------------------------------\n";
    
    return 0;
}