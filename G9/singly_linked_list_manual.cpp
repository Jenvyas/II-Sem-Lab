#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main(){
    int running = 1;
    while(running) {
        SinglyLinkedList<int> list;
        int list_size;
        int element;
        cout << "Enter the length of the list.\n";
        cin >> list_size;
        cout << "Enter the list elements(integers) seperated by spaces.\n";
        for (int i = 0; i < list_size; i++) {
            cin >> element;
            list.push_back(element);
        }
        cout << (list.duplicate_check() ? "The list had duplicates\n" : "There were no duplicates in the list\n") << '\n';
        cout << "Input 0 to exit. Input 1 to run again.\n";
        cin >> running;
    }
}