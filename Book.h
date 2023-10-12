#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{
	private:
		string IDBook; 
        string ID;  //ID account
        Date date;
		string money;
	
	public:
		Book();
		~Book();
		
		//get, set attributes
		const string &getIDBook();
		void setIDBook(const string &IDBook);
		
		const string &getID();
		void setID(const string &ID);

		Date getDate();
		void setDate(const Date &date);

		const string &getMoney();
		void setMoney(const string &money);

		//other method
		void setBook(ifstream &f);	//lay 1 book tu file
		void saveBook(ofstream &f);	//ghi 1 book vao lai file

};
#endif

