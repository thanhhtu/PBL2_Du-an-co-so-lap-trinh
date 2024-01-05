#include "Book.h"

#ifndef BOOK_CPP
#define BOOK_CPP

Book::Book(){

}

Book::~Book(){

}

//get, set attributes
string Book::getIDBook() const{
    return this->IDBook;
}

void Book::setIDBook(const string &IDBook){
    this->IDBook = IDBook;
}

string Book::getID() const{
    return this->ID;
}

void Book::setID(const string &ID){
    this->ID = ID;
}

Date Book::getOpeningDate() const{
    return this->openingDate;
}

void Book::setOpeningDate(const Date &openingDate){
    this->openingDate = openingDate;
}

string Book::getMoney() const{
    return this->money;
}

void Book::setMoney(const string &money){
    this->money = money;
}

string Book::getOpeningYear() const {
    string dateString = openingDate.dtAsString();
    return dateString.substr(dateString.size() - 4); //Extract the last 4 characters (YYYY)
}

#endif