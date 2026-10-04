#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int x){
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root -> val) {
        root -> left = insert(root->left, x);
    } else if (x > root -> val) {
        root -> right = insert(root -> right, x);
    }
    return root;
}

int ans = 0;
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftH = height(root -> left);
    int rightH = height(root -> right);
    int distance = leftH + rightH + 1;

    if (distance > ans) {
        ans = distance;
    }
    if (leftH > rightH) {
        return leftH + 1;
    } else {
        return rightH + 1;
    }
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
    height(root);
    cout << ans;

    return 0;
}