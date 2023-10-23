#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeUser.cpp"
#include "HomeAdmin.cpp"
#include "Date.cpp"

int main(){
    title();
    system("cls");
    float choice;
    
    //demo
    int day, month, year;
    cout << "Enter current date: \n";
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    //

    Date currentDate(day, month, year);

    do{
        system("cls");
        cout << "CONTROL PANNEL \n";
        cout << "1. ADMIN. \n";
        cout << "2. USER. \n"; 
        cout << "3. EXIT.\n";

        cout << "Your choice: ";
        cin >> choice;

        if(!(choice == int(choice) && choice >= 1 && choice <= 3)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }   

    }while(!(choice == int(choice) && choice >= 1 && choice <= 3));

    switch(int(choice)){
        case 1:
            homeAdmin(currentDate);
            break;

        case 2:
            homeUser(currentDate);
            break;
        case 3:
            exit(1);
            break;
    }
}