#include <iostream>
using namespace std;
#include <string>

void showDouble(int); // function prototype

// int main(){
//     int num;

//     for(num = 0; num < 10; num++){
//         showDouble(num);
//     }

//     return 0;
// }

// definition of function showDouble.
void showDouble(int val){
    cout << val << "\t" << val*2 << endl;
}


// Function prototype
void func1(double, int);

// int main()
// {
//     int x = 0;
//     double y = 1.5;

//     cout << x << " " << y << endl;     // Before call
//     func1(y, x);                        // Note: y (double) first, x (int) second
//     cout << x << " " << y << endl;     // After call

//     return 0;
// }

// Function definition
void func1(double a, int b)
{
    cout << a << " " << b << endl;
    a = 0.0;
    b = 10;
    cout << a << " " << b << endl;
}


// new program here
void show(int a)
{
    cout << "Integer: " << a << endl;
}

void show(double b)
{
    cout << "Double: " << b << endl;
}

void show(string s)
{
    cout << "String: " << s << endl;
}

// int main()
// {
//     show(10);      // calls show(int)
//     show(5.6);     // calls show(double)
//     show("Hi");    // calls show(string)

//     return 0;
// }

// new program

// Function prototypes (overloaded)
int manip(int);
int manip(int, int);
int manip(int, double);

// int main()
// {
//     int x = 2, y = 4, z;
//     double a = 3.1;
//     z = manip(x) + manip(x, y) + manip(y, a);
//     cout << z << endl;

//     return 0;
// }

// manip with one int parameter
int manip(int val1) {
    return val1 + val1 * 2;
}

// manip with two int parameters
int manip(int val1, int val2) {
    return (val1 + val2) * 2;
}

// manip with int and double
int manip(int val1, double val2) {
    return val1 * static_cast<int>(val2);
}


// new program
void showNumber()
{
    int number = 10;    // local variable – only exists inside this function
    cout << "Inside showNumber(), number = " << number << endl;
}

// int main()
// {
//     int number = 5;     // local variable – only exists inside main()
//     cout << "Inside main(), number = " << number << endl;

//     showNumber();       // calls the function

//     cout << "Back in main(), number is still = " << number << endl;

//     return 0;
// }

// new program

// Global variable - declared outside all functions
int counter = 0;

// Function that increases the global counter
void increment() {
    counter++;   // modifies the global variable
    cout << "Counter inside increment(): " << counter << endl;
}

// Function that displays the current counter value
void display() {
    cout << "Counter inside display(): " << counter << endl;
}

// int main() {
//     cout << "Initial counter value: " << counter << endl;

//     increment();   // increases counter to 1
//     increment();   // increases counter to 2

//     display();     // shows the current counter (2)

//     cout << "Counter in main(): " << counter << endl;

//     return 0;
// }


// new program
int factorial(int n)
{
    if (n == 1)          // Base Case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive Case
}

// int main()
// {
//     cout << "Factorial of 5 is: " << factorial(5) << endl;
//     return 0;
// }


// new program
int fibonacci(int n)
{
    if (n == 0 || n == 1)        // Base cases
        return n;
    
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

// int main()
// {
//     int n;
//     cout << "Enter how many terms: ";
//     cin >> n;

//     cout << "Fibonacci Series: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << fibonacci(i) << " ";
//     }
//     cout << endl;

//     return 0;
// }

// new program here
int sum(int n)
{
    if (n == 0)    // Base Case
        return 0;
    
    return n + sum(n - 1);   // Recursive Case
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers = " << sum(n) << endl;

    return 0;
}