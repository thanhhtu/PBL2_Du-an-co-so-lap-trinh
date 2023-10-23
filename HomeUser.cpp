#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeUser.h"

void homeUser(const Date &currentDate){
    Account user;
    ListUserAccount listUser;
    TermBook termBook;
    ListTermBook listTermBook;

    listUser.setUsers();
    listTermBook.setTermBooks();
    
    //dang ky, dang nhap
    log(user, listUser);
    
    menuUser(user, listUser, termBook, listTermBook, currentDate);

}

void log(Account &user, ListUserAccount &listUser){
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

void menuUser(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, const Date &currentDate){
    int isContinue;

MENU:
    system("cls");
    float choice;
    do{
        cout << "MENU ADMIN\n";
        cout << "1. View personal information.\n";
        cout << "2. Open fixed-term saving books.\n";
        cout << "3. Open saving books without term.\n";
        cout << "4. List all saving books\n";
        cout << "5. Withdraw money via ID book.\n";
        cout << "6. Delete a user account via ID account.\n";

        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        
        if(!(choice == int(choice) && choice >= 1 && choice <= 6)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }        
    }while(!(choice == int(choice) && choice >= 1 && choice <= 6));

    switch(int(choice)){
        case 1:
        INFOR:
			system("cls");
            cout << "YOUR INFORMATION\n";
			
            fflush(stdin);
            user.printInfor();

			isContinue = toContinue();
			if(isContinue == 1){
				goto INFOR;
			}
			else if(isContinue == 2){
				goto MENU;
			}

			break;

        case 2:
        OPENTERM:
			system("cls");
			
            fflush(stdin);
            listTermBook.openTermBook(termBook, user, currentDate);

			isContinue = toContinue();
			if(isContinue == 1){
				goto OPENTERM;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;

        case 3:
        case 4:
        LIST:
            system("cls");
			
            fflush(stdin);
            
            listTermBook.printTermBooks();

			isContinue = toContinue();
			if(isContinue == 1){
				goto LIST;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;
    }
}