#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const string FILE_PATH = "D:/c++/student-system/students.txt";
const int SUBJECT_COUNT = 2;

void clearBuffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getInteger(const string prompt, const string range = "positive", const int min = -1, const int max = -1){
    int input;

    while(true){
        cout << prompt;
        // incase of any string or other data type input
        if(!(cin >> input)){
            cin.clear();
            clearBuffer();
            cout << "❌ Invalid Input! Please enter a numeric value.\n";
        }else if(range == "positive" && input<0){
            cout << "❌ Error! Please enter a positive value\n"; 
            clearBuffer();
        }else if(range == "negative" && input>0){
            cout << "❌ Error! Please enter a negative value\n"; 
            clearBuffer();
        }else if(range == "custom" && (input>max || input<min)){
            cout << "❌ Error! Please enter a value between " << min << " and " << max << "!\n";
            clearBuffer();
        }else{
            clearBuffer();
            return input;
        }
    }
}

string getString(const string prompt){
    string input;

    while(true){
        cout << prompt;
        getline(cin, input);
        // if input is empty space
        if(input.empty()){
            cout << "❌ Input cannot be empty! Try again: \n";
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
        for( int i=0; i<SUBJECT_COUNT; i++ ){
            total += subjects[i].getTotalMarks();
        }

        return total;
    }

    float calculatePercentage(){
        return static_cast<float>(totalMarks) / (SUBJECT_COUNT*100) * 100;
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

// for displaying main menuu
void showMainMenu(){
    cout << "--- Welcome to Our Student Management System ---\n";
    cout << "1. Display all Students\n";
    cout << "2. Search a Student\n";
    cout << "3. Add a new Student\n";
    cout << "4. Update a student record\n";
    cout << "5. Delete a student record\n";
    cout << "6. Find topper\n";
    cout << "7. Find student with the lowest marks\n";
    cout << "8. Show grade statistics\n";
    cout << "9. Exit\n";
}

// menu functions
void readAllStudents(vector<Student>& students){
    // opening the file
    ifstream inFile(FILE_PATH);

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

        for(int i = 0; i < SUBJECT_COUNT; i++){
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
    if(students.empty()){
        cout << "--- No Records found ---\n";
    }else{
        cout << "--- Students Records ---\n";
        for(Student& s : students){
            cout << "Roll No: " << s.rollNo << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Grade: " << s.grade << "\n";
            cout << "Total Marks: " << s.totalMarks << "\n";

            cout << "Subjects: \n";
            for(Subject& sub : s.subjects){
                cout << sub.name << "(" << sub.code << ") - "
                    << "Credits: " << sub.credits 
                    << ", Internal Marks: " << sub.internalMarks 
                    << ", Semester Marks: " << sub.semesterMarks << "\n"; 
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

int searchStudentByRollNo(const vector<Student>& students, const int rollNo){
    for(int i=0; i<students.size(); i++){
        if(students[i].rollNo == rollNo){
            return i;
        }
    }

    return -1;
}

int searchStudentByName(const vector<Student>& students, const string name){
    for(int i=0; i<students.size(); i++){
        if(students[i].name == name){
            return i;
        }
    }

    return -1;
}

void displayStudent(const Student& s){
    cout << "----------------------------\n";
    cout << "Roll No: " << s.rollNo << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "Grade: " << s.grade << "\n";
    cout << "Total Marks: " << s.totalMarks << "\n";

    cout << "Subjects: \n";
    for(Subject sub : s.subjects){
        cout << sub.name << "(" << sub.code << ") - "
            << "Credits: " << sub.credits 
            << ", Internal Marks: " << sub.internalMarks 
            << ", Semester Marks: " << sub.semesterMarks << "\n"; 
    }  
    cout << "----------------------------\n";
}

void searchStudent(const vector<Student>& students){
    showSearchMenu();

    while(true){
        int choice = getInteger("Enter your choice for search(1-3): ", "custom", 1, 3);
        int idx = -1;

        int rollNo;
        string name;
        
        switch(choice){
            case 1:
                rollNo = getInteger("Enter the roll no, you want search: ", "positive"); 
                idx = searchStudentByRollNo(students, rollNo);
                break;
            case 2:
                name = getString("Enter student name, you want search: ");
                idx = searchStudentByName(students, name);
                break;
            default:
                cout << "Exiting search menu!\n";
                cout << "Back to main menu.\n";
                // end the function
                return;
        }

        if(idx == -1){
            cout << "--- No records found ---\n";
        }else{
            displayStudent(students[idx]);
        }
    }
}

void writeNewStudent(Student& s){
    ofstream outFile(FILE_PATH, ios::app);

    if(!outFile){
        cout << "Error opening file!\n";
        return;
    }

    outFile << s.rollNo << "|";
    outFile << s.name << "|";
    
    for(Subject& sub : s.subjects){
        outFile << sub.name << ","
                << sub.code << ","
                << sub.credits << ","
                << sub.internalMarks << ","
                << sub.semesterMarks << "," 
                << "|";
    } 

    outFile << s.totalMarks << "|";
    outFile << s.grade << "\n";

    outFile.close();

    cout << "---- Student added successfully -----\n";
}

bool rollNoExists(vector<Student>& students, const int rollNo){
    for(Student& s : students){
        if(s.rollNo == rollNo){
            return true;
        }
    }

    return false;
}

void addNewStudent(vector<Student>& students){
    cout << "--- Add New Student ---\n";
    Student s;

    while(true){
        s.rollNo = getInteger("Enter roll No: ", "positive");
        
        if(rollNoExists(students, s.rollNo)){
            cout << "❌ Roll number already exists! Try another.\n";
        }else{
            break;
        }
    }
    
    s.name = getString("Enter Name: "); 

    cout << "--- Please enter Subject Details ---\n";
    cout << "\n";
    for(int i=0; i<SUBJECT_COUNT; i++){
        cout << "Subject " << i+1 << ": \n";
        Subject sub;
        sub.name = getString("Enter subject name: ");
        sub.code = getString("Enter subject code: ");

        sub.credits = getInteger("Enter credits: ", "custom", 1, 100);
        sub.internalMarks = getInteger("Enter internal marks: ", "custom", 1, 100);
        sub.semesterMarks = getInteger("Enter end semester marks: ", "custom", 1, 100);

        s.subjects.push_back(sub);
    }

    s.totalMarks = s.calculateTotalMarks();
    s.grade = s.evaluateGrade();

    students.push_back(s);
    
    writeNewStudent(s);
}

void showUpdateMenu(){
    cout << "What do you want to update?\n";
    cout << "1. Name\n";
    cout << "2. Subjects & Marks\n";
    cout << "3. Cancel\n";
}

void rewriteFile(const vector<Student>& students, const string msg){
    ofstream outFile(FILE_PATH);

    if(!outFile){
        cout << "Error opening file for updation!\n";
        return;
    }

    for(const Student& s : students){
        outFile << s.rollNo << "|";
        outFile << s.name << "|";
        
        for(const Subject& sub : s.subjects){
            outFile << sub.name << ","
                    << sub.code << ","
                    << sub.credits << ","
                    << sub.internalMarks << ","
                    << sub.semesterMarks << "," 
                    << "|";
        } 

        outFile << s.totalMarks << "|";
        outFile << s.grade << "\n";
    }

    outFile.close();

    cout << msg;
    
}

void updateStudent(vector<Student>& students){
    if(students.empty()){
        cout << "--- No records to update ---\n";
        return;
    }

    int rollNo = getInteger("Enter Roll Number to update: ", "positive");

    int idx = searchStudentByRollNo(students, rollNo);

    if(idx == -1){
        cout << "Student not found!\n";
        return;
    }

    Student& s = students[idx];

    cout << "--- Current Record ---\n";
    displayStudent(s);

    showUpdateMenu();

    int choice = getInteger("Enter your choice(1-3): ", "custom", 1, 3);

    switch(choice){
        case 1:
            s.name = getString("Enter new name: "); 
            break;
        case 2:
            s.subjects.clear();

            for(int i = 0; i < SUBJECT_COUNT; i++){
                cout << "Subject " << i + 1 << ":\n";

                Subject sub;
                sub.name = getString("Enter subject name: ");
                sub.code = getString("Enter subject code: ");
                sub.credits = getInteger("Enter credits: ", "custom", 1, 100);
                sub.internalMarks = getInteger("Enter internal marks: ", "custom", 1, 100);
                sub.semesterMarks = getInteger("Enter semester marks: ", "custom", 1, 100);

                s.subjects.push_back(sub);
            }

            s.totalMarks = s.calculateTotalMarks();
            s.grade = s.evaluateGrade();   

            break;
        case 3:
            cout << "Update cancelled!\n";
            return;
    }

    rewriteFile(students, "✅ Student record updated successfully\n");

    cout << "Exiting update menu!\n";
    
}

void deleteStudent(vector<Student>& students){
    if(students.empty()){
        cout << "--- No records to delete ---\n";
        return;
    }

    int rollNo = getInteger("Enter Roll Number to delete: ", "positive");

    int idx = searchStudentByRollNo(students, rollNo);

    if(idx == -1){
        cout << "Student not found!\n";
        return;
    }

    cout << "--- Student Record Found ---\n";
    displayStudent(students[idx]);

    cout << "Are you sure you want to delete this record?\n";
    cout << "1. Confirm ✅\n";
    cout << "2. Cancel ❌\n";

    int choice = getInteger("Enter choice (1-2): ", "custom", 1, 2);
    
    switch(choice){
        case 1:
            students.erase(students.begin() + idx);
            break;
        default:
            cout << "Deletion Cancelled\n";
            return;
    }

    rewriteFile(students, "🗑️ Student record deleted successfully.\n");
}

void findTopper(const vector<Student>& students){
    if(students.empty()){
        cout << "--- No records found ---\n";
        return;
    }

    Student topper = students[0];

    for(const Student& s : students){
        if(s.totalMarks > topper.totalMarks){
            topper = s;
        }
    }

    cout << "--- Topper Student ---";
    displayStudent(topper);
}

void findLowestMarks(const vector<Student>& students){
    if(students.empty()){
        cout << "--- No records found ---\n";
        return;
    }

    Student currStudent = students[0];

    for(const Student& s : students){
        if(s.totalMarks < currStudent.totalMarks){
            currStudent = s;
        }
    }

    cout << "--- Student with the lowest marks ---";
    displayStudent(currStudent);
}

void evaluateGradeStatistics(const vector<Student>& students){
    if(students.empty()){
        cout << "--- No records found ---\n";
        return;
    }

    int countA = 0, countB = 0, countC = 0, countF = 0;

    for(const Student& s : students){
        if(s.grade == "A"){
            countA++;
        }else if(s.grade == "B"){
            countB++;
        }else if(s.grade == "C"){
            countC++;
        }else if(s.grade == "F"){
            countF++;
        }
    }

    float perA = (static_cast<float>(countA) / students.size()) * 100;
    float perB = (static_cast<float>(countB) / students.size()) * 100;
    float perC = (static_cast<float>(countC) / students.size()) * 100;
    float perF = (static_cast<float>(countF) / students.size()) * 100;

    cout << "--- Grade Statistics ---\n";
    cout << "Grade A: " << countA << " (" << perA << "%)" << "\n";
    cout << "Grade B: " << countB << " (" << perB << "%)" << "\n";
    cout << "Grade C: " << countC << " (" << perC << "%)" << "\n";
    cout << "Grade F: " << countF << " (" << perF * 100 << "%)" << "\n";
}

int main(){
    vector<Student> students;

    showMainMenu();

    while(true){
        int choice = getInteger("Enter your choice(1 to 8): ", "custom", 1, 8);
        
        switch(choice){
            case 1:
                students.clear();
                readAllStudents(students);
                displayAllStudents(students);
                break;
            case 2:
                students.clear();
                readAllStudents(students);
                searchStudent(students);
                break;
            case 3:
                students.clear();
                readAllStudents(students);
                addNewStudent(students);
                break;
            case 4: 
                students.clear();
                readAllStudents(students);
                updateStudent(students);
                break;
            case 5:
                students.clear();
                readAllStudents(students);
                deleteStudent(students);
                break;
            case 6:
                students.clear();
                readAllStudents(students);
                findTopper(students);
                break;
            case 7:
                students.clear();
                readAllStudents(students);
                findLowestMarks(students);
                break;
            case 8:
                students.clear();
                readAllStudents(students);
                evaluateGradeStatistics(students);
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