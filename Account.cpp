#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Account.h"

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

const string &Account::getID(){
	return this->ID;
}
void Account::setID(const string &ID){
	this->ID = ID;
}

const string &Account::getUsername(){
	return this->username;
}
void Account::setUsername(const string &username){
	this->username = username;
}

const string &Account::getPassword(){
	return this->password;
}
void Account::setPassword(const string &password){
	this->password = password;
}

const string &Account::getName(){
	return this->name;
}
void Account::setName(const string &name){
	this->name = name;
}

const string &Account::getIDCard(){
	return this->IDCard;
}
void Account::setIDCard(const string &IDCard){
	this->IDCard = IDCard;
}

const string &Account::getAddress(){
	return this->address;
}
void Account::setAddress(const string &address){
	this->address = address;
}

const string &Account::getTel(){
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

void Account::printInfor(){
	cout << "Account ID: " << this->ID << endl;
	cout << "Name: " << this->name << endl;
	cout << "Identity card number: " << this->IDCard << endl;
	cout << "Address: " << this->address << endl;
	cout << "Phone number: " << this->tel << endl;
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
