#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeUser.cpp"
#include "HomeAdmin.cpp"

int main(){
    float choice;
    
    do{
        system("cls");
        cout << "CONTROL PANNEL \n";
        cout << "1. ADMIN. \n";
        cout << "2. USER. \n"; 
        cout << "3. EXIT.\n";

        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        if(!(choice == int(choice) && choice >= 1 && choice <= 3)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }   

    }while(!(choice == int(choice) && choice >= 1 && choice <= 3));

    switch(int(choice)){
        case 1:
            HomeAdmin();
            break;

        case 2:
            HomeUser();
            break;
        case 3:
            exit(1);
            break;
    }
//    getch();
}