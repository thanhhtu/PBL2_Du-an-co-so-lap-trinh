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

void ListNonTermBook::printUserNonTermBook(const Account &user){
    cout << "NON-TERM BOOKS\n";
    int count = 0;
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == user.getID()){
            cout << "Numerical order " << ++count << ": \n";
            this->get(i).printBook();
            cout << endl;
        }
    }

    if(count == 0){
        cout << "You do not have any non-term books." << endl;
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

    box(x, y, w, h, 15, 1, 15, "   Enter the amount of money: ");
    gotoXY(x + 33, y + 1); getline(cin, tempMoney);

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

#endif