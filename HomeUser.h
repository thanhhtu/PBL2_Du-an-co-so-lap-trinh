#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "Account.cpp"
#include "ListUserAccount.cpp"
#include "Account.h"
#include "Date.cpp"
#include "TermBook.cpp"
#include "ListTermBook.cpp"

#ifndef HOMEUSER_H
#define HOMEUSER_H

void homeUser(const Date &currentDate);
void log(Account &user, ListUserAccount &listUser);
void menuUser(Account &user, ListUserAccount &listUser, TermBook &TermBook, ListTermBook &listTermBook, const Date &currentDate);

#endif

