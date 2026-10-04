#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int val) {
        this -> val = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val <= node -> val) {
        node -> left = insert(node -> left, val);
    } else {
        node -> right = insert(node -> right, val);
    }
    return node;
}

int main() {
    int n, k;
    cin >> n >> k;
    Node* root = nullptr;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        root = insert(root, v[i]);
    }
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;

        Node* cur = root;
        bool ok = true;

        for (char c : s) {
            if (c == 'L') {
                if (cur -> left == nullptr) {
                    ok = false;
                    break;
                }
                cur = cur -> left;
            } else {
                if (cur -> right == nullptr) {
                    ok = false;
                    break;
                }
                cur = cur -> right;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }



    return 0;
}