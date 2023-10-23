#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Book.cpp"
#include "Date.cpp"

#ifndef TERMBOOK_H
#define TERMBOOK_H

class TermBook : public Book{
    private:
        int term;
    public:
        TermBook();
        ~TermBook();
        
        const int &getTerm();
		void setTerm(int term);

        void setBook(ifstream &f);	//lay 1 book tu file    //overriding
		void saveBook(ofstream &f);	//ghi 1 book vao lai file   //overriding

        void printTermBook();
        /////////////
        float interestRate(const Date &currentDate, const Account &user, int time);
};

#endif