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
    if (root == nullptr) return new Node(x);

    if (x < root->val) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

int main() {

    Node* root = nullptr;
    for () {
        cin >> x;
        root = insert(root, x);
    }
    Node* cur = root;
    return 0;
}