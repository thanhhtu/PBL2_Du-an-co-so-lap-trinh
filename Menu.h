#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "mylib.h"

#ifndef MENU_H
#define MENU_H

void title();
int getCurrentCursorPositionY();    // lay vi tri dong hien tai cua con tro man hinh trong console
int toContinue1(int x, int y);
void enterPassword(string &temp_password);
void enterNumber(string &number);

void box(int x, int y, int w, int h, int t_color, int b_color, int nd_color, string nd);
void box1(int x, int y, int w, int h, int t_color, int b_color);    //ve box khong co nd
void thanhSang(int x, int y, int w, int h, int b_color, int nd_color, string nd);
int move(int x, int y, int h, int &yp, int &kt, int soKhung);
bool isEmptyNoWhitespace(const string& str);   //kiem tra chuoi nhap vao co rong hoac chua ky tu trang khong
void end();
void start();

#endif