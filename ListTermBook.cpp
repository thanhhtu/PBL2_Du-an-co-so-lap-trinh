#include "ListTermBook.h"

#ifndef LISTTERMBOOK_CPP
#define LISTTERMBOOK_CPP

ListTermBook::ListTermBook(){
    this->numOfTermBook = 0;
    this->head = NULL;
}

ListTermBook::~ListTermBook(){
    Node<TermBook> *current = this->head;
    while(current != NULL){
        Node<TermBook> *temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

void ListTermBook::setTermBooks(){
    ifstream f ("dataTermBook.txt");

    f >> this->numOfTermBook;
    f.ignore();

    while(!f.eof()){
        TermBook termBook;
        termBook.setBook(f);
        this->insertLast(termBook);
    }

    f.close();    
}

void ListTermBook::saveTermBooks(){
    ofstream f ("dataTermBook.txt");

    if(this->length() == 0){
        this->numOfTermBook = 0;
        f << this->numOfTermBook << "\n";
        return;
    }

    f << this->numOfTermBook << "\n";

	this->get(0).saveBook(f);
    for(int i = 1; i < this->length(); i++){
		f << endl;
		this->get(i).saveBook(f);
	}

    f.close();
}

void ListTermBook::printTermBooks(){
    cout << "Term books\n";
    for(int i = 0; i < this->length(); i++){
        cout << "Numerical order " << i + 1 << ": \n";
        this->get(i).printBook();
        cout << endl;
    }
}

void ListTermBook::printUserTermBook(const Account &user, int &ck){
    int x1 = 30, y1 = 5, w1 = 100, h1 = 2;
    box(x1, y1 - 3, w1, h1, 14, 1, 15, "******************************************* TERM BOOK *********************************************");
    int dem = 0;

    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == user.getID()){
           ++dem;
        }
    }

    if(dem == 0){
    	gotoXY(65, y1);
		cout << "You do not have any term books.";
        ck = 0; //kiem tra user co so hay k (0: k co, 1: co)
        return;
	}else{
        string text0 = "      Number";
        string text1 = "         ID";
        string text2 = "     Opening Day";
        string text3 = "       Term";
        string text4 = "      Money";
        
        box(x1, y1, 20, h1, 15, 1, 15, text0);
        box(x1 + 20, y1, 20, h1, 15, 1, 15, text1);
        box(x1 + 40, y1, 20, h1, 15, 1, 15, text2); 
        box(x1 + 60, y1, 20, h1, 15, 1, 15, text3);
        box(x1 + 80, y1, 20, h1, 15, 1, 15, text4);

        for (int i = 1; i < 5; i++){
            gotoXY(x1 + (i * 20), y1 + 2);
            cout << char(193);
            gotoXY(x1 + (i * 20), y1);
            cout << char(194);
        }

        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getID() == user.getID()){
                y1 += 2;
                box1(x1, y1, 20, h1, 15, 1);
                box1(x1 + 20, y1, 20, h1, 15, 1);
                box1(x1 + 40, y1, 20, h1, 15, 1);
                box1(x1 + 60, y1, 20, h1, 15, 1);
                box1(x1 + 80, y1, 20, h1, 15, 1);
                gotoXY(x1, y1);
                cout << char(195);
                gotoXY(x1 + 100, y1);
                cout << char(180);

                for(int J = 1; J < 5; J++){
                    gotoXY(x1 + (J * 20), y1);
                    cout << char(197);
                    gotoXY(x1 + (J * 20), y1 + 2);
                    cout << char(193);
                }
            }
        }

        int y2 = 8;
        dem = 0;

        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getID() == user.getID()){
                gotoXY(x1 + 1, y2);
                cout << "        " << ++dem << "            ";
                this->get(i).printBook();
                for (int J = 0; J < 5; J++){
                    gotoXY(x1 + (J * 20), y2);
                    cout << char(179);
                }
                y2 += 2;  
            }
        }
    }
}

bool ListTermBook::checkIDBook(const string &IDBook){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getIDBook() == IDBook){
            return true;
        }
    }
    return false;
}

