// QUESTION

// Input a 4 × 4 matrix

// Print the matrix

// Find:

// Row with maximum sum

// Column with minimum sum

// Use nested loops only

// Row/column numbering starts from 1

// SOLUTION:

#include <iostream>
using namespace std;

int main() {
    int arr[4][4];

    // Input matrix
    cout << "Enter elements of 4x4 matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    // Print matrix
    cout << "\nMatrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Find row with maximum sum
    int maxRowSum = 0, maxRowIndex = 0;

    for (int i = 0; i < 4; i++) {
        int rowSum = 0;
        for (int j = 0; j < 4; j++) {
            rowSum += arr[i][j];
        }

        if (i == 0 || rowSum > maxRowSum) {
            maxRowSum = rowSum;
            maxRowIndex = i;
        }
    }

    // Find column with minimum sum
    int minColSum = 0, minColIndex = 0;

    for (int j = 0; j < 4; j++) {
        int colSum = 0;
        for (int i = 0; i < 4; i++) {
            colSum += arr[i][j];
        }

        if (j == 0 || colSum < minColSum) {
            minColSum = colSum;
            minColIndex = j;
        }
    }

    // Output results
    cout << "\nRow with maximum sum: " << maxRowIndex + 1;
    cout << "\nColumn with minimum sum: " << minColIndex + 1;

    return 0;
}