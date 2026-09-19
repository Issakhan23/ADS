#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;


    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        Node* toDelete = current->next;

        current->next = toDelete->next;

        delete toDelete;

        current = current->next;
    }

    current = head;

    while (current != nullptr) {
        cout << current->data;

        if (current->next != nullptr)
            cout << " ";

        current = current->next;
    }

    return 0;
}