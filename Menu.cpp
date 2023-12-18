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
	printf("\t\t\t\t\t%c", Goc_Tren_Trai);
	for (int i = 0; i <= 70; i++) {
		printf("%c", Ngang);
	}
	printf("%c", Goc_Tren_Phai);
	
	printf("\n\t\t\t\t\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t\t\t\t\t%c\t\t    PBL2: DU AN CO SO LAP TRINH         \t\t%c", Doc, Doc);
	
	printf("\n\t\t\t\t\t%c\t\t    De tai: QUAN LY SO TIET KIEM NGAN HANG	        %c", Doc, Doc);
	
	printf("\n\t\t\t\t\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t\t\t\t\t%c\t Giao vien huong dan: NGUYEN VAN NGUYEN    \t\t\t%c", Doc, Doc);

	printf("\n\t\t\t\t\t%c\t Ten sinh vien: VO THANH TU               MSSV: 102220257\t%c", Doc, Doc);
	printf("\n\t\t\t\t\t%c\t                LE NGUYEN AI TRAN         MSSV: 102220255\t%c", Doc, Doc);

	printf("\n\t\t\t\t\t%c\t Lop sinh hoat: 22T_DT5                                  \t%c", Doc, Doc);
	printf("\n\t\t\t\t\t%c\t Lop hoc phan:  22NH10                                    \t%c", Doc, Doc);	
	
	printf("\n\t\t\t\t\t%c\t\t                                         \t\t%c", Doc, Doc);
	printf("\n\t\t\t\t\t%c", Goc_Duoi_Trai);
	for (int i = 0; i <= 70; i++) {
		printf("%c", Ngang);
	}
	printf("%c", Goc_Duoi_Phai);
	printf("\n");
	
	printf("\n\t\t\t\t\t Press any key to start ");

	getch();
	while (true){
		break;
	}
}

