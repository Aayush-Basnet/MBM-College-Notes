#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
       void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode; } }
     void remove(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
         if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;  }
     
    Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            cout << "Element not found!" << endl;
        }
    }


    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);
    linkedList.display();
    linkedList.remove(20);
    linkedList.display();
     return 0;
}

