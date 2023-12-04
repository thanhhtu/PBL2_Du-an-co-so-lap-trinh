#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdexcept>
#include "Menu.cpp"
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int year, month, day;
    public:
        Date(int dd = 01, int mm = 01, int yyyy = 2000);
		Date(const string &dt);
		Date(const Date &dt);
        ~Date();

		bool isLeap() const;   //kiem tra nam nhuan
		bool isValid();
		string dtAsString() const;  //class date to string

		Date &operator = (const Date &dt); //gan cac gia tri date duoc truyen vao date hien tai
		bool operator < (const Date &dt) const; //so sanh doi tuong date hien tai va date duoc truyen vao
		bool operator > (const Date &dt) const;
		bool operator == (const Date &dt) const;
		Date &operator ++ ();

		int dateCompare(const Date &dt1) const;

		friend istream &operator >> (istream &in, Date &dt);
		friend ostream &operator << (ostream &out, const Date &dt);

		int calDay() const;
		int getDayDifference(const Date &dt2) const;	//dem so ngay khac
};

#endif