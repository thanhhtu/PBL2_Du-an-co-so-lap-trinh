#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
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
		const string &getIDBook();
		void setIDBook(const string &IDBook);
		
		const string &getID();
		void setID(const string &ID);

		Date getOpeningDate();
		void setOpeningDate(const Date &openingDate);

		const string &getMoney();
		void setMoney(const string &money);

		//other method
		void setBook(ifstream &f);	//lay 1 book tu file
		void saveBook(ofstream &f);	//ghi 1 book vao lai file

};
#endif

