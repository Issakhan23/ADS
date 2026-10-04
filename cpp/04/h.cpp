#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node (int x) {
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

void greaterSum(Node* root, int& sum) {
    if (root == nullptr) {
        return;
    }
    greaterSum(root -> right, sum);
    sum += root -> val;
    root->val = sum;
    greaterSum(root -> left, sum);
}

void print(Node* root) {
    if (root == nullptr) {
        return;
    }
    print(root->right);
    cout << root -> val << " ";
    print(root -> left);
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
    int sum = 0;
    greaterSum(root, sum);
    print(root);

    return 0;
}