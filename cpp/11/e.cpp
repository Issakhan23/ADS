#include <iostream>
#include <vector>

using namespace std;

vector<int> p, sz;
vector<bool> act;

int findSet(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = findSet(p[v]);
    }
}

void units(int a, int b, int& cnt) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
    cnt--;
}

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

    p.resize(n + 1);
    sz.resize(n + 1, 1);
    act.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) p[i] = i;
    vector<int> ans(n + 1);
    int cnt = 0;

    for (int i = n; i >= 1; --i) {
        ans[i] = cnt;
        act[i] = true;
        cnt++;

        for (int j = 0; j < adj[i].size(); ++j) {
            int v = adj[i][j];
            if (act[v]) units(i, v, cnt);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}