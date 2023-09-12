#include <stdio.h>

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(T init_data) {
        data = init_data;
        next = NULL;
    }
};

template <class T>
class ReverseSinglyLinkedList{
private:
    Node<T>* head;

public:
    ReverseSinglyLinkedList() {
        head = NULL;
    }

    ~ReverseSinglyLinkedList(){
        Node<T>* current_node = head;    while( current_node != NULL ) {
            Node<T>* next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
        head = NULL;
    }

    ReverseSinglyLinkedList(const ReverseSinglyLinkedList<T> &old_list){
        head=NULL;

        Node<T>* current_node = old_list.head;
        while( current_node != NULL ){
            this->push_back(current_node->data);
            current_node = current_node->next;
        }
    }

    void push_back(T data)
    {
        Node<T>* new_node = new Node<T>(data);
            
        if (head==NULL) {
            head = new_node;
            return;
        }

        new_node->next = head;
        head = new_node;
    }

    Node<T>* begin(){
        return head;
    }
};

int main(){
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);
    
    ReverseSinglyLinkedList<char*>* alphabetic_list[26];
    for (int i = 0; i < 26; i++)
    {
        ReverseSinglyLinkedList<char*>* list = new ReverseSinglyLinkedList<char*>;
        alphabetic_list[i] = list;
    }
    
    char* s = new char[255];
    scanf("%s",s);
    
    while (!feof(stdin))
    {
        int index;
        if(s[0]>=65&&s[0]<=90) index = s[0]-65;
        else if(s[0]>=97&&s[0]<=122) index = s[0]-97;
        alphabetic_list[index]->push_back(s);
        s = new char[255];
        scanf("%s",s);
    }

    int count(0);
    for (int i = 0; i < 26; i++)
    {
        Node<char*>* iter = alphabetic_list[i]->begin();
        while(iter!=NULL){
            if (count==0) count = 1;
            printf("%s ",iter->data);
            iter = iter->next;
        }
    }
    if (count==0) printf("%s","nothing");
    
    return 0;
}