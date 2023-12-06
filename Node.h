#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
    public:
        T data;
        Node<T> *prev;
        Node<T> *next;

    public:
        Node();
        Node(const Node<T> &n);
        Node(const T &data);
        ~Node();

};

#endif