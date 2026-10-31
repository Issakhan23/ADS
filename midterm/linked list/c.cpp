
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
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

    int p, x;
    cin >> p >> x;

    Node* newNode = new Node(x);

    if (p == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;

        for (int i = 0; i < p - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
