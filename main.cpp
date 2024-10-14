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
    //delete by position
    void delete_pos(int position) {
        if(!head) return; //list is empty
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
    //delete the head node
    void pop_front(){
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else 
            tail = nullptr;//list became empty
        delete temp;
    }
    //delete tail node
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
    //delete by value
    void delete_val(int value){
        if (!head) return;   //empty list
        Node* temp = head;
        while (temp && temp->data!= value)
            temp = temp->next;
        if(!temp) return; //value not found

        if (temp ==head) {
            pop_front(); //delete head
        } else if (temp == tail) {
            pop_back(); //delete tail
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    //prints list backwards
    void print__reverse() const {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    //destrucvtor
    ~DoublyLinkedList(){
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
//driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    for ( int i = 0; i < size; i++)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);

    cout << "Initial list forward: ";
    list.print();
    cout << "Initial list backward: ";
    list.print__reverse();

    //deleting by postion
    cout << "\nDeleting node at position 2:" << endl;
    list.delete_pos(2);
    list.print();

    //popping front and back
    cout << "Popping front node: " << endl;
    list.pop_front();
    list.print();

    cout << "Popping back node: " << endl;
    list.pop_back();
    list.print();

    cout << "Deleting node with value 42(if exists): "<< endl;
    list.delete_val(42);
    list.print();

    return 0;
}

    
