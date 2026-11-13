#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int n, vector<vector<pair<int, int>>>& a, int d) {
    vector<int> k(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (auto e : a[i]) {
            if (e.second != d) k[e.first]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (k[i] == 0) q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;

        for (auto e : a[u]) {
            int v = e.first;
            if (e.second == d) continue;
            k[v]--;
            if (k[v] == 0) q.push(v);
        }
    }
    return cnt == n;
}

bool dfs(int u, vector<vector<pair<int, int>>>& a, vector<int>& c, vector<int>& p, vector<int>& pEdge, vector<int>& cycle) {
    c[u] = 1;
    for (auto e : a[u]) {
        int v = e.first, id = e.second;
        if (c[v] == 0) {
            p[v] = u;
            pEdge[v] = id;
            if (dfs(v, a, c, p, pEdge, cycle)) return true;
        } else if (c[v] == 1) {
            cycle.push_back(id);
            int x = u;
            while (x != v) {
                cycle.push_back(pEdge[x]);
                x = p[x];
            }
            return true;
        }
    }
    c[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> a(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back({y, i});
    }

    if (bfs(n, a, -1)) {
        cout << "YES" << endl;
        return 0;
    }

    vector<int> c(n+1, 0), p(n+1, -1), pEdge(n+1, -1), cycle;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            if (dfs(i, a, c, p, pEdge, cycle)) break;
        }
    }

    for (int h : cycle) {
        if (bfs(n, a, h)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}