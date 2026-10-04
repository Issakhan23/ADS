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

vector<int> levelC;

void countL(Node* root, int level) {
    if (root == nullptr) {
        return;
    } 
    levelC[level]++;
    countL(root -> left, level+1);
    countL(root -> right, level+1);
}

int main() {
    int n;
    cin >> n;
    vector<Node*> nodes(n+1);

    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            nodes[x] -> left = nodes[y];
        } else {
            nodes[x] -> right = nodes[y];
        }
    }
    levelC.resize(n+1, 0);
    countL(nodes[1], 0);

    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        if (levelC[i] > ans) {
            ans = levelC[i];
        }
    }
    cout << ans << endl;

    return 0;
}