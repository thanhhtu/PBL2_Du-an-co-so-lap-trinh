#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "List.cpp"
#include "Account.cpp"

#ifndef LISTUSERACCOUNT_H
#define LISTUSERACCOUNT_H

class ListUserAccount : public List<Account>{
    public:
        int numOfUser;  //so luong user account da dang ki (ke ca da xoa) => dua vao de luu account ID
    public:
        ListUserAccount();
        ~ListUserAccount();
        
        void setUsers();  //doc list users tu file ra
        void saveUsers();   //ghi list users lai vao file
    
        void printInforUsers();  //in ra thong tin users
        
        //true: trung; false: khong trung
        bool checkID(const string &ID);   
        bool checkUsername(const string &username); 
        bool checkPassword(const string &password);
        bool checkIDCard(const string &IDCard); 
        void signUp(Account &user);

        bool checkSignIn(Account &user, const string &username, const string &password);    //coi co tring username va password khong
        void signIn(Account &user);

        // void editUser();   
        // void editUsers();   //menu quan ly tk user (them, xoa, tim kiem)
        // void addUser();  //them 1 tk user
        // void deleteUser();   //xoa tk user
        // void getUserByID(); //lay user account theo ID 
};

#endif

