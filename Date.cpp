#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdexcept>
#include "Date.h"
using namespace std;

#ifndef DATE_CPP
#define DATE_CPP

int dayOfYears[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
					   {31,29,31,30,31,30,31,31,30,31,30,31}};

Date::Date(int dd, int mm, int yyyy){
    this->day = dd;
    this->month = mm;
    this->year = yyyy;
}

Date::Date(const string &dt){
    this->day = stoi(dt.substr(0, 2));
    this->month = stoi(dt.substr(2, 2));
    this->year = stoi(dt.substr(4, 4));
}

Date::Date(const Date &dt){
	this->day = dt.day;
	this->month = dt.month;
	this->year = dt.year;
}

Date::~Date(){

}

bool Date::isLeap() const{
	return (this->year % 400 == 0 || (this->year % 100 != 0 && this->year % 4 == 0));
}

bool Date::isValid(){
	return(this->year > 999 && 
           this->month > 0 && this->month < 13 &&
           this->day > 0 && this->day<=dayOfYears[this->isLeap()][this->month -1]);
}

string Date::dtAsString() const{        //ddmmyyyy
	string tmp = "";
	if(this->day < 10) tmp += "0";
	tmp += to_string(this->day);
	if(this->month < 10) tmp += "0";
	tmp += to_string(this->month);
    tmp += to_string(this->year);
	return tmp;
}

Date &Date::operator = (const Date &dt){
	this->day = dt.day;
	this->month = dt.month;
	this->year = dt.year;
	return *this;
} 


bool Date::operator < (const Date &dt) const{
	if(this->year != dt.year) return this->year < dt.year;
	if(this->month != dt.month) return this->month < dt.month;
	return this->day < dt.day;
}

bool Date::operator > (const Date &dt) const{
	if(this->year != dt.year) return this->year > dt.year;
	if(this->month != dt.month) return this->month > dt.month;
	return this->day > dt.day;
}

bool Date::operator == (const Date &dt) const{
	if(this->day == dt.day && this->month == dt.month && this->year == dt.year) return 1;
	return 0;
} 

Date &Date::operator ++ (){
	if(this->day < dayOfYears[this->isLeap()][this->month - 1]) this->day++;
    else{ 
		this->day = 1;
        if(this->month < 12) this->month++;
        else{
			this->month = 1; 
			this->year++;
		}
    }
    return *this;
}

int Date::dateCompare(const Date &dt) const{
    if(this->year != dt.year){
        return this->year < dt.year ? -1 : 1;  //-1 neu d1 < d2
    }else if(this->month != dt.month){
        return this->month < dt.month ? -1 : 1; //1 neu d1 > d2
    }else if (this->day != dt.day) {
        return this->day < dt.day ? -1 : 1; //0 neu d1 = d2
    }else {
        return 0;
    }
}

istream &operator >> (istream &in, Date &dt) {
    //doc du lieu tu dateData.txt (che do mac dinh)
    ifstream fi("dateData.txt", ios::in);

    //khoi tao gia tri mac dinh
    int lastD = 0, lastM = 0, lastY = 0; 

    //kiem tra file mo thanh cong
    if(fi){  
        while (fi >> lastD >> lastM >> lastY) {
            //reading the values until EOF
        }
        fi.close();
    }

    Date lastDate(lastD, lastM, lastY);

    do{
        SetColor(15);
        cout << "                                  The last logged date: ";
        cout << setfill('0') << setw(2) << right << lastDate.day << "/" << setw(2) << right << lastDate.month << "/" << setw(4) << right << lastDate.year << setfill(' ') << endl;
        box(30, 1, 40, 2, 15, 1, "      ENTER THE SYSTEM LOGIN DATE");

        keDuoi(30, 3, 40, 2, 15, 1, "Day: ");
        gotoXY(30, 3); cout << char(195);    //displays '├'
        gotoXY(70, 3); cout << char(180);    // displays '┤'
        gotoXY(36, 4); in >> dt.day;

        keDuoi(30, 5, 40, 2, 15, 1, "Month: ");
        gotoXY(30, 5); cout << char(195);   
        gotoXY(70, 5); cout << char(180);   
        gotoXY(38, 6); in >> dt.month;

        keDuoi(30, 7, 40, 2, 15, 1, "Year: ");
        gotoXY(37, 8); in >> dt.year;

        if(!dt.isValid() || dt.dateCompare(lastDate) < 0){
            gotoXY(27, 11);
            cout << "Error: Invalid date or date before the last entry date!\n";
            if(!dt.isValid() || dt.dateCompare(lastDate) < 0){
                gotoXY(27,12);
                SetColor(72);
                system("pause");
                system("cls");
            }
        } 
    }while(!dt.isValid() || dt.dateCompare(lastDate) < 0);
    
    //ghi du lieu vao tep (che do append)
    ofstream fo("dateData.txt", ios::app);
    if(fo){ 
        fo << dt.day << " " << dt.month << " " << dt.year << "\n";
        fo.close();
    }

    return in;
}

ostream &operator << (ostream &out, const Date &dt){
	out << setfill('0') << setw(2) << right << dt.day << "/" << setw(2) << right << dt.month << "/" << setw(4) << right << dt.year << setfill(' ');
	return out;
}

//thuat toan Zeller's Congruence
//ham san co: tinh hieu so ngay tu date 1/1/0 den date hien tai
int Date::calDay() const{
    Date temp = *this;
    if(temp.month < 3){
        temp.year--;
        temp.month += 12;
    }
    return 365 * temp.year + temp.year / 4 - temp.year / 100 + temp.year / 400 + (153 * temp.month - 457) / 5 + temp.day - 306;
}

//days1.days2 : days1 la ngay truoc, days2 la ngay sau
int Date::getDayDifference(const Date &dt) const {
    if (*this == dt) return 0;  //cung 1 date

    int days1 = this->calDay();
    int days2 = dt.calDay();

    return days2 - days1;
};

#endif