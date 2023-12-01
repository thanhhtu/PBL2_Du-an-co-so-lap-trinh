#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "mylib.h"

#ifndef MENU_H
#define MENU_H

void title();
int toContinue();
void enterPassword(string &temp_password);
void enterNumber(string &number);

void box(int x, int y, int w, int h, int t_color, int b_color, string text);
void thanhSang(int x, int y, int w, int h, int b_color, string text);
void keDuoi(int x, int y, int w, int h, int t_color, int b_color, string nd);
int menuMain(int x, int y, int w, int h);

#endif

