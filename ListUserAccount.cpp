#include "ListUserAccount.h"

#ifndef LISTUSERACCOUNT_CPP
#define LISTUSERACCOUNT_CPP

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

    system("cls");
    SetColor(15);

    int x = 30, y = 5, w = 45, h = 2;
    box(x, y - 3, w, h, 14, 1, 14, "************* USER SIGN UP **************");

    box(x, y, w, h, 15, 1, 15, " Username: ");
    gotoXY(x + 12, y + 1); getline(cin, tempUsername);

    keDuoi(x, y + 2, w, h, 15, 1, 15, " Password: ");
    gotoXY(x, y + 2); cout << char(195);   
    gotoXY(x + w, y + 2); cout << char(180);   
    gotoXY(x + 12, y + 2 + 1); enterPassword(tempPassword);

    if(this->checkUsername(tempUsername) == true){
        gotoXY(x - 5, y + 6);
        cout << "Error: This username has been used. Please enter other username!";
        gotoXY(x - 5, y + 7);
        SetColor(72);
        system("pause");
        system("cls");
        this->signUp(user);        
    }

    system("cls");
    x = 28, y = 5, w = 60, h = 2;
INFOR:
    box(x, y - 3, w, h, 14, 1, 14, "***************** USER INFORMATION FORM ******************");

    box(x, y, w, h, 15, 1, 15, " Full name: ");
    gotoXY(x + 13, y + 1); getline(cin, tempName);

    keDuoi(x, y + 2, w, h, 15, 1, 15, " Identity card number: ");
    gotoXY(x, y + 2); cout << char(195);   
    gotoXY(x + w, y + 2); cout << char(180);   
    gotoXY(x + 24, y + 2 + 1); getline(cin, tempIDCard);

    keDuoi(x, y + 4, w, h, 15, 1, 15, " Address: ");
    gotoXY(x, y + 4); cout << char(195);   
    gotoXY(x + w, y + 4); cout << char(180);   
    gotoXY(x + 11, y + 4 + 1); getline(cin, tempAddress);

    keDuoi(x, y + 6, w, h, 15, 1, 15, " Phone number: ");
    gotoXY(x, y + 6); cout << char(195);   
    gotoXY(x + w, y + 6); cout << char(180);   
    gotoXY(x + 16, y + 6 + 1); getline(cin, tempTel);

    if(this->checkIDCard(tempIDCard) == true){
        gotoXY(x - 5, y + 10);
        cout << "Error: The identity card number matches the registered account. Please re-enter!";
        gotoXY(x - 5, y + 11);
        SetColor(72);
        system("pause");
        system("cls");
        goto INFOR;  
    }

    gotoXY(x + 20, y + 10);
    cout << "Sign in successfully!";
    gotoXY(x + 17, y + 11);
    SetColor(72);
    system("pause");

    user.setID(tempID);
    user.setUsername(tempUsername);
    user.setPassword(tempPassword);
    user.setName(tempName);
    user.setIDCard(tempIDCard);
    user.setAddress(tempAddress);
    user.setTel(tempTel);
    
    this->insertLast(user);
    
    this->saveUsers();
    return;
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
    SetColor(15);
    system("cls");

    string tempUsername, tempPassword;
    
    int x = 30, y = 5, w = 40, h = 2;
    box(x, y - 3, w, h, 14, 1, 14, "************* USER SIGN IN ************");
    box(x, y, w, h, 15, 1, 15, " Username: ");
    gotoXY(x + 12, y + 1); getline(cin, tempUsername); 
    keDuoi(x, y + 2, w, h, 15, 1, 15, " Password: ");
    gotoXY(x, y + 2); cout << char(195);   
    gotoXY(x + w, y + 2); cout << char(180);   
    gotoXY(x + 12, y + 2 + 1); enterPassword(tempPassword);

    if(this->checkSignIn(user, tempUsername, tempPassword) == false){
        gotoXY(x - 5, y + 6);
        cout << "Error: Username or password is not correct! Please enter again!";
        gotoXY(x - 5, y + 7);
        SetColor(72);
        system("pause");
        system("cls");
        this->signIn(user);
    }else{
        gotoXY(x + 9, y + 6);
        cout << "Sign in successfully!\n";
        gotoXY(x + 6, y + 7);
        SetColor(72);
        system("pause");
        return;
    }
}

void ListUserAccount::getUserInforByID(){
    string tempID;
    cout << "Enter ID of user account: ";
    getline(cin, tempID);

    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == tempID){
            this->get(i).printInfor();
            return;
        }
    }

    if(this->checkID(tempID) == false){
        cout << "There is not this user account in the system.\n";
        return;
    }
}

void ListUserAccount::removeUserByID(const string &ID){
    Node<Account> *current = this->head;
    while(current != NULL){
        if(current->data.getID() == ID){
            this->remove(current);
            break;
        }else{
            current = current->next;
        }
    }
    this->saveUsers();
}

#endif
