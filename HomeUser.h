#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "ListUserAccount.cpp"
#include "Date.cpp"
#include "ListTermBook.cpp"
#include "ListNonTermBook.cpp"

#ifndef HOMEUSER_H
#define HOMEUSER_H

void homeUser(const Date &currentDate);
void log(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate);
void menuUser(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate);

#endif