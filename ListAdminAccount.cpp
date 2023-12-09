#include "ListAdminAccount.h"

#ifndef LISTADMINACCOUNT_CPP
#define LISTADMINACCOUNT_CPP

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
    ifstream f ("dataAdminAccount.txt");

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
    system("cls");
    SetColor(15);

    string tempUsername, tempPassword;

    int x = 55, y = 5, w = 40, h = 2;
    box(x, y - 3, w, h, 11, 1, 11, "************* ADMIN SIGN IN ************");

    box(x, y, w, h, 15, 1, 15, " Username: ");
    gotoXY(x + 12, y + 1); getline(cin, tempUsername);

    box(x, y + 2, w, h, 15, 1, 15, " Password: ");
    gotoXY(x, y + 2); cout << char(195);   
    gotoXY(x + w, y + 2); cout << char(180);   
    gotoXY(x + 12, y + 2 + 1); enterPassword(tempPassword);

    if(this->checkSignIn(admin, tempUsername, tempPassword) == false){
        gotoXY(x - 5, y + 6);
        cout << "Error: Username or password is not correct! Please enter again!";
        gotoXY(x - 5, y + 7);
        SetColor(72);
        system("pause");
        system("cls");
        this->signIn(admin);
    }else{
        gotoXY(x + 9, y + 6);
        cout << "Sign in successfully!\n";
        gotoXY(x + 6, y + 7);
        SetColor(72);
        system("pause");
        return;
    }
}

#endif