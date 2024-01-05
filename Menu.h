#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<vector>
using namespace std;
#include "mylib.h"

#ifndef MENU_H
#define MENU_H

void title();
int toContinue1(int x, int y);  //cho chon ket thuc chuong trinh hay quay lai menu
void enterPassword(string &temp_password);  //nhap password (thay so bang *)
bool isNumeric(const string &str);  //kiem tra chuoi co phai chuoi so hay khong
bool isEmptyNoWhitespace(const string& str);   //kiem tra chuoi nhap vao co rong hoac chua ky tu trang khong

int getCurrentCursorPositionY();    //lay vi tri dong hien tai cua con tro man hinh trong console
void box(int x, int y, int w, int h, int t_color, int b_color, int nd_color, string nd);    //ve box co noi dung
void box1(int x, int y, int w, int h, int t_color, int b_color);    //ve box khong co noi dung
void thanhSang(int x, int y, int w, int h, int b_color, int nd_color, string nd);
int move(int x, int y, int h, int &yp, int &kt, int soKhung);

//dong chu khi bat dau chuong trinh va luc ket thuc chuong trinh
void start();
void end();

// //xu ly so lon
// string multiply(const string& num1, const string& num2);
// string multiplyMultiple(const vector<string>& numbers);

#endif