#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Node.cpp"

#ifndef LIST_H
#define LIST_H

template<class T>
class List{
    protected:
        Node<T> *head;

    public:
        List();
        ~List();

        int length();
        bool isEmpty();
        T get(int i);    //lay ra 1 account trong list

        void insertFront(const T &data);
        void insertLast(const T &data);
        void insertAfterNode(const T &data, Node<T> *prevNode);
        
        void remove(Node<T> *delNode); //delNode: con tro tai vi tri Node muon xoa //dung friend cung duoc

};

#endif