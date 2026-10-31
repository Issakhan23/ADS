//-k
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        Node* newNode = new Node(v[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* cur = head;

    int k;
    cin >> k;

    while (cur != nullptr) {
        if (cur->val != k) {
            cout << cur->val << " ";
        } 
        cur = cur->next;
    }



    return 0;
} 