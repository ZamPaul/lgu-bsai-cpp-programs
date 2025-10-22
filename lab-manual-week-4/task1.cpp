#include <iostream>
#include <math.h>
using namespace std;

// operator precedence

int main(){
    int a, b, c, d, e, f, x, y;
    int A, B, C, Z, D;
    cout << "Enter coefficients a, b, c, d, e, f, x, y: ";
    cin >> a >> b >> c >> d >> e >> f >> x >> y;
    cout << "Enter coefficients B and C: ";
    cin >> B >> C;

    A = (B + C) / 2;
    D = pow((x + y), 2) / (x - y);
    Z = (a + b) * (c - d) / (e + f);


    cout << "Output A: " << A << endl;
    cout << "Output Z: " << Z << endl;
    cout << "Output D: " << D << endl;

    return 0;
}