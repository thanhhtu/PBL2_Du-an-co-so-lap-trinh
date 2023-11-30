#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cctype>
#include<map>
using namespace std;
#include "TermBook.h"

#ifndef TERMBOOK_CPP
#define TERMBOOK_CPP

TermBook::TermBook(){
    interestRates[3] = 0.00825;     //3.3%/nam
    interestRates[6] = 0.0215;      //4.3%/nam
    interestRates[12] = 0.055;      //5.5%/nam
    interestRates[18] = 0.09;        //6.0%/nam
}

TermBook::~TermBook(){

}

int TermBook::getTerm() const{
    return this->term;
}

void TermBook::setTerm(int term){
    this->term = term;
}

void TermBook::setBook(ifstream &f){
    getline(f, this->IDBook, '-');
    getline(f, this->ID, '-');

    string dt;
    getline(f, dt, '-');
    Date tempDate(dt);   //class date tu string dt
    this->setOpeningDate(tempDate);   //copy class tempDate sang class this->date

    string tempTerm;
    getline(f, tempTerm, '-');
    this->term = stoi(tempTerm);

    getline(f, this->money);
}

void TermBook::saveBook(ofstream &f){
    string dt = this->openingDate.dtAsString();    //chuyen class this->date sang string r luu vao string dt

    f << this->IDBook << "-" << this->ID << "-" << dt << "-" << this->term << "-" << this->money;
}

void TermBook::printBook() const{
    cout << "ID Book: " << this->IDBook << endl;
    cout << "The opening date: " << this->openingDate << endl;
    cout << "The term: " << this->getTerm() << endl;
    cout << "The money you add: " << this->money << endl;
}

float TermBook::interestRate(const Date &currentDate, const Account &user) const{
    //Check if the term of the book has come
    if(openingDate.getDayDifference(currentDate) < this->term * 30){      //mac dinh 1 thang co 30 ngay
        //If not, ask the user if they want to withdraw money
        cout << "The term of this book has not yet come. Are you sure you want to withdraw money?\n";
        int choice;
        do{
            cout << "1. Yes. \n";
            cout << "2. No. \n";
            cout << "Your choice: ";
            cin >> choice;
            if(!(choice >= 1 && choice <= 2)){
                cout << "Invalid input!! Please choose again.\n" << endl;
            }
        }while(!(choice >= 1 && choice <= 2));

        //If the user chooses to withdraw money early, return 0
        if(choice == 1){
            cin.ignore();
            return 0;
        }else{
            //If the user chooses not to withdraw money, don't calculate interest
            cin.ignore();
            return 0;
        }
    }

    //Calculate the interest rate
    auto it = interestRates.find(this->term);
    float interest = it->second;
    
    //Calculate the interest earned
    float interestEarned = stof(this->money) * interest;
    return interestEarned;
}

#endif