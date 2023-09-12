#pragma once
#include <cstddef>
#include <sstream>

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(T init_data);
};

template <class T>
class SinglyLinkedList{
private:
    Node<T>* head;

public:
    SinglyLinkedList();

    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList &old_list);

    void push_back(T data);

    Node<T>* begin();

    bool duplicate_check();
};

template <typename T>
Node<T>::Node(T init_data){
    data = init_data;
    next = NULL;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    head = NULL;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    Node<T>* current_node = head;  
    //goes through each node starting form the list head and deletes them.  
    while( current_node != NULL ) {
        Node<T>* next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
    head = NULL;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &old_list){
    head=NULL;

    Node<T>* current_node = old_list.head;
    while( current_node != NULL ) {
        this->push_back(current_node->data);
        current_node = current_node->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::push_back(T data)
{
    Node<T>* new_node = new Node<T>(data);
        
    // if the list is empty sets the added value as the list head
    if (head==NULL) {
        head = new_node;
        return;
    }

    Node<T>* temp = head;

    //iterates through all nodes until it reaches the last one
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

template <typename T>
Node<T>* SinglyLinkedList<T>::begin() {
    return head;
}

template <typename T>
bool SinglyLinkedList<T>::duplicate_check() {
    // creates a loop going through all the nodes, for each node
    // it starts another loop that checks all the next nodes for duplicates
    for (Node<T>* node1 = this->begin(); node1 != NULL; node1=node1->next)
    {
        for (Node<T>* node2=node1->next; node2 != NULL; node2 = node2->next)
        {
            if (node2->data==node1->data) return true;
        }
    }
    return false;
}