#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "NonTermBook.h"

#ifndef NONTERMBOOK_CPP
#define NONTERMBOOK_CPP

NonTermBook::NonTermBook(){

}

NonTermBook::~NonTermBook(){

}


//other method
void NonTermBook::setBook(ifstream &f){
    getline(f, this->IDBook, '-');
    getline(f, this->ID, '-');

    string dt;
    getline(f, dt, '-');

    Date tDate(dt);   //class date tu string dt
    this->setOpeningDate(tDate);   //copy class tDate sang class this->date

    getline(f, this->money);
}

void NonTermBook::saveBook(ofstream &f){
    string dt = this->openingDate.dtAsString();    //chuyen class this->date sang string r luu vao string dt

    f << this->IDBook << "-" << this->ID << "-" << dt << "-" << this->money;
}

void NonTermBook::printNonTermBook() const{
    cout << "ID Book: " << this->IDBook << endl;
    cout << "The opening date: " << this->openingDate << endl;
    cout << "The money you add: " << this->money << endl;
}

float NonTermBook::interestRate(const Date &currentDate, const Account &user) const{
    float interestEarned = stof(this->money) * openingDate.getDayDifference(currentDate) * this->interest;
    return interestEarned;
}

#endif