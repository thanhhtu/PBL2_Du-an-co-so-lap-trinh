#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "ListAdminAccount.h"
#include "Menu.cpp"

ListAdminAccount::ListAdminAccount(){
    this->head = NULL;
}

ListAdminAccount::~ListAdminAccount(){
    Node<Account> *current = this->head;
    while(current != NULL){
        Node<Account> *temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

void ListAdminAccount::setAdmins(){
    ifstream f ("dataUserAccount.txt");

    while(!f.eof()){
        Account admin;
        admin.setAccount(f);
        this->insertLast(admin);
    }

    f.close();
}

void ListAdminAccount::saveAdmins(){
    ofstream f ("dataAdminAccount.txt");

	this->get(0).saveAccount(f);
    for(int i = 1; i < this->length(); i++){
		f << endl;
		this->get(i).saveAccount(f);
	}

    f.close();
}

void ListAdminAccount::printInforAdmin(){
    cout << "List of user admins: \n";
    for(int i = 0; i < this->length(); i++){
        cout << "Numerical order " << i + 1 << ": \n";
        this->get(i).printInfor();
        cout << endl;
    }
}

bool ListAdminAccount::checkSignIn(Account &admin, const string &username, const string &password){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getUsername() == username && this->get(i).getPassword() == password){
            admin = this->get(i);
            return true;
        }
    }

    return false;
}

void ListAdminAccount::signIn(Account &admin){
    string tempUsername, tempPassword;
    cout << "Enter your username: ";
    cin >> tempUsername;

    cout << "Enter your password: ";
    enterPassword(tempPassword);

    if(this->checkSignIn(admin, tempUsername, tempPassword) == false){
        cout << "\nUsername or password is not correct! Please enter again!\n\n";
        this->signIn(admin);
    }else{
        cout << "\nSign in successfully!\n";
        return;
    }

}