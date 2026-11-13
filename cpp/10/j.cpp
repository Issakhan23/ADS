#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> worked(n+1, false);
    vector<int> parent(n+1, 0), children(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        if (worked[i]) continue;
        queue<int> q;
        worked[i] = true;
        q.push(i);

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < adj[v].size(); ++i) {
                int u = adj[v][i];
                if (!worked[u]) {
                    worked[u] = true;
                    parent[u] = v;
                    children[v]++;
                    q.push(u);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == 0) {
            ans++;
        } else if (children[i] > children[parent[i]]) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}