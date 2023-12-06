#include "List.h"

#ifndef LIST_CPP
#define LIST_CPP

template<class T>
List<T>::List(){
    this->head = NULL;
}

template<class T>
List<T>::~List(){
    Node<T> *current = this->head;
    while(current != NULL){
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

template<class T>
int List<T>::length(){
    int len = 0;
    Node<T> *temp = this->head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

template<class T>
bool List<T>::isEmpty(){
    return this->head == NULL;
}

template<class T>
T List<T>::get(int i){
    if(this->head == NULL){
        cout << "Error: Empty list";
    }else if(i >= this->length() || i < 0){
        cout << "Error: Index is out of bound";
    }
    
    if(i == 0){
        return this->head->data;
    }

    int count = 0;
    T res;
    Node<T> *temp = this->head;
    while(temp != NULL){
        if(count++ == i){
            res = temp->data;
            break;
        }
        temp = temp->next;
    }
    return res;
}

template<class T>
void List<T>::insertFront(const T &data){
    Node<T> *newNode = new Node<T>(data);
    newNode->next = this->head;
    if(this->head != NULL){
        this->head->prev = newNode;
    }
    this->head = newNode;
}

template<class T>
void List<T>::insertLast(const T &data){
    Node<T> *newNode = new Node<T>(data);

    Node<T> *temp = this->head;

    if(temp == NULL){
        this->head = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}

template<class T>
void List<T>::insertAfterNode(const T &data, Node<T> *prevNode){
    if(prevNode == NULL){
        cout << "Error: Can not insert after null";
        return;
    }

    Node<T> *newNode = new Node<T>(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
    
}

template<class T>
void List<T>::remove(Node<T> *delNode){
    if(delNode == NULL || this->head == NULL){
        cout << "Error: Can not remove null";
        return;
    }
    
    if(delNode == this->head){
        this->head = delNode->next;
    }
    if(delNode->next != NULL){
        delNode->next->prev = delNode->prev;
    }
    if(delNode->prev != NULL){
        delNode->prev->next = delNode->next;
    }

    delete delNode;
}

#endif