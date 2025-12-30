#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void clearBuffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getInteger(string prompt, string range = "positive", int min = -1, int max = -1){
    int input;

    while(true){
        cout << prompt;
        // incase of any string or other data type input
        if(!(cin >> input)){
            cin.clear();
            clearBuffer();
            cout << "Invalid Input! Please enter a numeric value.\n";
        }else if(range == "positive" && input<0){
            cout << "Error! Please enter a positive value\n"; 
            clearBuffer();
        }else if(range == "negative" && input>0){
            cout << "Error! Please enter a negative value\n"; 
            clearBuffer();
        }else if(range == "custom" && (input>max || input<min)){
            cout << "Error! Please enter a value between " << min << " and " << max << "!\n";
            clearBuffer();
        }else{
            clearBuffer();
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
    string name;
    string code;
    int credits;
    int internalMarks;
    int semesterMarks;

    float getTotalMarks(){
        // calculate aggregate of internal and external marks 
        return static_cast<float>(internalMarks + semesterMarks)/2;        
    }
};

struct Student{
    int rollNo;
    string name;
    vector<Subject> subjects;
    string grade;
    float totalMarks;

    float calculateTotalMarks(){
        float total = 0;
        // int nOfSubs = sizeof(subjects) / sizeof(subjects[0]);
        int size = subjects.size();
        for( int i=0; i<size; i++ ){
            total += subjects[i].getTotalMarks();
        }

        return total;
    }

    float calculatePercentage(){
        // int nOfSubs = sizeof(subjects) / sizeof(subjects[0]);
        int size = subjects.size();
        return static_cast<float>(totalMarks) / (size*100) * 100;
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

Student findTopper(vector<Student>& students){
    // finding topper student
    float highest = -1;
    Student topper;

    int size = students.size();

    for(int i=0; i<size; i++){
        if(students[i].totalMarks > highest){
            highest = students[i].totalMarks;
            topper = students[i];
        }
    }

    return topper;
}

Student findLowestMarks(vector<Student>& students){
    float lowest = 99999; 
    Student s;

    int size = students.size();
    
    for(int i=0; i<size; i++){
        if(students[i].totalMarks < lowest){
            lowest = students[i].totalMarks;
            s = students[i];
        }
    }

    return s;
}

// for displaying main menuu
void showMainMenu(){
    cout << "--- Welcome to Our Student Management ---\n";
    cout << "1. Display all Students\n";
    cout << "2. Search a Student\n";
    cout << "3. Add a new Student\n";
    cout << "4. Update a student record\n";
    cout << "5. Delete a student record\n";
    cout << "6. Find topper\n";
    cout << "7. Show grade statistics\n";
    cout << "8. Exit\n";
}

// menu functions
void readAllStudents(vector<Student>& students){
    // opening the file
    ifstream inFile("D:/c++/student-system/students.txt");

    if(!inFile){
        cout << "File could not be opened!";
        return;
    }

    string line;

    while(getline(inFile, line)){
        // make a new student
        Student s;

        stringstream ss(line);
        string token;

        getline(ss, token, '|');
        int rollNo = stoi(token);
        s.rollNo = rollNo;

        getline(ss, token, '|');
        string name = token;
        s.name = name;

        for(int i = 0; i < 2; i++){
            getline(ss, token, '|');
            stringstream sub(token);

            string subName, subCode, credits, internal, sem;
            getline(sub, subName, ',');
            getline(sub, subCode, ',');
            getline(sub, credits, ',');
            getline(sub, internal, ',');
            getline(sub, sem, ',');

            Subject newSubject = {subName, subCode, stoi(credits), stoi(internal), stoi(sem)};
            s.subjects.push_back(newSubject);
        }

        getline(ss, token, '|');
        s.totalMarks = static_cast<float>(stoi(token));

        getline(ss, token, '|');
        s.grade = token;

        students.push_back(s);
    }

    inFile.close();
    
}

void displayAllStudents(vector<Student>& students){
    int size = students.size();
    // cout << "\nSize of students vector" << size << endl;

    if(size==0){
        cout << "--- No Records found ---\n";
    }else{
        cout << "--- Students Records ---\n";
        for(int i=0; i<size; i++){
            cout << "Roll No: " << students[i].rollNo << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Grade: " << students[i].grade << "\n";
            cout << "Total Marks: " << students[i].totalMarks << "\n";

            cout << "Subjects: \n";
            for(int j=0; j<2; j++){
                cout << students[i].subjects[j].name << "(" << students[i].subjects[j].code << ") - "
                    << "Credits: " << students[i].subjects[j].credits 
                    << ", Internal Marks: " << students[i].subjects[j].internalMarks 
                    << ", Semester Marks: " << students[i].subjects[j].semesterMarks << "\n"; 
            }

            cout << "---------------------\n";
        }
    }
   
    // for(int i; )
}

void showSearchMenu(){
    cout << "----- Search Menu -----\n";
    cout << "1. Search student by Roll No\n";
    cout << "2. Search student by Name\n";
    cout << "3. Exit\n";
}

int searchStudentByRollNo(vector<Student>& students){
    int rollNo = getInteger("Enter the roll no, you want search: ", "positive");

    for(int i=0; i<students.size(); i++){
        if(students[i].rollNo == rollNo){
            return i;
        }
    }

    return -1;
}

int searchStudentByName(vector<Student>& students){
    string name = getString("Enter student name, you want search: ");

    for(int i=0; i<students.size(); i++){
        if(students[i].name == name){
            return i;
        }
    }

    return -1;
}

void displayStudent(Student s){
    cout << "----------------------------\n";
    cout << "Roll No: " << s.rollNo << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "Grade: " << s.grade << "\n";
    cout << "Total Marks: " << s.totalMarks << "\n";

    cout << "Subjects: \n";
    for(int j=0; j<2; j++){
        cout << s.subjects[j].name << "(" << s.subjects[j].code << ") - "
            << "Credits: " << s.subjects[j].credits 
            << ", Internal Marks: " << s.subjects[j].internalMarks 
            << ", Semester Marks: " << s.subjects[j].semesterMarks << "\n"; 
    }  
    cout << "----------------------------\n";
}

void searchStudent(vector<Student>& students){
    showSearchMenu();

    while(true){
        int choice = getInteger("Enter your choice for aearch(1-3): ", "custom", 1, 3);
        int idx;
        
        switch(choice){
            case 1:
                idx = searchStudentByRollNo(students);
                break;
            case 2:
                idx = searchStudentByName(students);
                break;
            default:
                break;
        }

        if(idx == -1){
            cout << "--- No records found ---\n";
        }else{
            displayStudent(students[idx]);
        }

        if(choice == 3){
            cout << "Exiting search menu!\n";
            cout << "Back to main menu.\n";
            break;
        }
    }
}

void addNewStudent(){
    int numOfSubjects = 2;
    int size = getInteger("Enter number of students: ", "positive");
    Student students[size];
    int countA = 0, countB = 0, countC = 0, countF = 0;

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

            students[i].subjects[j].credits = getInteger("Enter Subject Credits: ", "custom", 1, 100);
            students[i].subjects[j].internalMarks = getInteger("Enter internal marks: ", "custom", 1, 100);
            students[i].subjects[j].semesterMarks = getInteger("Enter end semester marks: ", "custom", 1, 100);
            
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

}

void writeFile(){

}

void updateStudent(){
    
}

void deleteStudent(){

}

void findTopper(){

}

void evaluateGradeStatistics(){

}

int main(){
    vector<Student> students;

    showMainMenu();

    while(true){
        int choice = getInteger("Enter your choce(1 to 8): ", "custom", 1, 8);
        
        switch(choice){
            case 1:
                readAllStudents(students);
                displayAllStudents(students);
                break;
            case 2:
                students.clear();
                readAllStudents(students);
                searchStudent(students);
                break;
            case 3:
                addNewStudent();
                break;
            case 4: 
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                findTopper();
                break;
            case 7:
                evaluateGradeStatistics();
                break;
            default:
                break;
        }

        if(choice == 8){
            cout << "Exiting the Main Menu. GoodBye!";
            break;
        }

    }
    
    return 0;
}