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
    NonTermBook nonTermBook;
    ListNonTermBook listNonTermBook;

    listUser.setUsers();
    listTermBook.setTermBooks();
    listNonTermBook.setNonTermBooks();
    
    //dang ky, dang nhap
    log(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
}

void log(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
    ShowCur(0);
    system("cls");

    const int x = 33, y = 5, w = 30, h = 2;
    string text1 = "           Sign up";
    string text2 = "           Sign in";

    box(x, y - 3, w, h, 14, 1, 14, "======= USER INTERFACE =======");
    box(x, y, w, h, 14, 1, 15, text1);
    gotoXY(x, y); cout << char(218);
    gotoXY(x + w, y); cout << char(191);
    box(x, y + 2, w, h, 14, 1, 15, text2);
    gotoXY(x, y + 2); cout << char(195);
    gotoXY(x + w, y + 2); cout << char(180);
    
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
            xcu = xp;
            ycu = yp;
            if(ycu == y) thanhSang(xp, yp, w, h, 100, 15, text1); //reset thanh sang cu
            if(ycu == y + 2) thanhSang(xp, yp, w, h, 110, 15, text2);
            kt = false;            
        }
        check = move(x, y, h, yp, kt, 2);
        if(check == y || check == y + 2){
            break;
        }
    } 

    switch(check){
        case y:
            textcolor(1);
            listUser.signUp(user);
            system("cls");    
            menuUser(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
            break;
        case y + 2: 
            textcolor(1);
            listUser.signIn(user);
            system("cls"); 
            menuUser(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
            break;
    }
}

void menuUser(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
    int isContinue;

MENU:
    system("cls");
    SetColor(0);
    textcolor(15);

    const int x = 30, y = 5, w = 60, h = 2;
    string text1 = "                View personal information";
    string text2 = "                  List all saving books";
    string text3 = "               Open fixed-term saving books";
    string text4 = "              Open saving books without term";
    string text5 = "                Withdraw money via ID book";
    string text6 = "                           Exit";

    box(x, y - 3, w, h, 14, 1, 14, "************************ USER MENU ************************");
    box(x, y, w, h, 14, 1, 15, text1);
    box(x, y + 2, w, h, 14, 1, 15, text2); 
    box(x, y + 4, w, h, 14, 1, 15, text3);
    box(x, y + 6, w, h, 14, 1, 15, text4);
    box(x, y + 8, w, h, 14, 1, 15, text5);
    box(x, y + 10, w, h, 14, 1, 15, text6);

    gotoXY(x, y); cout << char(218);
    gotoXY(x + w, y); cout << char(191);
    gotoXY(x, y + 2); cout << char(195);
    gotoXY(x + w, y + 2); cout << char(180);
    gotoXY(x, y + 4); cout << char(195);
    gotoXY(x + w, y + 4); cout << char(180);
    gotoXY(x, y + 6); cout << char(195);
    gotoXY(x + w, y + 6); cout << char(180); 
    gotoXY(x, y + 8); cout << char(195);
    gotoXY(x + w, y + 8); cout << char(180); 
    gotoXY(x, y + 10); cout << char(195);
    gotoXY(x + w, y + 10); cout << char(180); 
    
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
            if(ycu == y + 8) thanhSang(xcu, ycu, w, h, 1, 15, text5);
            if(ycu == y + 10) thanhSang(xcu, ycu, w, h, 1, 15, text6);           
            xcu = xp;
            ycu = yp;
            if(ycu == y) thanhSang(xp, yp, w, h, 100, 15, text1); 
            if(ycu == y + 2) thanhSang(xp, yp, w, h, 100, 15, text2);
            if(ycu == y + 4) thanhSang(xp, yp, w, h, 100, 15, text3);
            if(ycu == y + 6) thanhSang(xp, yp, w, h, 100, 15, text4);
            if(ycu == y + 8) thanhSang(xp, yp, w, h, 100, 15, text5);
            if(ycu == y + 10) thanhSang(xp, yp, w, h, 100, 15, text6);
            kt = false;            
        }
        check = move(x, y, h, yp, kt, 6);
        if(check == y || check == y + 2 || check == y + 4 || check == y + 6 || check == y + 8 || check == y + 10){
            break;
        }
    }

    SetColor(0);
    textcolor(15);
    switch(check){
        case y:
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

        case y + 2:
        LIST:
            system("cls");
            fflush(stdin);
            listTermBook.printUserTermBook(user);
            cout << endl;
            listNonTermBook.printUserNonTermBook(user);

			isContinue = toContinue();
			if(isContinue == 1){
				goto LIST;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;

        case y + 4:
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

        case y + 6:
        OPENNONTERM:
			system("cls");
            fflush(stdin);
            listNonTermBook.openNonTermBook(nonTermBook, user, currentDate);

			isContinue = toContinue();
			if(isContinue == 1){
				goto OPENNONTERM;
			}
			else if(isContinue == 2){
				goto MENU;
			}
			
            break;
            
        case y + 8:
        WITHDRAW:	
		    system("cls");
            fflush(stdin);
            
            float choice;
            do{
                cout << "Which type of book do you want to withdraw?\n";
                cout << "1. Term Book.\n";
                cout << "2. Non-term Book.\n";

                cout << "Your choice: ";
                cin >> choice;
                cin.ignore();
                
                if(!(choice == int(choice) && choice >= 1 && choice <= 2)){
                    cout << "Invalid input!! Please choose again.\n" << endl;
                }        
            }while(!(choice == int(choice) && choice >= 1 && choice <= 2));

            switch((int)choice){
                case 1:{
                    //Prompt user to enter the ID of the term book from which they want to withdraw money.
                    listTermBook.printUserTermBook(user);

                    string IDBook;
                    cout << "Enter the ID Book of the book that you want to withdraw: ";
                    cin >> IDBook;
                    cin.ignore();

                    TermBook *termBook = listTermBook.findBookByID(IDBook);
                    if(termBook != NULL){
                        float interestEarned = termBook->interestRate(currentDate, user);
                        cout << "Interest earned: " << interestEarned << endl;
                    }    
                    listTermBook.removeBookByIDBook(IDBook);
                                       
                    break; 
                }

                case 2: {
                    listNonTermBook.printUserNonTermBook(user);

                    string IDBook;
                    cout << "Enter the ID Book of the book that you want to withdraw: ";
                    cin >> IDBook;
                    cin.ignore();

                    NonTermBook *nonTermBook = listNonTermBook.findBookByID(IDBook);
                    if(nonTermBook != NULL){
                        float interestEarned = nonTermBook->interestRate(currentDate, user);
                        cout << "Interest earned: " << interestEarned << endl;
                    }    
                    listNonTermBook.removeBookByIDBook(IDBook);

                    break; 
                }
            }
            
            isContinue = toContinue();
            if (isContinue == 1) {
                goto WITHDRAW;
            } else if (isContinue == 2) {
                goto MENU;
            }

            break;
            
        case y + 10:
            gotoXY(x + 20, y + 14); cout << "GOODBYE! SEE YOU AGAIN!";
            exit(1);
    }
}