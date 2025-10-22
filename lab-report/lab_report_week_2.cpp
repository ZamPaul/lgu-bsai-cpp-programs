#include <iostream>
using namespace std;

int main() {
    int start;
    
    cout << "Enter the starting number for countdown: ";
    cin >> start;
    
    cout << "Countdown begins:\n";
    for(int i = start; i >= 1; i--) {
        cout << i << "\n";
    }
    cout << "Blast Off!\n";

    return 0;
}

// int main() {
//     cout << "**" << endl;
//     cout << "**" << endl;
//     cout << "***" << endl;
//     cout << "****" << endl;
//     return 0;
// }


// int main() {
//     cout << "Hello World" << endl;
//     return 0;
// }