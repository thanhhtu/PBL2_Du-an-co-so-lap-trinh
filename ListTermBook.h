#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "TermBook.cpp"
#include "Account.cpp"
#include "ListUserAccount.cpp"
#include "Date.cpp"


#ifndef LISTTERMBOOK_H
#define LISTTERMBOOK_H

class ListTermBook : public List<TermBook>{
    public:
        int numOfTermBook;  //so luong user account da dang ki (ke ca da xoa) => dua vao de luu account ID
    public:
        ListTermBook();
        ~ListTermBook();
        
        void setTermBooks();  //doc list term books tu file ra
        void saveTermBooks();   //ghi list term books lai vao file
        void printTermBooks();  //list term books

        void printUserTermBook(Account user);   //term books cua 1 nguoi

        bool checkIDBook(const string &IDBook);
        void openTermBook(TermBook &termBook, Account user, const Date &currentDate);

};

#endif