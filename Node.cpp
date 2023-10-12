#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Node.h"

#ifndef NODE_CPP
#define NODE_CPP
template<class T>
Node<T>::Node(){
    this->prev = NULL;
    this->next = NULL;
}

template<class T>
Node<T>::Node(const Node<T> &n){
    this->data = n.data;
    this->prev = NULL;
    this->next = NULL;
}

template<class T>
Node<T>::Node(const T &data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

template<class T>
Node<T>::~Node(){

}

#endif