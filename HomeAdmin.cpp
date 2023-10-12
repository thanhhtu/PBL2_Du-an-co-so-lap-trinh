#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "HomeAdmin.h"

void HomeAdmin(){
    Account admin;
    ListAdminAccount listAdmin;

    listAdmin.setAdmins();

    //dang ky, dang nhap
    system("cls");
    cout << "SIGN IN\n";
    listAdmin.signIn(admin);


}