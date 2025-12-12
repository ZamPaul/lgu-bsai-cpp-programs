#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    if (num1 << num2)
    {
        cout << "num 1 is largest";
    }
    else if(num2 << num1)
        {
            cout << "num 2 is largest";
        }
    else if(num1 == num2)
    {
        cout << "both are equal";
    }

    return 0;
}