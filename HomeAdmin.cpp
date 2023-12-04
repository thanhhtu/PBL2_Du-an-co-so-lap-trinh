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
    listAdmin.signIn(admin);

    menuAdmin(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
}

void menuAdmin(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
    int isContinue;

MENU:
    system("cls");
    SetColor(0);
    textcolor(15);

    const int x = 30, y = 5, w = 60, h = 2;
    string text1 = "               List user account information";
    string text2 = "          Look up user information via ID account";
    string text3 = "            Delete a user account via ID account";
    string text4 = "                           Exit";

    box(x, y - 3, w, h, 11, 1, 11, "************************ ADMIN MENU ***********************");
    box(x, y, w, h, 11, 1, 11, text1);
    box(x, y + 2, w, h, 11, 1, 15, text2); 
    box(x, y + 4, w, h, 11, 1, 15, text3);
    box(x, y + 6, w, h, 11, 1, 15, text4);

    gotoXY(x, y); cout << char(218);
    gotoXY(x + w, y); cout << char(191);
    gotoXY(x, y + 2); cout << char(195);
    gotoXY(x + w, y + 2); cout << char(180); 
    gotoXY(x, y + 4); cout << char(195);
    gotoXY(x + w, y + 4); cout << char(180);
    gotoXY(x, y + 6); cout << char(195);
    gotoXY(x + w, y + 6); cout << char(180); 
    
    int xp = x;     //xp, yp: toa do thanh sang
    int yp = y;     
    int xcu, ycu;   //xcu, ycu: toa do cu
    int check;
    int kt = true;

    while(true){
        if(kt == true){
            gotoXY(xcu, ycu);
            if(ycu == y) thanhSang(xcu, ycu, w, h, 1, 15, text1);
            if(ycu == y + 2) thanhSang(xcu, ycu, w, h, 1, 15, text2);
            if(ycu == y + 4) thanhSang(xcu, ycu, w, h, 1, 15, text3);
            if(ycu == y + 6) thanhSang(xcu, ycu, w, h, 1, 15, text4);            
            xcu = xp;
            ycu = yp;
            if(ycu == y) thanhSang(xp, yp, w, h, 150, 15, text1); 
            if(ycu == y + 2) thanhSang(xp, yp, w, h, 150, 15, text2);
            if(ycu == y + 4) thanhSang(xp, yp, w, h, 150, 15, text3);
            if(ycu == y + 6) thanhSang(xp, yp, w, h, 150, 15, text4);
            kt = false;            
        }
        check = move(x, y, h, yp, kt, 4);
        if(check == y || check == y + 2 || check == y + 4 || check == y + 6){
            break;
        }
    }

    SetColor(0);
    textcolor(15);
    switch(check){
        case y:
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

        case y + 2:
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

        case y + 4:
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

        case y + 6:
            gotoXY(x + 25, y + 14); cout << "GOODBYE! SEE YOU AGAIN!";
            exit(1);
    }
}