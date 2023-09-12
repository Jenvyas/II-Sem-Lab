#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct list_ext : public std::list<T> {
    bool duplicate_check() {
        // creates a loop going through all the elements, for each element
        // it starts another loop that checks all the next elements for duplicates
        typename std::list<T>::const_iterator it1;
        for (it1 = this->begin(); it1 != this->end(); ++it1) {
            typename std::list<T>::const_iterator it2=it1;
            ++it2;
            for (; it2 != this->end(); ++it2) {
                if ( *it2 == *it1 ) return true;
            }
        }
        return false;
    }
};

int main(){
    int running = 1;
    while(running) {
        list_ext<int> list;
        int list_size;
        int element;
        bool correct = true;
        cout << "Enter the length of the list.\n";
        try {
            //throws an error if the list size is entered incorrectly
            if(!(cin >> list_size))
                throw("Length must be an integer.");
            //throws an error if list size is negative
            if(list_size<0)
                throw("Length must be a positive integer");
        } catch(char const* e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << e << '\n';
            correct = false;
            continue;
        }
        cout << "Enter the list elements(integers) seperated by spaces.\n";
        for (int i = 0; i < list_size; i++) {
            //throws an error if a wrong object type(not an int) gets entered.
            //error gets caught and then the input buffer gets flushed
            try {
                if(!(cin >> element))
                    throw("Element "+to_string(i+1)+" was not an integer");
                list.push_back(element);
            } catch(string e) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cerr << e << '\n';
                correct = false;
                break;
            }
        }
        if (correct)
            cout << (list.duplicate_check() ? "The list had duplicates\n" : "There were no duplicates in the list\n") << '\n';
        
        cout << "Input 0 to exit. Input 1 to run again.\n";
        cin >> running;
    }
}