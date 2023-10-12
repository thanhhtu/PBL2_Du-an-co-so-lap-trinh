#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Book.h"

#ifndef BOOK_CPP
#define BOOK_CPP

Book::Book(){

}

Book::~Book(){

}

//get, set attributes
const string &Book::getIDBook(){
    return this->IDBook;
}

void Book::setIDBook(const string &IDBook){
    this->IDBook = IDBook;
}

const string &Book::getID(){
    return this->ID;
}

void Book::setID(const string &ID){
    this->ID = ID;
}

const string &getDate(){
    return this->date;
}

void setDate(const string &date){
    this->date = date;
}

const string &Book::getMoney(){
    return this->money;
}

void Book::setMoney(const string &money){
    this->money = money;
}

//other method
void Book::setBook(ifstream &f){
    getline(f, this->IDBook, '-');
    getline(f, this->ID, '-');
    getline(f, this->date, '-');
    getline(f, this->money);
}

void Book::saveBook(ofstream &f){
    
}

#endif
