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
    if (x < root->val) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

int cTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int ans = 0;
    if (root -> left != nullptr && root -> right != nullptr) {
        ans++;
    }
    ans += cTriangles(root->left);
    ans += cTriangles(root->right);
    return ans; 
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
    cout << cTriangles(root);

    return 0;
}