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

    TermBook termBook;
    ListTermBook listTermBook;
    NonTermBook nonTermBook;
    ListNonTermBook listNonTermBook;

    listAdmin.setAdmins();
    listUser.setUsers();
    listTermBook.setTermBooks();
    listNonTermBook.setNonTermBooks();

    //dang ky, dang nhap
    system("cls");
    cout << "SIGN IN\n";
    listAdmin.signIn(admin);

    menuAdmin(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
}

void menuAdmin(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
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
            fflush(stdin);
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

        case 3:
        DELETEUSER:
			system("cls");
            fflush(stdin);

            cout << "LIST OF USER ACCOUNT INFORMATION\n";
            listUser.printInforUsers();

            float choice;
            do{
                cout << "Warning: If a user account is deleted, all bank books will be deleted.\n";
                cout << "Do you want to continue deleting your account?\n";
                cout << "1. Yes.\n";
                cout << "2. No.\n";

                cout << "Your choice: ";
                cin >> choice;
                cin.ignore();

                if(!(choice == int(choice) && choice >= 1 && choice <= 2)){
                    cout << "Invalid input!! Please choose again.\n" << endl;
                }        
            }while(!(choice == int(choice) && choice >= 1 && choice <= 2));            

            if(int(choice) == 1){
                string ID;
                cout << "Enter the ID of user you want to delete account: ";
                getline(cin, ID);
                listTermBook.removeBookByID(ID);
                listNonTermBook.removeBookByID(ID);
                listUser.removeUserByID(ID);
                cout << "The account of user with ID number " << ID << " has been successfully deleted\n";
            }

			isContinue = toContinue();
			if(isContinue == 1){
				goto DELETEUSER;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;            
    }
}