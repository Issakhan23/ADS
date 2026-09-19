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
    int n, m;
    cin >> n;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head1 == nullptr) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    cin >> m;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;


    for (int j = 0; j < m; ++j) {
        int y;
        cin >> y;
        Node* newNode = new Node(y);
        if (head2 == nullptr) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2 -> next = newNode;
            tail2 = newNode;
        }
    }
    Node* head = nullptr; 
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1 -> data <= head2 -> data) {
            if (head == nullptr) {
                head = head1;
                tail = head1;
            } else {
                tail -> next = head1;
                tail = head1;
            }
            head1 = head1 -> next;
        } else {
            if (head == nullptr) {
                head = head2;
                tail = head2;
            } else {
                tail -> next = head2;
                tail = head2;
            }
            head2 = head2 -> next;
        }
    }
    if (head1 != nullptr) {
        if (head == nullptr) {
            head = head1;
        } else {
            tail -> next = head1;
        }
    }
    if (head2 != nullptr) {
        if (head == nullptr) {
            head = head2;
        } else {
            tail -> next = head2;
        }
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current-> data ;
        if (current -> next != nullptr) {
            cout << " ";
        }
        current = current -> next;

    }
    cout << endl;

    return 0;
}