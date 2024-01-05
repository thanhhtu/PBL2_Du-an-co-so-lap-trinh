#include "ListNonTermBook.h"

#ifndef LISTNONTERMBOOK_CPP
#define LISTNONTERMBOOK_CPP

ListNonTermBook::ListNonTermBook(){
    this->numOfNonTermBook = 0;
    this->head = NULL;
}

ListNonTermBook::~ListNonTermBook(){
    Node<NonTermBook> *current = this->head;
    while(current != NULL){
        Node<NonTermBook> *temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

void ListNonTermBook::setNonTermBooks(){
    ifstream f ("dataNonTermBook.txt");

    f >> this->numOfNonTermBook;
    f.ignore();

    while(!f.eof()){
        NonTermBook nonTermBook;
        nonTermBook.setBook(f);
        this->insertLast(nonTermBook);
    }

    f.close();    
}
void ListNonTermBook::saveNonTermBooks(){
    ofstream f ("dataNonTermBook.txt");

    if(this->length() == 0){
        this->numOfNonTermBook = 0;
        f << this->numOfNonTermBook << "\n";
        return;
    }

    f << this->numOfNonTermBook << "\n";

	this->get(0).saveBook(f);
    for(int i = 1; i < this->length(); i++){
		f << endl;
		this->get(i).saveBook(f);
	}

    f.close();
}

void ListNonTermBook::printNonTermBooks(){
    cout << "NON-TERM BOOK\n";
    for(int i = 0; i < this->length(); i++){
        cout << "Numerical order " << i + 1 << ": \n";
        this->get(i).printBook();
        cout << endl;
    }
}

void ListNonTermBook::printUserNonTermBook(const Account &user, int &ck){
    int y1 = getCurrentCursorPositionY();
    y1 = y1 + 4;
    int x1 = 40, w1 = 80, h1 = 2;
    box(x1, y1 - 3, w1, h1, 14, 1, 15, "********************************** NONTERM BOOK *******************************");
    int dem = 0;
    
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == user.getID()){
            ++dem;
        }
    }

    if(dem == 0){ 
        SetColor(0);
        textcolor(15);
    	gotoXY(63, y1);
		cout << "You do not have any non term books.\n";
        ck = 0; //kiem tra user co so hay k (0: k co, 1: co)
        return;
    }else{
        string text0 = "      Number";
        string text1 = "         ID";
        string text2 = "     Opening Day";
        string text3 = "      Money";

        box(x1, y1, 20, h1, 15, 1, 15, text0);
        box(x1 + 20, y1, 20, h1, 15, 1, 15, text1);
        box(x1 + 40, y1, 20, h1, 15, 1, 15, text2); 
        box(x1 + 60, y1, 20, h1, 15, 1, 15, text3);

        for (int i = 1; i < 4; i++){
            gotoXY(x1 + (i * 20), y1 + 2);
            cout << char(193);
            gotoXY(x1 + (i * 20), y1);
            cout << char(194);
        }

        int z = y1 + 2;
        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getID() == user.getID()){
                y1 += 2;
                box1(x1, y1, 20, h1, 15, 1);
                box1(x1 + 20, y1, 20, h1, 15, 1);
                box1(x1 + 40, y1, 20, h1, 15, 1);
                box1(x1 + 60, y1, 20, h1, 15, 1);
                gotoXY(x1, y1);
                cout << char(195);
                gotoXY(x1 + 80, y1);
                cout << char(180);
                
                for (int J = 1; J < 4; J++){
                    gotoXY(x1 + (J * 20), y1);
                    cout << char(197);
                    gotoXY(x1 + (J * 20), y1 + 2);
                    cout << char(193);
                }
            }
        }

        int y2 = z + 1;
        dem = 0;

        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getID() == user.getID()){
                gotoXY(x1 + 2, y2);
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


bool ListNonTermBook::checkIDBook(const string &IDBook){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getIDBook() == IDBook){
            return true;
        }
    }
    return false;
}

