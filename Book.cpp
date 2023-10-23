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

Date Book::getOpeningDate(){
    return this->openingDate;
}

void Book::setOpeningDate(const Date &openingDate){
    this->openingDate = openingDate;
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

    string dt;
    getline(f, dt, '-');
    Date tDate(dt);   //class date tu string dt
    this->setOpeningDate(tDate);   //copy class tDate sang class this->date

    getline(f, this->money);
}

void Book::saveBook(ofstream &f){
    string dt = this->openingDate.toString();    //chuyen class this->date sang string r luu vao string dt

    f << this->IDBook << "-" << this->ID << "-" << dt << "-" << this->money;
}

#endif
