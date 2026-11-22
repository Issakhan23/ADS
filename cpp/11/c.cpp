#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Edge{
    int a, b;
    long long cost;
};

bool cmp(Edge a, Edge b) {return a.cost < b.cost;}

vector<int> p, sz;

int findset(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = findset(p[v]);
    }
}

bool unite(int a, int b) {
    a = findset(a);
    b = findset(b);

    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<Edge> edge;
    for (int i = 0; i < m; ++i) {
        string t;
        int a, b, c;

        cin >> t >> a >> b >> c;
        long long cost;

        if (t == "big") {
            cost = x * c;
        } else if (t == "small") {
            cost = y * c;
        } else {
            cost = min(x, y) * c;
        }
        edge.push_back({a, b, cost});
    }

    sort(edge.begin(), edge.end(), cmp);
    p.resize(n + 1);
    sz.resize(n + 1);

    for (int i = 1; i <= n; ++i) p[i] = i;
    long long ans = 0;

    for (int i = 0; i < m; ++i) {
        if (unite(edge[i].a, edge[i].b)) ans += edge[i].cost;
    }
    cout << ans << endl;

    return 0;
}