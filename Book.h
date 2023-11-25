#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
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
};

#endif

