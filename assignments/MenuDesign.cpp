#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function prototypes defined here
void viewAllProducts();
void updateProduct();
void searchProduct();
void sortProducts();
void inventoryReport();

int main(){
    int choice = -9999999;

    cout << "---------------- INVENTORY MANAGEMENT SYSTEM ----------------" << endl;
    cout << "1. View All Products" << endl;
    cout << "2. Update a Product" << endl;
    cout << "3. Search a Product" << endl;
    cout << "4. Sort Products" << endl;
    cout << "5. Inventory Report" << endl;
    cout << "6. Exit" << endl;
    cout << "-------------------------------------------------------------" << endl;

    // loop until choice is not equal to 6
    while(choice != 6){
        cout << "Enter your choice(1-6): " << endl;
        cin >> choice;

        switch(choice){
            case 1: 
                viewAllProducts();
                break;
            case 2: 
                updateProduct();
                break;
            case 3: 
                searchProduct();
                break;
            case 4: 
                sortProducts();
                break;
            case 5: 
                inventoryReport();
                break;
            case 6:
                cout << "Exiting the System! GoodBye.";
                break;
            default:
                cout << "Invalid Choice. Please enter a number between 1-6!";
        }
        // program ends
    }
    
}

