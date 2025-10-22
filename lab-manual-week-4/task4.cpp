#include <iostream>
using namespace std;

int main() {
    float r, area;
    const float PI = 3.14159;
    
    cout << "Enter radius: ";
    cin >> r;
    
    area = PI * r * r;
    cout << "Area = " << area;
    
    return 0;
}