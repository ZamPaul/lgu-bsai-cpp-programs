#include <iostream>
using namespace std;

// Function to calculate area
float findArea(float length, float width)
{
    return length * width;
}
// Function to calculate perimeter
float findPerimeter(float length, float width)
{
    return 2 * (length + width);
}

// int main()
// {

//     float length, width;
//     cout << "Enter length: ";
//     cin >> length; 
//     cout << "Enter width: ";
//     cin >> width;
//     cout << "Area = " << findArea(length, width) << endl;
//     cout << "Perimeter = " << findPerimeter(length, width) << endl;

//     return 0;
// }

// void fucntion does not update the value in the original main fucntion here
void updateOne(int a){
    a = 5;
    cout << "Value of x inside this update function: " << a << endl;
}

// void fucntion does not update the value in the original main fucntion here
void updateTwo(int &a){
    a = 5;
    cout << "Value of x inside this update function: " << a << endl;
}

// int main(){
//     int x = 10;

//     cout << "Value of x before updation: " << x << endl;
//     updateTwo(x);
//     cout << "Value of x after updation: " << x << endl;

//     return 0;
// }

// new program here
void displayMessage()
{
    cout << "Hello from the function displayMessage.\n";
}

// int main()
// {
//     cout << "Hello from main.\n";
//     displayMessage();  // Call the function
//     cout << "Back in function main again.\n";
//     return 0;
// }

// new program
void first()
{
    cout << "I am now inside the function first.\n";
}

void second()
{
    cout << "I am now inside the function second.\n";
}

// int main()
// {
//     cout << "I am starting in function main.\n";
//     first();  // calls first()
//     second(); // calls second()
//     cout << "Back in function main again.\n";
//     return 0;
// }

// new program here

void deeper(){
    cout << "I am now in the function deep" << endl;
}

void deep(){
    cout << "I am now inside the deeper fucntion" << endl;
    deeper();
    cout << "Now i am back in deeper function" << endl;
}

// int main(){
//     cout << "I am starting in the main function right now" << endl;
//     deep();
//     cout << "Back now in the main function" << endl;

//     return 0;
// }


// new program here
void func1() {
    cout << "Abel was IN\n";
}

void func2() {
    cout << "I saw Elba\n";
}

int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;

    if (input < 10)
    {
        func1();
        func2();
    }
    else
    {
        func2();
        func1();
    }

    return 0;
}