void ListTermBook::openTermBook(TermBook &termBook, const Account &user, const Date &currentDate, int x, int y, int w, int h){
    string tempIDBook; 
    string tempID = user.getID();  
    Date tempOpeningDate(currentDate);
	string tempMoney;
    int tempTerm;

    string a = "TERMBOOK";
    this->numOfTermBook++;
    tempIDBook = a + to_string(this->numOfTermBook);
    if(checkIDBook(tempIDBook) == true){
        cout << "Error: The ID Book has been already existed!\n";
    }

    const int xx = x, yy = y, ww = w, hh = h;
    string text1 = "                      3-month";
    string text2 = "                      6-month";
    string text3 = "                     12-month";
    string text4 = "                     18-month";    

    box(xx, yy - 2, ww, hh, 15, 14, 15, "******* Select the term you want to open ********");
    box(xx, yy, ww, hh, 15, 1, 15, text1);
    box(xx, yy + 2, ww, hh, 15, 1, 15, text2);
    box(xx, yy + 4, ww, hh, 15, 1, 15, text3);
    box(xx, yy + 6, ww, hh, 15, 1, 15, text4);

    for(int i = 0; i < 4; i++){
        gotoXY(xx, yy + 2 * i); cout << char(195);
        gotoXY(xx + ww, yy + 2 * i); cout << char(180);
    }
    
    int xp = xx;     //xp, yp: toa do thanh sang
    int yp = yy;     
    int xcu, ycu;   //xcu, ycu: toa do cu
    int check;
    int kt = true;

    while(true){
        if(kt == true){
            gotoXY(xcu, ycu);
            if(ycu == yy) thanhSang(xcu, ycu, ww, hh, 1, 15, text1);
            if(ycu == yy + 2) thanhSang(xcu, ycu, ww, hh, 1, 15, text2);
            if(ycu == yy + 4) thanhSang(xcu, ycu, ww, hh, 1, 15, text3);
            if(ycu == yy + 6) thanhSang(xcu, ycu, ww, hh, 1, 15, text4);
            xcu = xp;
            ycu = yp;
            if(ycu == yy) thanhSang(xp, yp, ww, hh, 100, 15, text1);
            if(ycu == yy + 2) thanhSang(xp, yp, ww, hh, 100, 15, text2);
            if(ycu == yy + 4) thanhSang(xp, yp, ww, hh, 100, 15, text3);
            if(ycu == yy + 6) thanhSang(xp, yp, ww, hh, 100, 15, text4);
            kt = false;            
        }
        check = move(xx, yy, hh, yp, kt, 4);
        if(check == yy || check == yy + 2 || check == yy + 4 || check == yy + 6){
            break;
        }
    }

    if(check ==  yy){
        tempTerm = 3;
    }else if(check == yy + 2){
        tempTerm = 6;
    }else if(check == yy + 4){
        tempTerm = 12;
    }else{
        tempTerm = 18;
    }

    SetColor(0);
    textcolor(15);
    int nx = 45, ny = yy + 9, nw = 60, nh = 2;
    gotoXY(nx + 8, ny); cout << " Open a savings book with a term of " << tempTerm << "-month.";

    do{
        box(nx, ny + 2, nw, nh, 15, 14, 15, "   Enter the amount of money: ");
        gotoXY(nx + 33, ny + 3); getline(cin, tempMoney);
        if(!isNumeric(tempMoney) || isEmptyNoWhitespace(tempMoney)){
            gotoXY(nx + 16, ny + 5);
            cout << "Error: The money is invalid!";
            return;
        }
    }while(!isNumeric(tempMoney) || isEmptyNoWhitespace(tempMoney));

    gotoXY(nx + 16, ny + 5); cout << "Open saving book successfully!";

    termBook.setIDBook(tempIDBook);
    termBook.setID(tempID);
    termBook.setOpeningDate(tempOpeningDate);
    termBook.setMoney(tempMoney);
    termBook.setTerm(tempTerm);
    
    this->insertLast(termBook);
    
    this->saveTermBooks();    
}

