#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "List.cpp"
#include "Account.cpp"

#ifndef LISTADMINACCOUNT_H
#define LISTADMINACCOUNT_H

class ListAdminAccount : public List<Account>{
    public:
        ListAdminAccount();
        ~ListAdminAccount();
        void setAdmins();  //doc list admins tu file ra
        void saveAdmins();   //ghi list admins lai vao file
    
        void printInforAdmin();  //in ra thong tin users

        bool checkSignIn(Account &admin, const string &username, const string &password);        
        void signIn(Account &admin);
        
};

#endif

