#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "TermBook.h"

#ifndef TERMBOOK_CPP
#define TERMBOOK_CPP

TermBook::TermBook(){

}

TermBook::~TermBook(){

}

const int &TermBook::getTerm(){
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
    string dt = this->openingDate.toString();    //chuyen class this->date sang string r luu vao string dt

    f << this->IDBook << "-" << this->ID << "-" << dt << "-" << this->term << "-" << this->money;
}

void TermBook::printTermBook(){
    cout << "ID Book: " << this->IDBook << endl;
    cout << "The opening date: ";
    this->openingDate.printDate();
    cout << "The money you add: " << this->money << endl;
}
///////////////
float TermBook::interestRate(const Date &currentDate, const Account &user, int time){
    float tempMoney = stof(this->money);
    int tempTerm = this->term;
    
    float interest;

    if(tempTerm > time){
        interest = 0;
    }else if(tempTerm == 3){
        interest = tempMoney * 0.2 * 3;
    }else if(tempTerm == 6){
        interest = tempMoney * 0.2 * 6;
    }

    return interest;
}
// float TermBook::interestRate(Date currentDate, Account user){
//     float interest = 0;

//     int time = this->openingDate.timeTerm(currentDate);

//     if(this->term <= time){
//         cout << "The term of this book has not yet come. Are you sure you want to withdraw money?\n";
//         float choice;
//         do{
//             cout << "1. Yes. \n";
//             cout << "2. No. \n"; 

//             cout << "Your choice: ";
//             cin >> choice;

//             if(!(choice == int(choice) && choice >= 1 && choice <= 2)){
//                 cout << "Invalid input!! Please choose again.\n" << endl;
//             }   
//         }while(!(choice == int(choice) && choice >= 1 && choice <= 2));

//         if(choice == 1){
//             cout << "Interest rate of your bank book is: " << interest << endl;
//             return 0;
//         }else{
//             return 0;
//         }

//     }
// }

#endif