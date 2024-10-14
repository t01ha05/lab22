#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the back
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at the front
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void delete_pos(int position) {
        if(!head) return;
        if(position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. node not deleted .\n";
            return;
        }

        if (temp==head) {
            pop_front();
        } else if (temp == tail) {
            pop_back();
        } else {
            temp->prev->next = temp->next;
            temp->prev->prev = temp->prev;
            delete temp;
        }
    }

    void pop_front(){
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else 
            tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if(!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        else 
            head = nullptr;
        delete temp;
    }

    void delete_val(int value){
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data!= value)
            temp = temp->next;
        if(!temp) return;

        if (temp ==head) {
            pop_front();
        } else if (temp == tail) {
            pop_back();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }


        

    
