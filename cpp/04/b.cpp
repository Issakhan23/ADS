#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int x) {
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root -> val) {
        root -> left = insert(root -> left, x);
    } else {
        root -> right = insert(root -> right, x);
    }
    return root;
}

int size(Node* root) {
    if (root == nullptr){
        return 0;
    }
    return 1 + size(root->left) + size(root -> right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        root = insert(root, v[i]);
    }
    int x;
    cin >> x;
    Node* cur = root;
    while (cur -> val != x) {
        if (x < cur->val) {
            cur = cur -> left;
        } else {
            cur = cur -> right;
        }
    }
    cout << size(cur) << endl; 

    return 0;
}