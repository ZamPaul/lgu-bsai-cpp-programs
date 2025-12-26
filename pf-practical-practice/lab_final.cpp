#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int getInteger(string prompt, bool positive = false){
    int input;

    while(true){
        cout << prompt;
        // incase of any string or other data type input
        if(!(cin >> input)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter a numeric value.\n";
        }else if(positive && input<0){
            cout << "Error! Please enter a positive value\n"; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}

string getString(string prompt){
    string input;

    while(true){
        cout << prompt;
        getline(cin, input);
        // if input is empty space
        if(input.empty()){
            cout << "Input cannot be empty! Try again: \n";
            continue;
        }

        return input;
    }
}

struct Subject{
    string code;
    string name;
    int credits;
    int internalMarks;
    int semesterMarks;

    float getTotalMarks(){
        // calculate aggregate of internal and external marks 
        return (internalMarks + semesterMarks)/2;        
    }
};

struct Student{
    int rollNo;
    string name;
    Subject subjects[2];
    string grade;
    float totalMarks;

    float calculateTotalMarks(){
        float total = 0;
        int nOfSubs = sizeof(subjects) / sizeof(subjects[0]);
        for( int i=0; i<nOfSubs; i++ ){
            total += subjects[i].getTotalMarks();
        }

        return total;
    }

    float calculatePercentage(){
        int nOfSubs = sizeof(subjects) / sizeof(subjects[0]);
        return static_cast<float>(totalMarks) / (nOfSubs*100) * 100;
    }

    string evaluateGrade(){
        float per = calculatePercentage();
        string g;

        if(per >= 80){
            g = "A";
        }else if(per >= 65){
            g = "B";
        }else if(per >= 50){
            g = "C";
        }else{
            g = "F";
        }

        return g;
    }
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

Student findTopper(Student students[], int size){
    // finding topper student
    int highest = -1;
    Student topper;

    for(int i=0; i<size; i++){
        if(students[i].totalMarks > highest){
            highest = students[i].totalMarks;
            topper = students[i];
        }
    }

    return topper;
}

int main(){
    int numOfSubjects = 2;
    int size = getInteger("Enter number of students: ", true);

    Student students[size];

    int countA = 0, countB = 0, countC = 0, countF = 0;

    // inputing data from user
    for(int i=0; i<size; i++){
        cout << "Enter details of Student " << i+1 << ": \n"; 

        students[i].name = getString("Enter Name: ");
        students[i].rollNo = i+1;

        // input data for all the subjects
        // let's take 5 as an example here
        cout << "-------Subject Details-------\n";
        for(int j=0; j<numOfSubjects; j++){
            cout << "Enter details of Subject " << j+1 << ": \n"; 

            students[i].subjects[j].name = getString("Enter Subject Name: ");
            students[i].subjects[j].code = getString("Enter Subject Code: ");

            students[i].subjects[j].credits = getInteger("Enter Subject Credits: ");
            students[i].subjects[j].internalMarks = getInteger("Enter internal marks: ", true);
            students[i].subjects[j].semesterMarks = getInteger("Enter end semester marks: ", true);
            
            cout << "   \n";
        }

        // calculate marks for the currect student
        float totalMarks = students[i].calculateTotalMarks();
        
        // save total marks in the structure
        students[i].totalMarks = totalMarks;

        // evaluate grade and save grade in structure
        string grade = students[i].evaluateGrade();

        // save grade in structure
        students[i].grade = grade;

        // increments grades counts
        if(grade == "A"){
            countA += 1;
        }else if(grade == "B"){
            countB += 1;
        }else if(grade == "C"){
            countC += 1;
        }else{
            countF += 1;
        }
    }

    printBoard(students, size, numOfSubjects);

    Student topper = findTopper(students, size);

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