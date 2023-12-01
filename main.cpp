#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeUser.cpp"
#include "HomeAdmin.cpp"
#include "Date.cpp"

int main(){
    title();
    system("cls");
    
    Date currentDate;
	cin >> currentDate;

    ShowCur(0);
    while (true)
    {
        system("cls");
        box(30, 2, 30, 2, 15, 1, "           YOU ARE");
        box(30, 5, 30, 2, 11, 1, "             ADMIN");
        gotoXY(30, 5); cout << char(218);
        gotoXY(60, 5); cout << char(191);

        box(30, 7, 30, 2, 11, 1, "            USER");
        gotoXY(30, 7); cout << char(195);
        gotoXY(60, 7); cout << char(180);
        
        int check = menuMain(30, 5, 30, 2);  //menuMain trong file Menu
        char c;   
        bool exitLoop = false;

        switch(check){
            case 5:
                textcolor(1);
                homeAdmin(currentDate);
                break;
            case 7: 
                textcolor(1);
                homeUser(currentDate);
                break;
        }
    }

    return 0;
}