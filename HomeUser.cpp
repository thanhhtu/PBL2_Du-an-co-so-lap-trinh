#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeUser.h"

void log(Account user, ListUserAccount listUser){
    float choice;
    do{
        system("cls");
        cout << "You want?\n";
        cout << "1. Sign up.\n";
        cout << "2. Sign in.\n";

        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        
        if(!(choice == int(choice) && choice >= 1 && choice <= 2)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }        
    }while(!(choice == int(choice) && choice >= 1 && choice <= 2));

    switch(int(choice)){
        case 1:
            system("cls");
            cout << "SIGN UP\n";
            listUser.signUp(user);
            break;
        
        case 2:
            system("cls");
            cout << "SIGN IN\n";
            listUser.signIn(user);
            break;
    }
}

void HomeUser(){
    Account user;
    ListUserAccount listUser;

    listUser.setUsers();

    //dang ky, dang nhap
    log(user, listUser);
    cout << "\nhello";
    cout << 1234;

}
