#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "Account.cpp"
#include "Menu.cpp"
#include "Account.cpp"
#include "ListAdminAccount.cpp"
#include "ListUserAccount.cpp"
#include "Date.h"

#ifndef HOMEADMIN_H
#define HOMEADMIN_H

void homeAdmin(const Date &currentDate);
void menuAdmin(ListUserAccount &listUser, Account &user, const Date &currentDate);

#endif

