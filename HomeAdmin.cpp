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
    string text1 = "               List user account information";
    string text2 = "          Look up user information via account ID";
    string text3 = "            Delete a user account via account ID";
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
        LISTUSER:
			system("cls");
            cout << "LIST OF USER ACCOUNT INFORMATION\n";
            fflush(stdin);
            listUser.printInforUsers();

			isContinue = toContinue();
			if(isContinue == 1){
				goto LISTUSER;
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

            const int x = 45, y = 5, w = 60, h = 2;
            box(x, y - 3, w, h, 11, 1, 11, "********* LOOK UP USER INFORMATION VIA ACCOUNT ID *********");
            
            box(x, y, w, h, 15, 1, 15, "      Enter the account ID: ");
            string ID;
            gotoXY(x + 33, y + 1); getline(cin, ID);
            if(ID[0] != 'U' || ID[1] != 'S' || ID[2] != 'E' || ID[3] != 'R'){
                gotoXY(x + 20, y + 4); cout << "Error: Invalid ID code! Please enter again!";
                SetColor(72);
                gotoXY(x + 19, y + 5);
                system("pause");
                goto FINDUSER;
            }

            listUser.getUserInforByID(ID, x + 10, y + 3, w - 20, h);

            if(listUser.checkID(ID) == true){
                isContinue = toContinue1(x + 13, y + 17);
                if(isContinue == 1){
                    goto MENU;
                }
            }else{
                isContinue = toContinue1(x + 13, y + 5);
                if(isContinue == 1){
                    goto MENU;
                }
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
            if(ID[0] != 'U' || ID[1] != 'S' || ID[2] != 'E' || ID[3] != 'R'){
                gotoXY(x + 10, y + 4); cout << "Error: Invalid ID code! Please enter again!";
                SetColor(72);
                gotoXY(x + 10, y + 5);
                system("pause");
                goto DELETEUSER;
            }

            listUser.getUserInforByID(ID, x + 10, y + 3, w - 20, h);

            //truong hop co hoac khong co account
            if(listUser.checkID(ID) == true){
                box(x, y + 16, w, h + 7, 11, 1, 15, " Warning: If a user account is deleted, all bank books \n\t\t\t\t\t\t\t of this user account will be deleted.");
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

            }else{
                isContinue = toContinue1(x + 13, y + 5);
                if(isContinue == 1){
                    goto MENU;
                }
            }   
            break;      
        }
              
        case y + 6:{
            SetColor(0);
            textcolor(15);            
            gotoXY(x + 20, y + 10); cout << "GOODBYE AND SEE YOU AGAIN!!";
            exit(1);            
            break;
        }
    }
}
