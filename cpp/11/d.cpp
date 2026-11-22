#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int a, b, cost;
};

bool cmp(Edge x, Edge y) {return x.cost < y.cost;}

vector<int> p, sz;

int findSet(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = findSet(p[v]);
    }
} 

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Edge> edge;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (i < j) edge.push_back({i, j, x});
        }
    }

    sort(edge.begin(), edge.end(), cmp);
    p.resize(n);
    sz.resize(n, 1);

    for (int i = 0; i < n; ++i) p[i] = i;
    int ans = 0;

    for (int i = 0; i < edge.size(); ++i) {
        if (unite(edge[i].a, edge[i].b)) ans += edge[i].cost;
    }

    cout << ans << endl;

    return 0;
}