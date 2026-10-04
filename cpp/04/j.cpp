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

void inorder(Node* root, int& k, int& ans) {
    if (root == nullptr){
        return;
    }
    inorder(root -> left, k, ans);
    k--;
    if (k == 0) {
        ans = root -> val;
        return;
    }
    inorder(root -> right, k, ans);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << -1;
        return 0;
    }

    Node* root = nullptr;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        root = insert(root, v[i]);
    }
    int ans = -1;
    inorder(root, k, ans);
    cout << ans;

    return 0;
}