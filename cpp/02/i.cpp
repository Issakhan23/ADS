#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
    Node (string d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void add_front(string data) {
    Node* newNode =new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    cout << "ok" << endl;
}

void add_back (string data) {
    Node* newNode = new Node(data);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    cout << "ok" << endl;

}

void erase_front() {
    if (head == nullptr) {
        cout << "error" << endl;
    return;
    }
    cout << head->data << endl;
    Node* temp = head;
    head = head -> next;
    if (head != nullptr) {
        head -> prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

void erase_back() {
    if (tail == nullptr) {
        cout << "error" << endl;
        return;
    }
    cout << tail->data << endl;
    Node* temp = tail;
    tail = tail -> prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void front() {
    if (head == nullptr) {
        cout << "error" << endl;
    } else {
        cout << head -> data << endl;
    }
}

void back() {
    if (tail == nullptr) {
        cout << "error" << endl;
    } else {
        cout << tail -> data << endl;
    }
}

void clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current -> next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    cout << "ok" << endl;
}

int main() {
    string command;
    while (cin >> command) {
        if (command == "add_front") {
            string data;
            cin >> data;
            add_front(data);
        } else if (command == "add_back") {
            string data;
            cin >> data;
            add_back(data);
        } else if (command == "erase_front") {
            erase_front();
        } else if (command == "erase_back") {
            erase_back();
        } else if (command == "front") {
            front();
        } else if (command == "back") {
            back();
        } else if (command == "clear") {
            clear();
        } else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}