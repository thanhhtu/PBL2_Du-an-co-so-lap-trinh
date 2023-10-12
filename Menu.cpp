#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#include "Menu.h"

#ifndef MENU_CPP
#define MENU_CPP

#define Ngang 205
#define Doc 179
#define Goc_Tren_Trai 213
#define Goc_Duoi_Trai 212
#define Goc_Tren_Phai 184
#define Goc_Duoi_Phai 190

void title() {
	printf("\t%c", Goc_Tren_Trai);
	for (int i = 0; i <= 70; i++) {
		printf("%c", Ngang);
	}
	printf("%c", Goc_Tren_Phai);
	
	printf("\n\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t%c\t\t     PBL1: DU AN CO SO LAP TRINH         \t\t%c", Doc, Doc);
	
	printf("\n\t%c\t\t      De tai: QUAN LY NGAN HANG		   \t\t%c", Doc, Doc);
	
	printf("\n\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t%c\t Giao vien huong dan: NGUYEN VAN NGUYEN    \t\t\t%c", Doc, Doc);

	printf("\n\t%c\t Ten sinh vien: VO THANH TU               MSSV: 102220257\t%c", Doc, Doc);
	printf("\n\t%c\t                LE NGUYEN AI TRAN         MSSV: 102220255\t%c", Doc, Doc);

	printf("\n\t%c\t Lop sinh hoat: 22T_DT5                                  \t%c", Doc, Doc);
	printf("\n\t%c\t Lop hoc phan:  22NH10                                    \t%c", Doc, Doc);	
	
	printf("\n\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t%c", Goc_Duoi_Trai);
	for (int i = 0; i <= 70; i++) {
		printf("%c", Ngang);
	}
	printf("%c", Goc_Duoi_Phai);
	printf("\n");
	
	printf("\nPress any key to start the program ");
}

/* 
	MO TA HINH THUC:
	Khi user nhap them 1 ky tu vao temp_password thi tren man hinh console xuat hien 1 dau *.
	Ket thuc nhap temp_password khi ki tu nhap vao la Enter (gia tri ASCII 13).
	Neu ki tu nhap vao khong phai la Enter thi kiem tra xem no co phai Backspace (gia tri ASCII 8) hay khong, 
	neu phai thi xoa ki tu cuoi cung ra khoi temp_password va xoa bot 1 dau * tren console.
*/
void enterPassword(string &password){
	char x;
    while(x != 13){
    	int index;
        x = getch();
        
        if(x == 13){
        	return;
		}else if(x == 8 && password.size() != 0){
			/*
				Khi user nhan Backspace va dam bao temp_password khong trong thi thuc hien:
				- Xoa ki tu cuoi cung trong temp_password.
				- Xoa 1 dau * tren console:
					"\b" di chuyen con tro console ve 1 vi tri truoc do.
					Sau do, " " duoc in ra, ghi de len vi tri hien tai. => In ra khoang trang tren man hinh console.
					"\b" tiep theo di chuyen con tro console quay lai vi tri ky tu vua duoc ghi de (vi tri con tro console quay lai o buoc 1).
				=> Tao hieu ung khi nhan Backspace se xoa duoc ky tu vua nhap.
			*/
				
        	index = password.size() - 1;
            password.erase(index);
            
            cout << "\b" << " \b";
        }else if (x != 8){
            password += x;
            cout << '*';
        }
    }	
}

void enterNumber(string &number){
	getline(cin, number);
	for(int i = 0; i < number.size(); i++){
		if(number[i] < 48 || number[i] > 57){
			cout << "Error: Phone number can not a charater. Please enter again!\n";
			enterNumber(number);
		}
	}
	return;
}

#endif