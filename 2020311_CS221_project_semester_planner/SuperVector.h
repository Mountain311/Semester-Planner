#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

template <class N>
class Node {

public:
    N data;
    Node* next;

    Node() {

        next = NULL;

    }

};

template <class V>
class SuperVector {

private:

    Node<V>* head,*rear;
    int Size;

public:

    SuperVector(){
        head = NULL;
        rear = NULL;
        Size = 0;
    }

    int size() {
        return Size;
    }

    void push_back(V Data) {
        if (head == NULL || Size==0) {

            Node<V>* temp = new Node<V>;

            temp->data = Data;
            head = temp;
            rear = head;
            Size++;

        }
        else {

            Node<V>* temp = new Node<V>;

            temp->data = Data;
            rear->next = temp;
            rear = rear->next;
            Size++;

        }
    }

    void stack_push(V Data){

        Node<V>* temp = new Node<V>;

        temp->data = Data;
        temp->next = head;
        head = temp;
        Size++;

    }

    void queue_enqueue(V Data) {

        if (head == NULL ) {

            Node<V>* temp = new Node<V>;

            temp->data = Data;
            head = temp;
            rear = head;
            Size++;

        }
        else {

            Node<V>* temp = new Node<V>;

            temp->data = Data;
            rear->next = temp;
            rear = rear->next;
            Size++;

        }

    }

    V& operator[](int index) {

        //assert(("SuperVector Index Subscript Out of Range", index < Size));

        Node<V>* ptr=head;

        for (int i = 0; i < index; i++) {

            ptr = ptr->next;

        }

        return ptr->data;

    }

    V pop_back(int index){
    
        Node<V>* ptr = head;
        Node<V>* ptr2 ;
        V Data;

        if (index == 0 && ptr != NULL) {

            Data = ptr->data;
            head = head->next;
            free(ptr);

            return Data;

        }
        else if (ptr != NULL && index!=0) {

            for (int i = 0; i < index -1; i++) {

                ptr = ptr->next;

            }

            ptr2 = ptr->next;
            Data = ptr2->data;

            ptr->next = ptr2->next;
            free(ptr2);
            Size--;

            return Data;
        }
        else {

            cout << "The Vector is Empty\n";
            
            return NULL;

        }
    
    }

    V stack_pop() {

        Node<V>* ptr = head;
        V Data;

        if (ptr != NULL) {

            Data = head->data;

            head = ptr->next;
            free(ptr);

            Size--;

            return Data;

        }
        else {

            cout << "The Stack is Empty\n";

            return NULL;

        }

    }

    V queue_dequeue() {

        Node<V>* ptr = head;
        V Data;

        if (ptr != NULL) {

            Data = head->data;

            head = ptr->next;
            free(ptr);

            Size--;

            return Data;

        }
        else {

            cout << "The Queue is Empty\n";

            return NULL;

        }

    }

    V stack_top() {

        if (head != NULL) {

            return head->data;

        }
        else {
            
            cout << "Stack is Empty\n";

            return NULL;

        }

    }

    V queue_front() {

        if (head != NULL) {

            return head->data;

        }
        else {

            cout << "Queue is Empty\n";

            return NULL;

        }

    }

    void clear() {

        Node<V>* temp = head;

        while (head != NULL) {

            temp = head;
            head = head->next;
            free(temp);

        }

        Size = 0;

    }

    void print_vector() {

        Node<V>* ptr = head;

        while (ptr != NULL) {

            cout << ptr->data << endl;
            ptr = ptr->next;

        }

    }

};