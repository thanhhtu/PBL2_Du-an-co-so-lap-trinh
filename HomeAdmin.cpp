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

    const int x = 45, y = 5, w = 60, h = 2;
    string text1 = "             List all user information accounts";
    string text2 = "          Look up user information via account ID";
    string text3 = "            Delete a user account via account ID";
    string text4 = "                  List savings books by year";
    string text5 = "                           Exit";

    box(x, y - 3, w, h, 11, 1, 11, "************************ ADMIN MENU ***********************");
    box(x, y, w, h, 11, 1, 11, text1);
    box(x, y + 2, w, h, 11, 1, 15, text2); 
    box(x, y + 4, w, h, 11, 1, 15, text3);
    box(x, y + 6, w, h, 11, 1, 15, text4);
    box(x, y + 8, w, h, 11, 1, 15, text5);

    for(int i = 1; i < 5; i++){
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
            xcu = xp;
            ycu = yp;
            if(ycu == y) thanhSang(xp, yp, w, h, 150, 15, text1); 
            if(ycu == y + 2) thanhSang(xp, yp, w, h, 150, 15, text2);
            if(ycu == y + 4) thanhSang(xp, yp, w, h, 150, 15, text3);
            if(ycu == y + 6) thanhSang(xp, yp, w, h, 150, 15, text4);
            if(ycu == y + 8) thanhSang(xp, yp, w, h, 150, 15, text5);
            kt = false;            
        }
        check = move(x, y, h, yp, kt, 5);
        if(check == y || check == y + 2 || check == y + 4 || check == y + 6 || check == y + 8){
            break;
        }
    }

    SetColor(0);
    textcolor(15);
    switch(check){
        case y:{
        LISTACCOUNT:
			system("cls");
            const int x1 = 30, y1 = 5, w1 = 100, h1 = 2;
            box(x1, y1 - 3, w1, h1, 11, 1, 11, "****************************** LIST ALL USER INFORMATION ACCOUNTS *****************************");
            
            string text0 = "  Account ID";
            string text1 = "  Name";
            string text2 = "  ID number";
            string text3 = "  Phone number";
            string text4 = "  Address";
            
            box(x1, y1, 20, h1, 15, 1, 15, text0);
            box(x1 + 20, y1, 20, h1, 15, 1, 15, text1);
            box(x1 + 40, y1, 20, h1, 15, 1, 15, text2); 
            box(x1 + 60, y1, 20, h1, 15, 1, 15, text3);
            box(x1 + 80, y1, 20, h1, 15, 1, 15, text4);
            
            for(int J = 1; J < 5; J++){
                gotoXY(x1 + (J * 20), y1);
                cout << char(194);
            }

            fflush(stdin);
            listUser.printInforUsers();
		
			isContinue = toContinue1(whereX() + 33, whereY() + 1);
            if (isContinue == 1){
                goto MENU;
            }
			break;
        }

        case y + 2:{
        FINDUSER:
			system("cls");
            fflush(stdin);

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 11, 1, 11, "********* LOOK UP USER INFORMATION VIA ACCOUNT ID *********");
            box(x, y, w, h, 15, 1, 15, "      Enter the account ID: ");
            string ID;
            gotoXY(x + 33, y + 1); getline(cin, ID);

            if(!listUser.checkID(ID)){
                box(x, y + 4, w, h + 6, 11, 1, 15, "              Error: This ID user is invalid!");
                gotoXY(x + 7, y + 6); cout << "         Do you want to enter again?";
                
                const int xx = 70, yy = 12, ww = 10, hh = 2; 
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

                SetColor(0);
                textcolor(15);
                switch(check){
                    case yy:{
                        goto FINDUSER;
                        break;            
                    }
                    case yy + 2:{
                        goto MENU;
                        break;                                 
                    } 
                }
            }

            listUser.getUserInforByID(ID, x + 10, y + 3, w - 20, h);

            isContinue = toContinue1(x + 13, y + 17);
            if(isContinue == 1){
                    goto MENU;
            }
            break;      
        }

        case y + 4:{
        DELETEUSER:
			system("cls");
            fflush(stdin);
            
            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 11, 1, 11, "************ DELETE USER ACCOUNT VIA ACCOUNT ID **********");
            box(x, y, w, h, 15, 1, 15, "      Enter the account ID: ");
            string ID;
            gotoXY(x + 33, y + 1); getline(cin, ID);

            if(!listUser.checkID(ID)){
                box(x, y + 4, w, h + 6, 11, 1, 15, "              Error: This ID user is invalid!");
                gotoXY(x + 7, y + 6); cout << "         Do you want to enter again?";
                
                const int xx = 70, yy = 12, ww = 10, hh = 2; 
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

                SetColor(0);
                textcolor(15);
                switch(check){
                    case yy:{
                        goto DELETEUSER;
                        break;            
                    }
                    case yy + 2:{
                        goto MENU;
                        break;                                 
                    } 
                }
            }

            listUser.getUserInforByID(ID, x + 10, y + 3, w - 20, h);

            box(x, y + 16, w, h + 7, 11, 1, 15, "   Warning: If a user account is deleted, all bank books \n\t\t\t\t\t\t\t  of this user account will be deleted.");
            gotoXY(x + 7, y + 19); cout << " Do you want to continue deleting this account?";

            const int xx = 70, yy = 25, ww = 10, hh = 2; 
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

            SetColor(0);
            textcolor(15);
            switch(check){
                case yy:{
                    listTermBook.removeBookByID(ID);
                    listNonTermBook.removeBookByID(ID);
                    listUser.removeUserByID(ID);

                    gotoXY(x - 2, yy + 6); cout << "The account of user with ID number " << ID << " has been successfully deleted!\n";

                    isContinue = toContinue1(x + 13, yy + 8);
                    if(isContinue == 1){
                        goto MENU;
                    }
                    break;            
                }
                case yy + 2:{
                    goto MENU;
                    break;                                 
                } 
            }
            break;        
        }
        
		case y + 6:{
		LISTBYYEAR: 
			system("cls");
			fflush(stdin);

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 11, 1, 11, "*************** LIST SAVINGS BOOKS BY YEAR ****************");
            box(x, y, w, h, 15, 1, 15, "     Enter the year you want to list: ");
            string year;
            gotoXY(x + 42, y + 1); getline(cin, year);
			
            if(!isNumeric(year) || year.size() < 4 || isEmptyNoWhitespace(year)){
                box(x, y + 4, w, h + 6, 11, 1, 15, "               Error: This year is invalid!");
                gotoXY(x + 7, y + 6); cout << "         Do you want to enter again?";
                
                const int xx = 70, yy = 12, ww = 10, hh = 2; 
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

                SetColor(0);
                textcolor(15);
                switch(check){
                    case yy:{
                        goto LISTBYYEAR;
                        break;            
                    }
                    case yy + 2:{
                        goto MENU;
                        break;                                 
                    } 
                }
            }else{
				gotoXY(x, getCurrentCursorPositionY());
            	listTermBook.listBookByYear(year);
                cout << "\n\n";
                listNonTermBook.listBookByYear(year);
            	gotoXY(x, getCurrentCursorPositionY() + 1);
                
                isContinue = toContinue1(whereX() + 20, whereY() + 2);
                if(isContinue == 1){
                    goto MENU;
            	}            
				break;
            }
        }      
        case y + 8:{
            system("cls");
            end();           
            break;
        }
    }
}