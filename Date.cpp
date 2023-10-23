#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Date.h"

#ifndef DATE_CPP
#define DATE_CPP

Date::Date(){

}

Date::Date(int d, int m, int y){
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::Date(const string &dt){
    this->day = stoi(dt.substr(0, 2));
    this->month = stoi(dt.substr(2, 2));
    this->year = stoi(dt.substr(4, 4));
}

Date::Date(const Date &date){
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date::~Date(){

}

string Date::toString(){
    string dt;
    dt += to_string(this->day);
    dt += to_string(this->month);
    dt += to_string(this->year);
    return dt;
}

void Date::printDate(){
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

//tinh ngay cua term book 
int Date::timeTerm(const Date &date){
    return 5;
}

#endif