int getCurrentCursorPositionY(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

int toContinue1(int x, int y){
	SetColor(72);
	gotoXY(x, y); cout << " Press [ESC] to go back to MENU...";
	gotoXY(x, y + 1); cout << "Press any key to exit the program...";

	char c = getch();
	if(c == 27){
		return 1;
	}else{
		return 0;
	}
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

void box(int x, int y, int w, int h, int t_color, int b_color, int nd_color, string nd){
	//========== BACKGROUNG ==========
	textcolor(b_color);
	for(int iy = y + 1; iy <= y + h - 1; iy++){
		for(int ix = x + 1; ix <= x + w - 1; ix++){
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	
	//========== NOI DUNG ==========
	SetColor(nd_color);	//15: chu mau trang
	gotoXY(x + 1, y + 1);
	cout << nd;
	
	//========== VE VIEN ==========
	textcolor(1);
	SetColor(t_color);
	//ke ngang
	if(h <= 1 || w <= 1) return;
	for(int ix = x; ix <= x + w; ix++){
		gotoXY(ix, y);
		cout << char(196);	//196: ke ngang
		gotoXY(ix, y + h);
		cout << char(196);
	}
	//ke doc
	for(int iy = y; iy <= y + h; iy++){
		gotoXY(x, iy);
		cout << char(179);	//179: ke doc
		gotoXY(x + w, iy);
		cout << char(179);
	}
	//4 goc
	gotoXY(x, y);
	cout << char(218);	//218: goc tren ben trai
	gotoXY(x + w, y);
	cout << char(191);	//191: goc tren ben phai
	gotoXY(x, y + h);
	cout << char(192);	//192: goc tren ben phai
	gotoXY(x + w, y + h);
	cout << char(217);	//217: goc tren ben phai
}

void thanhSang(int x, int y, int w, int h, int b_color, int nd_color, string nd){
	textcolor(b_color);
	for(int iy = y + 1; iy <= y + h - 1; iy++){
		for(int ix = x + 1; ix <= x + w - 1; ix++){
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	
	SetColor(nd_color);	
	gotoXY(x + 1, y + 1);
	cout << nd;
}

void box1(int x, int y, int w, int h, int t_color, int b_color){
	//========== BACKGROUNG ==========
	textcolor(b_color);
	for(int iy = y + 1; iy <= y + h - 1; iy++){
		for(int ix = x + 1; ix <= x + w - 1; ix++){
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	//========== VE VIEN ==========
	textcolor(1);
	SetColor(t_color);
	//ke ngang
	if(h <= 1 || w <= 1) return;
	for(int ix = x; ix <= x + w; ix++){
		gotoXY(ix, y);
		cout << char(196);	//196: ke ngang
		gotoXY(ix, y + h);
		cout << char(196);
	}
	//ke doc
	for(int iy = y; iy <= y + h; iy++){
		gotoXY(x, iy);
		cout << char(179);	//179: ke doc
		gotoXY(x + w, iy);
		cout << char(179);
	}
	//4 goc
	gotoXY(x, y);
	cout << char(218);	//218: goc tren ben trai
	gotoXY(x + w, y);
	cout << char(191);	//191: goc tren ben phai
	gotoXY(x, y + h);
	cout << char(192);	//192: goc tren ben phai
	gotoXY(x + w, y + h);
	cout << char(217);	//217: goc tren ben phai
}

int move(int x, int y, int h, int &yp, int &kt, int soKhung){
	if(_kbhit()){		
		char c = getch();
		if(c == -32){
			kt = true;
			c = getch();    
			if(c == 72 && yp != y){   
				yp -= 2;
			}else if(c == 72 && yp == y){
				yp = y + h * (2 - 1) ;
			}else if(c == 80  && yp != y + h * (soKhung - 1)){
				yp += 2;
			}else if(c == 80  && yp == y + h * (soKhung - 1)){
				yp = y;
			} 
		}else if(c == 13){
			kt = false;
			return yp;
		}
	}   
}

bool isEmptyNoWhitespace(const string& str){
    if (str.empty()){
        return true;		
    }
    int tmp = 0;
    for(int i = 0; i < str.length(); i++){
    	char c = str[i];
        if (!isspace(c)){
        	tmp = 1;
            return false;
        }
    }
    if(tmp == 0){
    	return true;
	}
}

void end(){
	int x = 32, y = 3;
	int i = 1;	
	while(true){
		if (i % 16 == 0){
			i = 1;
		}
		SetColor(i);
		gotoXY(x, y); cout << "	           _____    ____     ____    _____    ____   __     __  ______  " << endl;
		gotoXY(x, y + 1); cout << "		  / ____|  / __ \\   / __ \\  |  __ \\  |  _ \\  \\ \\   / / |  ____| " << endl;
		gotoXY(x, y + 2); cout << "		 | |  __  | |  | | | |  | | | |  | | | |_) |  \\ \\_/ /  | |__    " << endl;
		gotoXY(x, y + 3); cout << "		 | | |_ | | |  | | | |  | | | |  | | |  _ <    \\   /   |  __|   " << endl;
		gotoXY(x, y + 4); cout << "		 | |__| | | |__| | | |__| | | |__| | | |_) |    | |    | |____  " << endl;
		gotoXY(x, y + 5); cout << "		  \\_____|  \\____/   \\____/  |_____/  |____/     |_|    |______| " << endl;
	          
	    i++;     
		Sleep(500);	                                                       
		if (_kbhit() == true){
			char a = _getch();
			if (a == 13){
				break;
			}
		}		                                                  
	}
	SetColor(15);
}

void start(){
	int x = 5, y = 3;
	SetColor(6);
	
	gotoXY(x, y); cout <<	    "			  ____               _   _   _  __  _____   _   _    _____     		";  
	gotoXY(x, y + 1); cout <<	"			 |  _  \\     /\\     | \\ | | | |/ / |_   _| | \\ | |  / ____|    	";  
	gotoXY(x, y + 2); cout <<	"			 | |_) |    /  \\    |  \\| | | ' /    | |   |  \\| | | |  __     	";  
	gotoXY(x, y + 3); cout <<	"			 |  _ <    / /\\ \\   | . ` | |  <     | |   | . ` | | | |_ |    	";  
	gotoXY(x, y + 4); cout <<	"			 | |_) |  / ____ \\  | |\\  | | . \\   _| |_  | |\\  | | |__| |    	";  
	gotoXY(x, y + 5); cout <<	"			 |____/  /_/    \\_\\ |_| \\_| |_|\\_\\ |_____| |_| \\_|  \\_____|  ";  
                                                        
    int xx = 40;
	gotoXY(xx, y + 10); cout <<	"			   _____  __     __   _____   _______   ______   __  __   ";
	gotoXY(xx, y + 11); cout <<	"			  / ____| \\ \\   / /  / ____| |__   __| |  ____| |  \\/  |  ";
	gotoXY(xx, y + 12); cout <<	"			 | (___     \\ \_/ /  | (___      | |    | |__    | \\  / |  ";
	gotoXY(xx, y + 13); cout <<	"			  \\___ \\    \\   /    \\___ \\     | |    |  __|   | |\\/| |  ";
	gotoXY(xx, y + 14); cout <<	"			  ____) |    | |     ____) |    | |    | |____  | |  | |  ";
	gotoXY(xx, y + 15); cout <<	"			 |_____/     |_|    |_____/     |_|    |______| |_|  |_|  ";
                                                                                                                         
	int w = 30, h = 2;
	box(x + 58, y + 20, w, h, 15, 1, 15, "    ENTER TO START PROGRAM");  
	gotoXY(x + 55, y + 23); SetColor(0); system("pause");                                                              
}

#endif