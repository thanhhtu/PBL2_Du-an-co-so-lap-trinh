#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int day, month, year;
    public:
        Date();
        Date(int d, int m, int y);
        Date(const string &dt); //ham dung sao chep tu string sang class Date
        Date(const Date &date); //ham dung sao chep tu string
        ~Date();

        string toString();    //chuyent tu class Date sang string
        void printDate();

        int timeTerm(const Date &date);
};
#endif