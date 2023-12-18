#include "Account.h"
#include "Menu.cpp"
#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

Account::Account(){

}

Account::Account(const string &ID, const string &username, const string &password, const string &name, const string &IDCard, const string &address, const string &tel){
	this->ID = ID;
	this->username = username;
	this->password = password;

	this->name = name;
	this->IDCard = IDCard;
	this->address = address;
	this->tel = tel;
}

Account::~Account(){

}

string Account::getID() const{
	return this->ID;
}
void Account::setID(const string &ID){
	this->ID = ID;
}

string Account::getUsername() const{
	return this->username;
}
void Account::setUsername(const string &username){
	this->username = username;
}

string Account::getPassword() const{
	return this->password;
}
void Account::setPassword(const string &password){
	this->password = password;
}

string Account::getName() const{
	return this->name;
}
void Account::setName(const string &name){
	this->name = name;
}

string Account::getIDCard() const{
	return this->IDCard;
}
void Account::setIDCard(const string &IDCard){
	this->IDCard = IDCard;
}

string Account::getAddress() const{
	return this->address;
}
void Account::setAddress(const string &address){
	this->address = address;
}

string Account::getTel() const{
	return this->tel;
}
void Account::setTel(const string &tel){
	this->tel = tel;
}

void Account::setAccount(ifstream &f){
	getline(f, this->ID, '-');
	getline(f, this->username, '-');
	getline(f, this->password, '-');
	getline(f, this->name, '-');
	getline(f, this->IDCard, '-');
	getline(f, this->address, '-');
	getline(f, this->tel);
}
void Account::saveAccount(ofstream &f){
	f << this->ID << "-" << this->username << "-" << this->password << "-" << this->name << "-" << this->IDCard << "-" << this->address << "-" << this->tel;
}

void Account::printInfor() const{
	int x1 = whereX();
	int y1 = whereY();

	cout << "   " << this->ID;

	gotoXY(x1 + 20, y1);
	cout << this->name;

	gotoXY(x1 + 40, y1);
	cout << this->IDCard;

	gotoXY(x1 + 60, y1);
	cout << this->tel;
	
	gotoXY(x1 + 80, y1);
	cout << this->address << endl;
}

Account &Account::operator = (const Account &acc){
	this->ID = acc.ID;
	this->username = acc.username;
	this->password = acc.password;
	this->name = acc.name;
	this->IDCard = acc.IDCard;
	this->address = acc.address;
	this->tel = acc.tel;
	
	return *this;
}

#endif