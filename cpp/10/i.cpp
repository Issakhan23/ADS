#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        d[v]++;
    }

    vector<int> q;
    for (int j = n; j >= 1; --j) {
        if (d[j] == 0) q.push_back(j);
    }

    vector<int> order;
    while (!q.empty()) {
        int v = q.back();
        q.pop_back();
        order.push_back(v);

        for (int i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i];
            d[u]--;
            if (d[u] == 0) q.push_back(u);
        }
    }

    if (order.size() < n) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < n; ++i) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}