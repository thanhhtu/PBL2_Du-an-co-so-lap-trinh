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
    log(user, listUser);
    
    menuUser(user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
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

void menuUser(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
    int isContinue;

MENU:
    system("cls");
    float choice;
    do{
        cout << "MENU USER\n";
        cout << "1. View personal information.\n";
        cout << "2. Open fixed-term saving books.\n";
        cout << "3. Open saving books without term.\n";
        cout << "4. List all saving books\n";
        cout << "5. Withdraw money via ID book.\n";         //2 loai so
        cout << "6. Exit.\n";

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

            
        case 4:
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

        case 5:
        WITHDRAW:	
		    system("cls");
            fflush(stdin);
            
            float choice;
            do{
                cout << "Which type of book do you want to withdraw?\n";
                cout << "1. Term Book.\n";
                cout << "2. Non-term Book.\n";
                cout << "3. All book.\n";

                cout << "Your choice: ";
                cin >> choice;
                cin.ignore();
                
                if(!(choice == int(choice) && choice >= 1 && choice <= 3)){
                    cout << "Invalid input!! Please choose again.\n" << endl;
                }        
            }while(!(choice == int(choice) && choice >= 1 && choice <= 3));

            switch((int)choice){
                case 1:{
                    //Prompt user to enter the ID of the term book from which they want to withdraw money.
                    listTermBook.printUserTermBook(user);

                    string IDBook;
                    cout << "Enter the ID Book of the book that you want to withdraw: ";
                    cin >> IDBook;
                    cin.ignore();

                    TermBook *termBook = listTermBook.findBookbyID(IDBook);
                    if(termBook != NULL){
                        float interestEarned = termBook->interestRate(currentDate, user);
                        cout << "Interest earned: " << interestEarned << endl;
                    }    
                                       
                    break; 
                }

                case 2: {
                    listNonTermBook.printUserNonTermBook(user);

                    string IDBook;
                    cout << "Enter the ID Book of the book that you want to withdraw: ";
                    cin >> IDBook;
                    cin.ignore();

                    NonTermBook *nonTermBook = listNonTermBook.findBookbyID(IDBook);
                    if(nonTermBook != NULL){
                        float interestEarned = nonTermBook->interestRate(currentDate, user);
                        cout << "Interest earned: " << interestEarned << endl;
                    }    
                                       
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

        

    }
}