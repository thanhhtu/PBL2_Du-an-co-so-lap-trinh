#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "NonTermBook.cpp"
#include "ListUserAccount.cpp"
#include "Menu.cpp"
#include "Date.cpp"


#ifndef LISTNONTERMBOOK_H
#define LISTNONTERMBOOK_H

class ListNonTermBook : public List<NonTermBook>{
    public:
        int numOfNonTermBook;  //so luong user account da dang ki (ke ca da xoa) => dua vao de luu account ID
    public:
        ListNonTermBook();
        ~ListNonTermBook();
        
        void setNonTermBooks();  //doc list term books tu file ra
        void saveNonTermBooks();   //ghi list term books lai vao file
        void printNonTermBooks();  //list term books

        void printUserNonTermBook(const Account &user, int &ck);   //non term books cua 1 nguoi

        bool checkIDBook(const string &IDBook);
        void openNonTermBook(NonTermBook &nonTermBook, const Account &user, const Date &currentDate, int x, int y, int w, int h);

        NonTermBook* findBookByID(const string &IDBook) const;

        void removeBookByIDBook(const string &IDBook);
        void removeBookByID(const string &ID);
};

#endif