#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> fun(int start, vector<vector<pair<int, int>>>& g) {
    vector<long long> d(g.size(), 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    d[start] = 0;
    q.push({0, start});
    while (!q.empty()) {
        long long cost = q.top().first;
        int v = q.top().second;
        q.pop();
        if (cost != d[v]) continue;

        for (int i = 0; i < g[v].size(); ++i) {
            int o = g[v][i].first;
            int w = g[v][i].second;

            if (d[v] + w < d[o]) {
                d[o] = d[v] + w;
                q.push({d[o], o});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;
    s--;
    a--;
    b--;
    f--;

    vector<long long> ds = fun(s, g), da = fun(a, g), db = fun(b, g);
    long long first = ds[a] + da[b] + db[f], second = ds[b] + db[a] + da[f];
    long long ans = min(first, second);

    if (ans >= 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}