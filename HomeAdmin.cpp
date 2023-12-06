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

    menuAdmin(admin, listAdmin, user, listUser, termBook, listTermBook, nonTermBook, listNonTermBook, currentDate);
}

void menuAdmin(Account &admin, ListAdminAccount &listAdmin, Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate){
    listAdmin.signIn(admin);
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

    for(int i = 1; i < 4; i++){
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
        case y:{
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
        }

        case y + 2:{
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

        case y + 4:{
        DELETEUSER:
			system("cls");
            fflush(stdin);
            
            const int x = 30, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 11, 1, 11, "************ DELETE USER ACCOUNT VIA ID ACCOUNT **********");
            SetColor(0);
            textcolor(15);          
            gotoXY(x - 10, y + 1); cout << "Warning: If a user account is deleted, all bank books of this user account will be deleted.";
            box(x + 6, y + 3, w - 11, h + 5, 11, 1, 15, " Do you want to continue deleting this account?");
            
            const int xx = 56, yy = 10, ww = 10, hh = 2; 
            string text1 = "   Yes";
            string text2 = "   No";
            box(xx, yy, ww, hh, 15, 1, 15, text1);
            box(xx, yy + 2, ww, hh, 15, 1, 15, text2);

            gotoXY(xx, yy + 2); cout << char(195);
            gotoXY(xx + ww, yy + 2); cout << char(180);     

            int xp = xx;     
            int yp = yy;     
            int xcu, ycu;   
            int check;
            int kt = true;            
            while(true){
                if(kt == true){
                    gotoXY(xcu, ycu);
                    if(ycu == yy) thanhSang(xcu, ycu, ww, hh, 1, 15, text1);
                    if(ycu == yy + 2) thanhSang(xcu, ycu, ww, hh, 1, 15,  text2);
                    xcu = xp;
                    ycu = yp;
                    if(ycu == yy) thanhSang(xp, yp, ww, h, 150, 15, text1); 
                    if(ycu == yy + 2) thanhSang(xp, yp, ww, h, 150, 15, text2);
                    kt = false;            
                }
                check = move(xx, yy, hh, yp, kt, 2);
                if(check == yy || check == yy + 2){
                    break;
                }
            }          

            SetColor(15);
            textcolor(0);
            switch(check){
                case yy:{
                    system("cls");
                    const int x = 20, y = 5, w = 80, h = 2;
                    box(x, y - 3, w, h, 11, 1, 11, "********************** DELETE USER ACCOUNT VIA ID ACCOUNT *********************");
                    box(x, y, w, h, 15, 1, 15, " Enter the ID of user you want to delete account: ");

                    string ID;
                    gotoXY(x + 51, y + 1); getline(cin, ID);
                    fflush(stdin);
                    listTermBook.removeBookByID(ID);
                    listNonTermBook.removeBookByID(ID);
                    listUser.removeUserByID(ID);

                    gotoXY(x + 5, y + 4); cout << "The account of user with ID number " << ID << " has been successfully deleted!\n";
                    break;            
                }
                case yy + 2:{
                    goto MENU;
                    break;                                 
                } 
            }
            isContinue = toContinue1(x + 13, y + 6);
            if(isContinue == 1){
                goto MENU;
            }
			
            break;      
        }
              
        case y + 6:{
            gotoXY(x + 20, y + 10); cout << "GOODBYE! SEE YOU AGAIN!";
            exit(1);            
        }
    }
}
