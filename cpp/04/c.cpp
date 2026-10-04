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

Node* find(Node* root, int x) {
    if(root -> val == x) {
        return root;
    } 
    if (x < root->val) {
        return find(root->left, x);
    } else {
        return find(root->right, x);
    }
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root -> val << " ";
    preorder(root->left);
    preorder(root->right);
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
    int k;
    cin >> k;

    Node* node = find(root, k);
    preorder(node);
    return 0;
}