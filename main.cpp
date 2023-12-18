#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<limits>
using namespace std;
#include "HomeUser.cpp"
#include "HomeAdmin.cpp" 
#include "Date.cpp"

int main(){
    ShowCur(0);
    title();
    system("cls");
    start(); 
    system("cls");
    Date currentDate;
	cin >> currentDate;
    system("cls");

    const int x = 60, y = 5, w = 30, h = 2;
    string text1 = "            ADMIN";
    string text2 = "            USER";

    box(x, y - 3, w, h, 12, 14, 12, "********** YOU ARE **********");
    box(x, y, w, h, 15, 1, 15, text1);
    box(x, y + 2, w, h, 15, 1, 15, text2);

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
            if(ycu == y) thanhSang(xp, yp, w, h, 78, 15, text1); //reset thanh sang cu
            if(ycu == y + 2) thanhSang(xp, yp, w, h, 78, 15, text2);
            kt = false;            
        }
        check = move(x, y, h, yp, kt, 2);
        if(check == y || check == y + 2){
            break;
        }
    }

    switch(check){
        case y:{
            textcolor(1);
            cin.ignore();
            homeAdmin(currentDate);
            break;            
        }
        case y + 2:{
            system("cls");
            textcolor(1);
            cin.ignore();
            homeUser(currentDate);
            break;            
        } 
    }

    system("cls");
    end();
    return 0;
}