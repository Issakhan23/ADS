#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node (string val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    int N, k;
    cin >> N >> k;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    Node* current = head;
    for (int j = 1; j < k; ++j) {
        current = current -> next;
    }

    Node* newHead = current -> next;
    current -> next = nullptr;
    tail -> next = head;
    head = newHead;
    current = head;
    while (current != nullptr) {
        cout << current -> data;
        if (current -> next != nullptr) {
            cout << " ";
        }
        current = current -> next;
    }


    return 0;
}