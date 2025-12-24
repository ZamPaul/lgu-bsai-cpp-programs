#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    // firstly reading data from the file
    ifstream inFile("students.txt");

    if(!inFile.is_open()){
        cout << "File could not be opened";
        return 1;
    }

    int highest = -9999;
    int lowest = 9999;
    float total = 0;
    int count = 0;
    string topper;

    int marks;
    string name;

    cout << "Students Records: \n";

    while(inFile >> name >> marks){
        cout << name << " " << marks << endl;

        total += marks;
        count ++;

        if(marks > highest){
            highest = marks;
            topper = name;
        }
        if(marks < lowest){
            lowest = marks;
        }
    }

    inFile.close();

    float avg = total / count;

    cout << "----------- Results -----------";
    cout << "Average Marks: " << avg << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "-------------------------------";

    // writing the data back to the file
    ofstream outFile;
    outFile.open("students.txt", ios::app);

    if(!outFile.is_open()){
        cout << "File could not be opened";
        return 1;
    }

    outFile << "Average Marks: " << avg << endl;
    outFile << "Highest Marks: " << highest << endl;
    outFile << "Lowest Marks: " << lowest << endl;

    outFile.close();

    cout << "Data is appended";

    return 0;
}