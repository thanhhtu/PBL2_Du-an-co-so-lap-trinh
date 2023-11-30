#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeAdmin.h"

void homeAdmin(const Date &currentDate){
    Account admin, user;
    ListAdminAccount listAdmin;
    ListUserAccount listUser;

    listAdmin.setAdmins();
    listUser.setUsers();

    //dang ky, dang nhap
    system("cls");
    cout << "SIGN IN\n";
    listAdmin.signIn(admin);

    menuAdmin(listUser, user, currentDate);
}

void menuAdmin(ListUserAccount &listUser, Account &user, const Date &currentDate){
    int isContinue;

MENU:
    system("cls");
    float choice;
    do{
        cout << "MENU ADMIN\n";
        cout << "1. List user account information.\n";
        cout << "2. Look up user information via ID account.\n";
        cout << "3. Delete a user account via ID account.\n";
        cout << "4. Exit.\n";

        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        
        if(!(choice == int(choice) && choice >= 1 && choice <= 3)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }        
    }while(!(choice == int(choice) && choice >= 1 && choice <= 3));

    switch(int(choice)){
        case 1:
        LISTACCOUNT:
			system("cls");
            cout << "LIST OF USER ACCOUNT INFORMATION\n";
			
            listUser.printInforUsers();

			isContinue = toContinue();
			if(isContinue == 1){
				goto LISTACCOUNT;
			}
			else if(isContinue == 2){
				goto MENU;
			}

			break;

        case 2:
        FINDUSER:
			system("cls");
			
            fflush(stdin);
            listUser.getUserInforByID();

			isContinue = toContinue();
			if(isContinue == 1){
				goto FINDUSER;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;
    }
}