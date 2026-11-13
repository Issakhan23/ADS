#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int t, k;
    cin >> t >> k;

    vector<bool> worked(n + 1, false);
    queue<int> bfs;
    bfs.push(t);
    worked[t] = true;

    while(!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();

        for (int c : adj[cur]) {
            if(!worked[c]) {
                worked[c] = true;
                bfs.push(c);
            }
        }
    }

    if (worked[k]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}