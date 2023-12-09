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
    system("cls");
    ShowCur(0);

    const int x = 60, y = 5, w = 30, h = 2;
    string text1 = "           Sign up";
    string text2 = "           Sign in";
    box(x, y - 3, w, h, 14, 1, 14, "******* USER INTERFACE *******");
    box(x, y, w, h, 14, 1, 15, text1);
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

    const int x = 45, y = 5, w = 60, h = 2;
    string text1 = "                View personal information";
    string text2 = "                  List all saving books";
    string text3 = "               Open fixed-term saving book";
    string text4 = "                 Open nonterm saving book";
    string text5 = "                Withdraw money via ID book";
    string text6 = "                           Exit";

    box(x, y - 3, w, h, 14, 1, 14, "************************ USER MENU ************************");
    box(x, y, w, h, 14, 1, 15, text1);
    box(x, y + 2, w, h, 14, 1, 15, text2); 
    box(x, y + 4, w, h, 14, 1, 15, text3);
    box(x, y + 6, w, h, 14, 1, 15, text4);
    box(x, y + 8, w, h, 14, 1, 15, text5);
    box(x, y + 10, w, h, 14, 1, 15, text6);

    for(int i = 1; i < 6; i++){
        gotoXY(x, y + 2 * i); cout << char(195);
        gotoXY(x + w, y + 2 * i); cout << char(180);
    }
    
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
        case y:{
        INFOR:
			system("cls");
            fflush(stdin);
            
            const int x = 55, y = 5, w = 40, h = 2;
            box(x - 10, y - 3, w + 20, h, 14, 1, 14, "**************** VIEW PERSONAL INFORMATION ***************");
            box(x, y, w, h, 15, 1, 15, "           USER INFORMATION");
            box(x, y + 2, w, h, 15, 1, 15, "   Account ID   :");
            box(x, y + 4, w, h, 15, 1, 15, "    Full name   :");
            box(x, y + 6, w, h, 15, 1, 15, " ID card number :");
            box(x, y + 8, w, h, 15, 1, 15, "     Address    :");
            box(x, y + 10, w, h, 15, 1, 15, "  Phone number  :");
            for(int j = 1; j < 6; j++){
                gotoXY(x, y + 2 * j); cout << char(195);
                gotoXY(x + w, y + 2 * j); cout << char(180);
            }
            gotoXY(x + 20, y + 2 + 1); cout << user.getID();
            gotoXY(x + 20, y + 4 + 1); cout << user.getName();
            gotoXY(x + 20, y + 6 + 1); cout << user.getIDCard();
            gotoXY(x + 20, y + 8 + 1); cout << user.getAddress();
            gotoXY(x + 20, y + 10 + 1); cout << user.getTel();

            isContinue = toContinue1(x + 3, y + 14);
            if(isContinue == 1){
                goto MENU;
            }            
			break;            
        }

        case y + 2:{
        LIST:
            system("cls");
            fflush(stdin);
            const int x1 = 33, y1 = 5, h1 = 2, z1 = 5;
            int ck = 1;
            listTermBook.printUserTermBook(user, ck);
            cout << "\n\n";
            gotoXY(x1, getCurrentCursorPositionY());
            listNonTermBook.printUserNonTermBook(user, ck);
			isContinue = toContinue1(whereX() - 55, whereY() + 3);
            if(isContinue == 1){
                goto MENU;
            }            
			break;
        }
        case y + 4:{
        OPENTERM:
			system("cls");
            fflush(stdin);

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 14, 1, 14, "*************** OPEN FIXED-TERM SAVING BOOK **************");
            listTermBook.openTermBook(termBook, user, currentDate, x + 5, y + 2, w - 10, h);

			isContinue = toContinue1(x + 13, y + 18);
            if(isContinue == 1){
                goto MENU;
            }            
			break;        
        }

        case y + 6:{
        OPENNONTERM:
			system("cls");
            fflush(stdin);

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 14, 1, 14, "**************** OPEN NONTERM SAVING BOOK ****************");
            listNonTermBook.openNonTermBook(nonTermBook, user, currentDate, x, y, w, h);

			isContinue = toContinue1(x + 13, y + 5);
            if(isContinue == 1){
                goto MENU;
            }            
			break;            
        }
            
        case y + 8:{
        WITHDRAW:	
		    system("cls");
            fflush(stdin);
            SetColor(0); 
            textcolor(15);

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 14, 1, 14, "**************** WITHDRAW MONEY VIA ID BOOK ****************");


            const int x1 = 45, y1 = 7, h1 = 2, z1 = 5;
            int w1 = 60, w2 = 20;
            int J;
            int z;
            text1 = "     Term Book";
           	text2 = "  Non - term Book";
			
            gotoXY(x1, y1 - 1); cout << "           Which type of book do you want to withdraw?";
    		box(x1 + 20, y1, w2, h1, 15, 1, 15, text1);
    		gotoXY(x1 + 20, y1); cout << char(218);
    		gotoXY(x1 + 20 + w2, y1); cout << char(191);
    		box(x1 + 20, y1 + 2, w2, h1, 15, 1, 15, text2);
    		gotoXY(x1 + 20, y1 + 2); cout << char(195);
        	gotoXY(x1 + 20 + w2, y1 + 2); cout << char(180);
        	
    		int xp1;     //xp, yp: toa do thanh sang
    		xp1 = x1 + 20;
    		int yp1;    
			yp1 = y1; 
    		int xcu1, ycu1;   //xcu, ycu: toa do cu
    		int check;
    		kt = true;

            while(true){
                if(kt == true){
                    gotoXY(xcu, ycu);
                    if(ycu1 == y1) thanhSang(xcu1, ycu1, w2, h1, 1, 15, text1);
                    if(ycu1 == y1 + 2) thanhSang(xcu1, ycu1, w2, h1, 1, 15, text2);
                    xcu1 = xp1;
                    ycu1 = yp1;
                    if(ycu1 == y1) thanhSang(xp1, yp1, w2, h1, 100, 15, text1); //reset thanh sang cu
                    if(ycu1 == y1 + 2) thanhSang(xp1, yp1, w2, h1, 110, 15, text2);
                    kt = false;            
                }
                check = move(x1 + 20, y1, h1, yp1, kt, 2);
                if(check == y1 || check == y1 + 2){
                    break;
                }
            } 
            
            SetColor(0); 
            textcolor(15);
            switch(check){
                case y1:{
                M:	system("cls");
                	SetColor(0); 
            		textcolor(15);
                    
                    //Prompt user to enter the ID of the term book from which they want to withdraw money.
                    int ck = 1;
                    listTermBook.printUserTermBook(user, ck);
                    if(ck == 0){
                        break;
                    }else{
                        cout << endl;
                        string IDBook;
                        z = whereY();
                        box(x1 + 5, whereY() + 2, w1, h1, 15, 1, 14, "********* WITHDRAW MONEY FROM TERMBOOK VIA ITS ID **********");
                        box(x1 + 5, whereY(), w1, h1, 15, 1, 15, "      Enter the ID book: ");
                        gotoXY(x1 + 5, z + 4);
                        cout << char(195);
                        gotoXY(x1 + 5 + w1, z + 4);
                        cout << char(180);
                        gotoXY(x1 + 40, whereY() + 1);
                        cin >> IDBook;
                        cin.ignore();
                        TermBook *termBook = listTermBook.findBookByID(IDBook);
                        if(termBook != NULL){
                            float interestEarned = termBook->interestRate(currentDate, user);
                            gotoXY(x1 + 28, whereY() + 3);
                            if (interestEarned == -1){
                                goto F;
                            }else{
                                box(x1 + 10, whereY() + 1, w1 - 10, h1, 14, 1, 14, "       Interest earned:\n");
                                gotoXY(x1 + 45, whereY() - 1);
                                cout << interestEarned;
                                listTermBook.removeBookByIDBook(IDBook);
                            }
                        }    
                        else{
                            gotoXY(x1 + 20, whereY() + 2);
                            cout << "Error: Invalid ID TermBook. Try again!" << endl;
                            SetColor(72);
                            gotoXY(x1 + 25, whereY() + 1);
                            system("pause");
                            goto M;
                        }
                    }
                               
                    break; 
                }

                case y1 + 2: {
                M1:
                 	system("cls");
                	SetColor(0); 
            		textcolor(15);
                    
                    //Prompt user to enter the ID of the term book from which they want to withdraw money.
                    int ck = 1;
                    listNonTermBook.printUserNonTermBook(user, ck);
                    if(ck == 0){
                        break;
                    }else{
                        cout << endl;
                        string IDBook;

                        z = whereY();
                        box(x1 + 5, whereY() + 2, w1, h1, 15, 1, 14, "******** WITHDRAW MONEY FROM NONTERMBOOK VIA ITS ID ********");
                        box(x1 + 5, whereY(), w1, h1, 15, 1, 15, "      Enter the ID book: ");
                        gotoXY(x1 + 5, z + 4);
                        cout << char(195);
                        gotoXY(x1 + 5 + w1, z + 4);
                        cout << char(180);
                        gotoXY(x1 + 40, whereY() + 1);
                        cin >> IDBook;
                        cin.ignore();
                        NonTermBook *nonTermBook = listNonTermBook.findBookByID(IDBook);
                        if(nonTermBook != NULL){
                            float interestEarned = nonTermBook->interestRate(currentDate, user);
                            box(x1 + 10, whereY() + 1, w1 - 10, h1, 14, 1, 14, "       Interest earned:\n");
                            gotoXY(x1 + 45, whereY() - 1);
                            cout << interestEarned;
                            listNonTermBook.removeBookByIDBook(IDBook);
                        }else{
                            gotoXY(x1 + 15, whereY() + 2);
                            cout << "Error: Invalid ID non-termBook. Try again!";
                            SetColor(72);
                            gotoXY(x1 + 25, whereY() + 1);
                            system("pause");
                            goto M1;
                        }
                    }

                    break; 
                }
            }

		F:
            isContinue = toContinue1(x1 + 20, whereY() + 3);
            if (isContinue == 1){
                goto MENU;
            }

            break;
        }    
              
        case y + 10:{
            system("cls");
            end();       
            break;    
        }
    }
}