TermBook* ListTermBook::findBookByID(const string &IDBook) const{
    Node<TermBook> *current = head;
    while(current != NULL){
        if(current->data.getIDBook() == IDBook){
            return &(current->data);    //Return address of the TermBook object
        }
        current = current->next;
    }
    return NULL;     //Return nullptr if not found
}

TermBook *ListTermBook::findUserBookByID(const string &ID, const string &IDBook) const{
    Node<TermBook> *current = head;
    while(current != NULL){
        if(current->data.getID() == ID && current->data.getIDBook() == IDBook){
            return &(current->data);    //Return address of the TermBook object
        }
        current = current->next;
    }
    return NULL;     //Return nullptr if not found    
}

void ListTermBook::removeBookByIDBook(const string &IDBook){
    Node<TermBook> *current = this->head;
    if(current == NULL){
        return;
    }
    while(current != NULL){
        if(current->data.getIDBook() == IDBook){
            this->remove(current);
            break;
        }else{
            current = current->next;
        }
    }
    this->saveTermBooks();
}

void ListTermBook::removeBookByID(const string &ID){
    Node<TermBook> *current = this->head;
    if(current == NULL){
        return;
    }
    while(current != NULL){
        if(current->data.getID() == ID){
            this->remove(current);
        }
        current = current->next;
    }
    this->saveTermBooks();
}

void ListTermBook::listBookByYear(const string &year){
    system("cls");
    int x1 = 30, y1 = 5, w1 = 100, h1 = 2;
    int y2 = 8;
    int dem = 0, count = 0;

    box(x1, y1 - 3, w1, h1, 14, 1, 15, "************************************** LIST TERM BOOK BY YEAR *************************************");

    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getOpeningYear() == year){
           ++dem;
        }
    }

    if(dem == 0){
    	gotoXY(x1 + 25, y1);
		cout << "There are not any term books in this year.";
        return;
	}else{
        string text0 = "      Number";
        string text1 = "        ID";
        string text2 = "     Opening Day";
        string text3 = "       Term";
        string text4 = "      Money";
        string text5 = "       Interest";   
        
        box(x1, y1, 20, h1, 15, 1, 15, text0);
        box(x1 + 20, y1, 20, h1, 15, 1, 15, text1);
        box(x1 + 40, y1, 20, h1, 15, 1, 15, text2); 
        box(x1 + 60, y1, 20, h1, 15, 1, 15, text3);
        box(x1 + 80, y1, 20, h1, 15, 1, 15, text4);
        // box(x1 + 100, y1, 20, h1, 15, 1, 15, text5);

        for (int i = 1; i < 5; i++){
            gotoXY(x1 + (i * 20), y1 + 2);
            cout << char(193);
            gotoXY(x1 + (i * 20), y1);
            cout << char(194);
        }

        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getOpeningYear() == year){
                y1 += 2;
                box1(x1, y1, 20, h1, 15, 1);
                box1(x1 + 20, y1, 20, h1, 15, 1);
                box1(x1 + 40, y1, 20, h1, 15, 1);
                box1(x1 + 60, y1, 20, h1, 15, 1);
                box1(x1 + 80, y1, 20, h1, 15, 1);
                // box1(x1 + 100, y1, 20, h1, 15, 1);

                gotoXY(x1, y1); cout << char(195);
                gotoXY(x1 + 100, y1); cout << char(180);

                for (int J = 1; J < 5; J++){
                    gotoXY(x1 + (J * 20), y1);
                    cout << char(197);
                    gotoXY(x1 + (J * 20), y1 + 2);
                    cout << char(193);
                }

                gotoXY(x1 + 1, y2);
                cout << "        " << ++count << "            ";
                this->get(i).printBook();
                for (int J = 0; J < 5; J++){
                    gotoXY(x1 + (J * 20), y2);
                    cout << char(179);
                }
                y2 += 2;  
            }
        }
        return;
    }
}

#endif
