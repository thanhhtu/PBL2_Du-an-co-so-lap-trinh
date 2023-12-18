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

    if(this->length() == 0){
        this->numOfUser = 0;
        f << this->numOfUser << "\n";
        return;
    }

    f << this->numOfUser << "\n";

	this->get(0).saveAccount(f);
    for(int i = 1; i < this->length(); i++){
		f << endl;
		this->get(i).saveAccount(f);
	}

    f.close();
}

void ListUserAccount::printInforUsers(){
    int x1 = 30, y1 = 5, w1 = 100, h1 = 2;
    for(int i = 0; i < this->length(); i++){
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
        gotoXY(x1, y1);
        for (int J = 1; J < 5; J++){
            gotoXY(x1 + (J * 20), y1);
            cout << char(197);
            gotoXY(x1 + (J * 20), y1 + 2);
            cout << char(193);
        }
    }
    
    int y2 = 8;
    for(int i = 0; i < this->length(); i++){
        gotoXY(x1 + 1, y2);
        this->get(i).printInfor();
        y2 += 2;
        for(int J = 0; J < 5; J++){
            gotoXY(x1 + (J * 20), y2 - 2);
            cout << char(179);
        }
    }
    gotoXY(x1, y2);
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

    int x = 50, y = 5, w = 45, h = 2;
    box(x, y - 3, w, h, 14, 1, 14, "*********** USER SIGN UP ************");

    box(x, y, w, h, 15, 1, 15, " Username: ");
    gotoXY(x + 12, y + 1); getline(cin, tempUsername);

    box(x, y + 2, w, h, 15, 1, 15, " Password: ");
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
    
    if(isEmptyNoWhitespace(tempUsername) == true || isEmptyNoWhitespace(tempPassword) == true){
        gotoXY(x - 5, y + 6);
        cout << "Error: Username and password can not be empty. Please enter again!";
        gotoXY(x - 5, y + 7);
        SetColor(72);
        system("pause");
        system("cls");
        this->signUp(user);     	
	}

INFOR:
    system("cls");
    x = 45, y = 5, w = 60, h = 2;
    box(x, y - 3, w, h, 14, 1, 14, "*************** USER INFORMATION FORM ****************");

    box(x, y, w, h, 15, 1, 15, " Full name: ");
    gotoXY(x + 13, y + 1); getline(cin, tempName);

    box(x, y + 2, w, h, 15, 1, 15, " ID card number: ");
    gotoXY(x, y + 2); cout << char(195);   
    gotoXY(x + w, y + 2); cout << char(180);   
    gotoXY(x + 18, y + 2 + 1); getline(cin, tempIDCard);

    box(x, y + 4, w, h, 15, 1, 15, " Address: ");
    gotoXY(x, y + 4); cout << char(195);   
    gotoXY(x + w, y + 4); cout << char(180);   
    gotoXY(x + 11, y + 4 + 1); getline(cin, tempAddress);

    box(x, y + 6, w, h, 15, 1, 15, " Phone number: ");
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
    
    if(isEmptyNoWhitespace(tempName) == true  || isEmptyNoWhitespace(tempIDCard) == true || isEmptyNoWhitespace(tempAddress) == true || isEmptyNoWhitespace(tempTel) == true){
        gotoXY(x + 2, y + 10);
        cout << "Error: The information can not be empty. Please re-enter!";
        gotoXY(x + 2, y + 11);
        SetColor(72);
        system("pause");
        system("cls");
        goto INFOR;     	
	}
	
    gotoXY(x + 20, y + 10);
    cout << "Sign up successfully!";
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
    system("cls");
    SetColor(15);

    string tempUsername, tempPassword;
    
    int x = 55, y = 5, w = 40, h = 2;
    box(x, y - 3, w, h, 14, 1, 14, "************* USER SIGN IN ************");
    box(x, y, w, h, 15, 1, 15, " Username: ");
    gotoXY(x + 12, y + 1); getline(cin, tempUsername); 
    box(x, y + 2, w, h, 15, 1, 15, " Password: ");
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

void ListUserAccount::getUserInforByID(const string &ID, int x, int y, int w, int h){
    for(int i = 0; i < this->length(); i++){
        if(this->get(i).getID() == ID){
            box(x, y, w, h, 15, 1, 15, "           USER INFORMATION");
            box(x, y + 2, w, h, 15, 1, 15, "   Account ID   :");
            box(x, y + 4, w, h, 15, 1, 15, "    Full name   :");
            box(x, y + 6, w, h, 15, 1, 15, " ID card number :");
            box(x, y + 8, w, h, 15, 1, 15, "     Address    :");
            box(x, y + 10, w, h, 15, 1, 15, "  Phone number  :");
            for(int j = 1; j < 6; j++){
                gotoXY(x, y + 2 * j); cout << char(195);
                gotoXY(x + w, y + 2 * j); cout << char(180);
            }
            gotoXY(x + 20, y + 2 + 1); cout << this->get(i).getID();
            gotoXY(x + 20, y + 4 + 1); cout << this->get(i).getName();
            gotoXY(x + 20, y + 6 + 1); cout << this->get(i).getIDCard();
            gotoXY(x + 20, y + 8 + 1); cout << this->get(i).getAddress();
            gotoXY(x + 20, y + 10 + 1); cout << this->get(i).getTel();
            return;
        }
    }

    if(this->checkID(ID) == false){
        gotoXY(x, y); cout << "There is not this user account in the system.\n";
        return;
    }
}

void ListUserAccount::removeUserByID(const string &ID){
    Node<Account> *current = this->head;
    if(current == NULL){
        return;
    }
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