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

void ListTermBook::openTermBook(TermBook &termBook, const Account &user, const Date &currentDate){
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

    float choice;
    do{
        cout << "Select the term you want to open: \n";
        cout << "1. 3-month saving book.\n";
        cout << "2. 6-month saving book.\n";
        cout << "3. 12-month saving book.\n";
        cout << "4. 18-month saving book.\n";

        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        
        if(!(choice == int(choice) && choice >= 1 && choice <= 3)){
            cout << "Invalid input!! Please choose again.\n" << endl;
        }        
    }while(!(choice == int(choice) && choice >= 1 && choice <= 3));
    if(choice == 1){
        tempTerm = 3;
    }else if(choice == 2){
        tempTerm = 6;
    }else if(choice == 3){
        tempTerm = 12;
    }else{
        tempTerm = 18;
    }
    cout << "Enter the amount of money: ";
    getline(cin, tempMoney);

    cout << "\nOpen successfully!\n";

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
    while(current != NULL){
        if(current->data.getID() == ID){
            this->remove(current);
        }
        current = current->next;
    }
    this->saveTermBooks();
}

#endif