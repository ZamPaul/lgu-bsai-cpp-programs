#include <iostream>
#include <string>
using namespace std;

void laamLele(int lambayi){
    for(int i = 1; i<=lambayi; i++){
        int bakiKaHissa = lambayi - i;
        int ekHissa = bakiKaHissa / 2;
        int dosraHissa = bakiKaHissa / 2;

        // cout << singlePart;
        if(i % 2 != 0){
            for(ekHissa; ekHissa>=1; ekHissa--){
                cout << " ";
            }
            for(int j = 1; j<=i; j++){
                cout << "*";
            }
            for(dosraHissa; dosraHissa>=1; dosraHissa--){
                cout << " ";
            }

            cout << "\n";
        }
    }
}

// int main(){
//     // KITNI LAMBAYI CHAHIYE???
//     int apkiLambayi;
//     cout << "Bolo kitni Lambayi chahiye: " << endl;
//     cin >> apkiLambayi;
//     laamLele(apkiLambayi);

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

void hollowLeftTraingle(int length){
    for(int i = 1; i <= length; i++){
        if(i <= 2 || i == length){
            for(int j = 1; j<=i; j++){
                cout << "*";
            } 
        }else{
            cout << "*";
            for(int j = 1; j<= i - 2; j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << '\n'; 
    }
}

int main(){
    int length;
    cout << "Enter the length of the traingle: ";

    cin >> length;
    hollowLeftTraingle(length);

    return 0;
}