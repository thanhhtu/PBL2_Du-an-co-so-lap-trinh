#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cctype>
#include<map>
using namespace std;
#include "Book.cpp"
#include "Date.cpp"
#include "Account.cpp"

#ifndef NONTERMBOOK_H
#define NONTERMBOOK_H

class NonTermBook : public Book{
    private:
        float interest = (0.15/100) / 365;    //0.15%/ nam
    public:
        NonTermBook();
        ~NonTermBook();
        
		//other method
		void setBook(ifstream &f);	//lay 1 book tu file
		void saveBook(ofstream &f);	//ghi 1 book vao lai file

        void printBook() const;
        
        float interestRate(const Date &currentDate, const Account &user) const;
};

#endif