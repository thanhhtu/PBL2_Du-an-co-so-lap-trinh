#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "TermBook.cpp"
#include "ListUserAccount.cpp"
#include "Menu.cpp"
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

        void printUserTermBook(const Account &user, int &ck);   //term books cua 1 nguoi

        bool checkIDBook(const string &IDBook);
        void openTermBook(TermBook &termBook, const Account &user, const Date &currentDate, int x, int y, int w, int h);

        TermBook* findBookByID(const string &IDBook) const;
        TermBook* findUserBookByID(const string &ID, const string &IDBook) const;   //tim book cua 1 nguoi

        void removeBookByIDBook(const string &IDBook);
        void removeBookByID(const string &ID);
        
        void listBookByYear(const string &year);    //liet ke cac so theo nam da nhap
};

#endif
