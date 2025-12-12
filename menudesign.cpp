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
        cout << "Enter your choice(1-6): ";
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
                cout << "Exiting the Inventory Management System! GoodBye.";
                break;
            default:
                cout << "Invalid Choice. Please enter a number between 1-6!" << endl;
        }
        // program ends
    }
    
}


void viewAllProducts(){
    cout << "Successfully viewed all Products!" << endl;
}

void updateProduct(){
    cout << "Successfully updated the Product!" << endl;
}

void searchProduct(){
    cout << "Successfully found the Product!" << endl;
}

void sortProducts(){
    int sortingChoice = -99999999;

    cout << "---------------- SUB-MENU FOR SORTING PRODUCTS ----------------" << endl;
    cout << "1. Sort by Price (Low to High)" << endl;
    cout << "2. Sort by Price (High to Low)" << endl;
    cout << "3. Sort by Name (A-Z)" << endl;
    cout << "4. Return to Main Menu" << endl;
    cout << "-------------------------------------------------------------" << endl;

    // loop until choice is 4
    while(sortingChoice != 4){
        cout << "Enter your choice for sorting products(1-4): ";
        cin >> sortingChoice;

        switch(sortingChoice){
            case 1: 
                cout << "Sorted products in ascending order" << endl;
                break;
            case 2: 
                cout << "Sorted products in descending order" << endl;
                break;
            case 3: 
                cout << "Sorted products in alphabetical order" << endl;
                break;
            case 4:
                cout << "Exiting the Sub-Menu for Sorting Products!" << endl;
                cout << "Back to Main Menu!" << endl;
                break;
            default:
                cout << "Invalid Sorting Choice. Please enter a number between 1-4!" << endl;
        }
    }

}

void inventoryReport(){
    cout << "Inventory report displayed Successfully!" << endl;
}