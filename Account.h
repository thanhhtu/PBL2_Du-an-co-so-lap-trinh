#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<map>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
	private:
		//thong tin dang nhap
		string ID;		//ID phan biet trong he thong
		string username;
		string password;		
		
		//thong tin ca nhan
		string name;
		string IDCard;	//CMND
		string address;
		string tel;
	
	public:
		Account();
		Account(const string &ID, const string &username, const string &password, const string &name, const string &IDCard, const string &address, const string &tel);
		~Account();

		//get, set attributes
		string getID() const;
		void setID(const string &ID);
		
		string getUsername() const;
		void setUsername(const string &username);
		
		string getPassword() const;
		void setPassword(const string &password);		
		
		string getName() const;
		void setName(const string &name);
		
		string getIDCard() const;
		void setIDCard(const string &IDCard);
		
		string getAddress() const;
		void setAddress(const string &address);
		
		string getTel() const;
		void setTel(const string &tel);
		
		//other methods
		void setAccount(ifstream &f);	//lay 1 account tu file
		void saveAccount(ofstream &f);	//ghi 1 account vao lai file

		void printInfor() const;		//in ra thong tin ca nhan cua 1 account

		Account &operator = (const Account &acc);
};

#endif