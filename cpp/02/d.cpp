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
    for (int i = 0; i < n; ++i) {
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
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    current = head;
    while (current != nullptr) {
        cout << current -> data;
        if (current -> next != nullptr) {
            cout << " ";
        }
        current = current -> next;
    }
    cout << endl;

    return 0;
}