void ListNonTermBook::openNonTermBook(NonTermBook &nonTermBook, const Account &user, const Date &currentDate, int x, int y, int w, int h){
    string tempIDBook; 
    string tempID = user.getID();  
    Date tempOpeningDate(currentDate);
	string tempMoney;

    string a = "NONTERMBOOK";
    this->numOfNonTermBook++;
    tempIDBook = a + to_string(this->numOfNonTermBook);
    if(checkIDBook(tempIDBook) == true){
        cout << "Error: The ID Book has been already existed!\n";
    }

    do{
        box(x, y, w, h, 15, 14, 15, "   Enter the amount of money: ");
        gotoXY(x + 33, y + 1); getline(cin, tempMoney);
        if(!isNumeric(tempMoney) || isEmptyNoWhitespace(tempMoney)){
            gotoXY(x + 16, y + 3);
            cout << "Error: The money is invalid!";
            return;
        }
    }while(!isNumeric(tempMoney) || isEmptyNoWhitespace(tempMoney));

    gotoXY(x + 16, y + 3); cout << "Open saving book successfully!";

    nonTermBook.setIDBook(tempIDBook);
    nonTermBook.setID(tempID);
    nonTermBook.setOpeningDate(tempOpeningDate);
    nonTermBook.setMoney(tempMoney);
    
    this->insertLast(nonTermBook);
    
    this->saveNonTermBooks();    
}

NonTermBook* ListNonTermBook::findBookByID(const string &IDBook) const{
    Node<NonTermBook> *current = head;
    while(current != NULL){
        if(current->data.getIDBook() == IDBook){
            return &(current->data); 
        }
        current = current->next;
    }
    return NULL; 
}

NonTermBook *ListNonTermBook::findUserBookByID(const string &ID, const string &IDBook) const{
    Node<NonTermBook> *current = head;
    while(current != NULL){
        if(current->data.getID() == ID && current->data.getIDBook() == IDBook){
            return &(current->data);    //Return address of the TermBook object
        }
        current = current->next;
    }
    return NULL;     //Return nullptr if not found    
}

void ListNonTermBook::removeBookByIDBook(const string &IDBook){
    Node<NonTermBook> *current = this->head;
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
    this->saveNonTermBooks();
}

void ListNonTermBook::removeBookByID(const string &ID){
    Node<NonTermBook> *current = this->head;
    if(current == NULL){
        return;
    }
    while(current != NULL){
        if(current->data.getID() == ID){
            this->remove(current);
        }
        current = current->next;
    }
    this->saveNonTermBooks();
}

void ListNonTermBook::listBookByYear(const string &year, float &itr, const Date &currentDate){
    int x1 = 40, y1 = getCurrentCursorPositionY() + 4, w1 = 80, h1 = 2;
    int y2 = y1 + 3;
    int dem = 0, count = 0;

    box(x1, y1 - 3, w1, h1, 11, 1, 15, "*************************** LIST NONTERM BOOK BY YEAR *************************");

    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getOpeningYear() == year){
           ++dem;
        }
    }

    if(dem == 0){
        SetColor(0);
        textcolor(15);
    	gotoXY(x1 + 17, y1);
		cout << "There are not any nonterm books in this year.";
        gotoXY(x1 + 25, whereY() - 1);
        return;
	}else{
        string text0 = "      Number";
        string text1 = "        ID";
        string text2 = "     Opening Day";
        string text3 = "      Money";
        // string text5 = "       Interest";   
        
        box(x1, y1, 20, h1, 15, 1, 15, text0);
        box(x1 + 20, y1, 20, h1, 15, 1, 15, text1);
        box(x1 + 40, y1, 20, h1, 15, 1, 15, text2); 
        box(x1 + 60, y1, 20, h1, 15, 1, 15, text3);
        // box(x1 + 100, y1, 20, h1, 15, 1, 15, text5);

        for (int i = 1; i < 4; i++){
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
                // box1(x1 + 80, y1, 20, h1, 15, 1);

                gotoXY(x1, y1); cout << char(195);
                gotoXY(x1 + 80, y1); cout << char(180);

                for(int J = 1; J < 4; J++){
                    gotoXY(x1 + (J * 20), y1);
                    cout << char(197);
                    gotoXY(x1 + (J * 20), y1 + 2);
                    cout << char(193);
                }

                gotoXY(x1 + 2, y2);
                cout << "        " << ++count << "            ";
                this->get(i).printBook();
                for(int J = 0; J < 4; J++){
                    gotoXY(x1 + (J * 20), y2);
                    cout << char(179);
                }
                y2 += 2;  
            }
        }

        for(int i = 0; i < this->length(); i++){
            if(this->get(i).getOpeningYear() == year){
                itr += this->get(i).interestRate(currentDate);
            }
        }
        return;
    }
}

#endif