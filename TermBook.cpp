#include "TermBook.h"

#ifndef TERMBOOK_CPP
#define TERMBOOK_CPP

TermBook::TermBook(){
    interestRates[3] = 0.00825;     //3.3%/nam
    interestRates[6] = 0.0215;      //4.3%/nam
    interestRates[12] = 0.055;      //5.5%/nam
    interestRates[18] = 0.09;        //6.0%/nam
}

TermBook::~TermBook(){

}

int TermBook::getTerm() const{
    return this->term;
}

void TermBook::setTerm(int term){
    this->term = term;
}

void TermBook::setBook(ifstream &f){
    getline(f, this->IDBook, '-');
    getline(f, this->ID, '-');

    string dt;
    getline(f, dt, '-');
    Date tempDate(dt);   //class date tu string dt
    this->setOpeningDate(tempDate);   //copy class tempDate sang class this->date

    string tempTerm;
    getline(f, tempTerm, '-');
    this->term = stoi(tempTerm);

    getline(f, this->money);
}

void TermBook::saveBook(ofstream &f){
    string dt = this->openingDate.dtAsString();    //chuyen class this->date sang string r luu vao string dt

    f << this->IDBook << "-" << this->ID << "-" << dt << "-" << this->term << "-" << this->money;
}

void TermBook::printBook() const{
    int x1 = whereX(); 
    int y1 = whereY();

	cout << "    " << this->IDBook;
	gotoXY(x1 + 23, y1);
    cout << this->openingDate;
    gotoXY(x1 + 48, y1);
    cout << this->getTerm();
    gotoXY(x1 + 64, y1);
    cout << this->money ;
}

float TermBook::interestRate(const Date &currentDate) const{
    if(openingDate.getDayDifference(currentDate) < this->term * 30) return 0;
    
    auto it = interestRates.find(this->term);
    float interest = it->second;
    //Calculate the interest earned
    float interestEarned = stof(this->money) * interest * float(openingDate.getDayDifference(currentDate)) / (float(this->term) * 30);
    return interestEarned; 
}

float TermBook::interest(const Date &currentDate) const{
    //Check if the term of the book has come
    const int z = whereY();
    const int x1 = 35, y1 = z + 4, h1 = 2;
    if(openingDate.getDayDifference(currentDate) < this->term * 30){      //mac dinh 1 thang co 30 ngay
		int w1 = 90;
		box(x1, y1 - 2, w1, h1, 15, 1, 14, "  The first term of this book has not yet come. Are you sure you want to withdraw money?\n\n");
        string text1 = "                                         1. Yes";
        string text2 = "                                         2. No";
        box(x1, y1, 90, h1, 15, 1, 15, text1);
        box(x1, y1 + 2, 90, h1, 15, 1, 15, text2);

    	gotoXY(x1, y1); cout << char(195);
        gotoXY(x1, y1 + 2); cout << char(195); 
    	gotoXY(x1 + 90, y1); cout << char(180);
        gotoXY(x1 +90,  y1 + 2); cout << char(180);

        int choice;
        do{
            gotoXY(whereX() - 50, whereY() + 3);
            SetColor(72);
            cout << "Your choice: ";
            cin >> choice; 
            if(!(choice >= 1 && choice <= 2)){
                gotoXY(whereX() + 50, whereY());
                cout << "Invalid input!! Please choose again.\n";
            }
        }while (!(choice >= 1 && choice <= 2));

        //If the user chooses to withdraw money early, return 0
        if(choice == 1){
            return this->interestRate(currentDate);
        }else if(choice == 2){
            //If the user chooses not to withdraw money, don't calculate interest
            cin.ignore();
            return -1;
        }
    }
    
    return this->interestRate(currentDate);
}
#endif