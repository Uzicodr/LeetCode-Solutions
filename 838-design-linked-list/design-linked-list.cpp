#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int val;

    Node(int val, Node* ptr = nullptr) {
        this->val = val;
        next = ptr;
    }
};

class MyLinkedList {
    Node* head;
    Node* tail;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* temp = head;
        int cnt = 0;
        while (temp) {
            if (cnt == index) {
                return temp->val;
            }
            temp = temp->next;
            cnt++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val, head);
        head = newnode;
        if (tail == nullptr) {
            tail = newnode; 
        }
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val, nullptr);
        if (tail) {
            tail->next = newnode;
            tail = newnode;
        } else {
            head = tail = newnode;
        }
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp) { 
            Node* newnode = new Node(val, temp->next);
            temp->next = newnode;

            if (newnode->next == nullptr) {
                tail = newnode; 
            }
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0 && head) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp && temp->next) {
            Node* to_delete = temp->next;
            temp->next = to_delete->next;
            if (temp->next == nullptr) {
                tail = temp;
            }
            delete to_delete;
        }
    }
};

