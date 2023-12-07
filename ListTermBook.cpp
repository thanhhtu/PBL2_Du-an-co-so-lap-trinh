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

void ListTermBook::printUserTermBook(const Account &user){
    cout << "TERM BOOKS\n";
    int count = 0;
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == user.getID()){
            cout << "Numerical order " << ++count << ": \n";
            this->get(i).printBook();
            cout << endl;
        }
    }
    if(count == 0){
        cout << "You do not have any term books." << endl;
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
    gotoXY(nx + 8, ny); cout << "Open a savings book with a term of " << tempTerm << " book.";
    box(nx, ny + 2, nw, nh, 15, 14, 15, "   Enter the amount of money: ");
    gotoXY(nx + 33, ny + 3); getline(cin, tempMoney);

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

#endif
