#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    vector<int> d(n, -1);
    queue<int> q;
    d[0] = 0;
    q.push(0);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            if (d[i] == -1 && a[v][i] != a[0][n - 1]) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    cout << d[n-1] << endl;

    return 0;
}