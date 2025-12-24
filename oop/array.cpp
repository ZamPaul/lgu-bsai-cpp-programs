#include <iostream>
using namespace std;

int main() {
    int students = 3;
    int subjects = 3;

    int marks[students][subjects] = {
        {85, 78, 90},   // Student 1
        {88, 92, 81},   // Student 2
        {75, 80, 85}    // Student 3
    };

    int topperIndex = 0;
    int highestTotal = 0;

    for (int i = 0; i < students; i++) {
        int total = 0;

        for (int j = 0; j < subjects; j++) {
            total += marks[i][j];
        }

        if (total > highestTotal) {
            highestTotal = total;
            topperIndex = i;
        }
    };

    cout << "Topper Student: Student " << topperIndex + 1 << endl;
    cout << "Total Marks: " << highestTotal << endl;

    return 0;
};