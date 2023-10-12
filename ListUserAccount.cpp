#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "ListUserAccount.h"
#include "Menu.cpp"

ListUserAccount::ListUserAccount(){
    this->numOfUser = 0;
    this->head = NULL;
}

ListUserAccount::~ListUserAccount(){
    Node<Account> *current = this->head;
    while(current != NULL){
        Node<Account> *temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

void ListUserAccount::setUsers(){
    ifstream f ("dataUserAccount.txt");

    f >> this->numOfUser;
    f.ignore();

    while(!f.eof()){
        Account user;
        user.setAccount(f);
        this->insertLast(user);
    }

    f.close();
}

void ListUserAccount::saveUsers(){
    ofstream f ("dataUserAccount.txt");

    f << this->numOfUser << "\n";

	this->get(0).saveAccount(f);
    for(int i = 1; i < this->length(); i++){
		f << endl;
		this->get(i).saveAccount(f);
	}

    f.close();
}

void ListUserAccount::printInforUsers(){
    cout << "List of user accounts: \n";
    for(int i = 0; i < this->length(); i++){
        cout << "Numerical order " << i + 1 << ": \n";
        this->get(i).printInfor();
        cout << endl;
    }
}


bool ListUserAccount::checkID(const string &ID){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == ID){
            return true;
        }
    }
    return false;

}

bool ListUserAccount::checkUsername(const string &username){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getUsername() == username){
            return true;
        }
    }
    return false;
}

bool ListUserAccount::checkPassword(const string &password){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getPassword() == password){
            return true;
        }
    }
    return false;
}

bool ListUserAccount::checkIDCard(const string &IDCard){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getIDCard() == IDCard){
            return true;
        }
    }
    return false;
}

void ListUserAccount::signUp(Account &user){
    string tempID, tempUsername, tempPassword;
    string tempName, tempIDCard, tempAddress, tempTel;

    string a = "USER";
    this->numOfUser++;
    tempID = a + to_string(this->numOfUser);
    if(checkID(tempID) == true){
        cout << "Error: The ID has been already existed!\n";
    }

    do{
        cout << "Enter username: ";
        getline(cin, tempUsername);

        if(this->checkUsername(tempUsername)){
            cout << "This username has been used. Please enter other username!\n\n";
        }

    }while(this->checkUsername(tempUsername));

    cout << "Enter password: ";
    enterPassword(tempPassword);

    cout << "\n\nYour information \n";

    cout << "Enter full name: ";
    getline(cin, tempName);

    do{
        cout << "Enter identity card number: ";
        getline(cin, tempIDCard);

        if(this->checkIDCard(tempIDCard)){
            cout << "The identity card number matches the registered account. Please re-enter!\n\n";
        }

    }while(this->checkIDCard(tempIDCard));

    cout << "Enter your address: ";
    getline(cin, tempAddress);
    cout << "Enter your phone number: ";
    enterNumber(tempTel);
    
    cout << "\nSign up successfully!\n";

    user.setID(tempID);
    user.setUsername(tempUsername);
    user.setPassword(tempPassword);
    user.setName(tempName);
    user.setIDCard(tempIDCard);
    user.setAddress(tempAddress);
    user.setTel(tempTel);
    
    this->insertLast(user);
    
    this->saveUsers();
}

bool ListUserAccount::checkSignIn(Account &user, const string &username, const string &password){
    //kiem tra co dung username va password khong
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getUsername() == username && this->get(i).getPassword() == password){
            user = this->get(i);
            return true;
        }
    }
    return false;
}

void ListUserAccount::signIn(Account &user){
    string tempUsername, tempPassword;
    cout << "Enter your username: ";
    cin >> tempUsername;

    cout << "Enter your password: ";
    enterPassword(tempPassword);

    if(this->checkSignIn(user, tempUsername, tempPassword) == false){
        cout << "\nUsername or password is not correct! Please enter again!\n";
        this->signIn(user);
    }else{
        cout << "\nSign in successfully!\n";
        return;
    }

}