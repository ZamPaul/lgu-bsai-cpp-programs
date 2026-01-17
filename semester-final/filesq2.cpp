#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream fin("D:/c++/semester-final/marks.txt");

    if(!fin){
        cout << "Error opening the file";
        return -1;
    }

    int num, sum = 0, count = 0;
    float avg;

    while(fin >> num){
        sum += num;
        count ++;
    }

    avg = (float)sum / count;

    fin.close();

    ofstream fout("D:/c++/semester-final/marks.txt", ios::app);

    if(!fout){
        cout << "Error opening the file";
        return -1;
    }

    if(avg > 50){
        cout << "Pass";
        fout << "Pass\n";
    }else{
        cout << "Fail";
        fout << "Pass\n";
    }
    
    fout.close();

    return 0;
}