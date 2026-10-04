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

void level(Node* root, int l, vector<int>& sums) {
    if (root == nullptr) {
        return;
    }
    if (l == sums.size()) {
        sums.push_back(0);
    }
    sums[l] += root -> val;
    level(root -> left, l+1, sums);
    level(root -> right, l+1, sums);
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

    vector<int> sums;
    level(root, 0, sums);
    cout << sums.size() << endl;
    for (int i = 0; i < sums.size(); ++i) {
        cout << sums[i] << " ";
    }

    return 0;
}