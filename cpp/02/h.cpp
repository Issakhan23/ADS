#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val) {
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
            tail -> next = newNode;
            tail = newNode;
        }
    }
    Node* currentNode = head;
    int current = head -> data;
    int best = head -> data;
    currentNode = head -> next;

    while (currentNode != nullptr) {
        int x = currentNode -> data;
        current = max(x, current + x);
        best = max(best, current);
        currentNode = currentNode -> next;
    }

    cout << best;

    return 0;
}