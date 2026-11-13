#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>  d(n+1, -1);
    for (int i = 0; i < q; ++i) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            if (d[k] != 0) {
                queue<int> bfs;
                d[k] = 0;
                bfs.push(k);

                while(!bfs.empty()) {
                    int cur = bfs.front();
                    bfs.pop();

                    for (int c : adj[cur]) {
                        if (d[c] == -1 || d[c] > d[cur]+1) {
                            d[c] = d[cur] + 1;
                            bfs.push(c);
                        }
                    }
                }
            }
        }
        else {
            cout << d[k] << endl;
        }
    }

    return 0;
}