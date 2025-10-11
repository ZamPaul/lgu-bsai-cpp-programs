// question 1
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

// question 1
int main()
{
    float A, P;
    float r, t;

    cout << "Enter the desired numbers: ";
    cin >> r >> t >> P;

    A = P * pow(1 + r / 100, t);

    cout << "Result: " << A;

    return 0;
}

// question 2
int main()
{
    float weight, BMI, height;

    cout << "Enter weight and height respectively: ";
    cin >> weight >> height;

    BMI = weight / pow(height,2);

    cout << "BMI is: " << BMI;

    return 0;
}

// question 3
int main()
{
    float r1, r2, R;
    cout << "Enter r1 and r2 respectively: ";
    cin >> r1 >> r2;

    R = (r1 * r2) / (r1 + r2);
    cout << "Result is: " << R;

    return 0;
}

// question 4
int main()
{
    float x, result;
    cout << "Enter x: ";
    cin >> x;

    result = (3 * pow(x, 2) + 2 * x + 1) / (x + 5);
    cout >> "Result is: " >> result;

    return 0;
}

// question 5
int main()
{
    float a, b, c, y;
    cout << "Enter a, b, and c: ";

    cin >> a >> b >> c;

    y = (a * a + b * b - 2 * a * b * cos(c)) / 2 * a * b;
    cout << "Result is: " << y;

    return 0;
}