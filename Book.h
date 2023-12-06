#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cctype>
#include<map>
using namespace std;
#include "Date.cpp"

#ifndef BOOK_H
#define BOOK_H

class Book{
	protected:
		string IDBook; 
        string ID;  //ID account
        Date openingDate;
		string money;
	
	public:
		Book();
		~Book();
		
		//get, set attributes
		string getIDBook() const;
		void setIDBook(const string &IDBook);
		
		string getID() const;
		void setID(const string &ID);

		Date getOpeningDate() const;
		void setOpeningDate(const Date &openingDate);

		string getMoney() const;
		void setMoney(const string &money);

		virtual void setBook(ifstream &f) = 0;	//lay 1 book tu file
		virtual void saveBook(ofstream &f) = 0;	//ghi 1 book vao lai file

        virtual void printBook() const = 0;
        
        virtual float interestRate(const Date &currentDate, const Account &user) const = 0;
};

#endif