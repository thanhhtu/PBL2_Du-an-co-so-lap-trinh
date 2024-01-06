#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<map>
using namespace std;
#include "Book.cpp"
#include "Date.cpp"
#include "Account.cpp"

#ifndef TERMBOOK_H
#define TERMBOOK_H

class TermBook : public Book{
    private:
        int term;
        map<int, long double> interestRates;  //luu han muc
    public:
        TermBook();
        ~TermBook();
        
        int getTerm() const;
		void setTerm(long double term);

        void setBook(ifstream &f);
		void saveBook(ofstream &f);

        void printBook() const;
        
        long double interestRate(const Date &currentDate) const;
        long double interest(const Date &currentDate) const;
};

#endif