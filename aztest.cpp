#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a char to check: ";
    cin >> ch;

    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            cout << "vowel";
            break;
        default:
            cout << "consonant";
    }

    return 0;
}
