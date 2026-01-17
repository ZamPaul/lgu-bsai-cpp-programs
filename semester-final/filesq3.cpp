#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream fin("D:/c++/semester-final/marks.txt");
    ofstream evenOut("D:/c++/semester-final/odd.txt", ios::app);
    ofstream oddOut("D:/c++/semester-final/even.txt", ios::app);
    
    if(!fin || !evenOut || !oddOut){
        cout << "Error opening files!";
        return -1;
    }

    int num;
    int evenCount = 0, oddCount = 0;

    while(fin >> num){
        if(num % 2 == 0){
            evenCount ++;
            evenOut << num << "\n";
        }else{
            oddCount ++;
            oddOut << num << "\n";
        }
    }

    fin.close();
    evenOut.close();
    oddOut.close();

    cout << evenCount << " numbers are even! " << oddCount << " numbers are odd!";

    return 0;
};