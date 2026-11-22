#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Seg {
    long long c;
    int l, r;
};

bool cmp(Seg a, Seg b) {return a.c < b.c;}

vector<int> p, sz, nxt;

int findSet(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = findSet(p[v]);
    }
}

int findNext(int v) {
    if (nxt[v] == v) {
        return v;
    } else {
        return nxt[v] = findNext(nxt[v]);
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
    int n, m;
    cin >> n >> m;
    vector<Seg> v(m);
    for (int i = 0; i < m; ++i) cin >> v[i].l >> v[i].r >> v[i].c;
    
    sort(v.begin(), v.end(), cmp);
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    nxt.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        nxt[i] = i;
    }

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int po = findNext(v[i].l);
        while (po < v[i].r) {
            if (unite(po, po+1)) ans += v[i].c;
            nxt[po] = findNext(po + 1);
            po = findNext(po);
        }
    }

    cout << ans << endl;

    return 0;
}