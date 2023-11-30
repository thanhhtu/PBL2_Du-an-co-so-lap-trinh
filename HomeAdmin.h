#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Menu.cpp"
#include "ListAdminAccount.cpp"
#include "ListUserAccount.cpp"
#include "Date.h"

#ifndef HOMEADMIN_H
#define HOMEADMIN_H

void homeAdmin(const Date &currentDate);
void menuAdmin(Account &user, ListUserAccount &listUser, TermBook &termBook, ListTermBook &listTermBook, NonTermBook &nonTermBook, ListNonTermBook &listNonTermBook, const Date &currentDate);

#endif

