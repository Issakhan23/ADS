#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n;
    cin >> n;
    vector<Edge> edge;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            if (w != 100000) edge.push_back({i, j, w});
        }
    }

    vector<long long> d(n, 0);
    vector<int> p(n, -1);
    int x = -1;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < edge.size(); ++j) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                p[v] = u;
                x = v;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
        return 0;
    }
    int y = x;
    for (int i = 0; i < n; ++i) y = p[y];
    vector<int> cycle;
    int cur = y;

    for (int i = 0; i <= n; ++i) {
        cycle.push_back(cur);
        cur = p[cur];

        if (cur == y) {
            cycle.push_back(y);
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    cycle.pop_back();
    int pos = 0;
    for (int i = 0; i < cycle.size(); ++i) {
        if (cycle[i] > cycle[pos]) pos = i;
    }
    vector<int> temp;
    for (int i = 0; i < cycle.size(); ++i) temp.push_back(cycle[(pos+i)%cycle.size()]);
    temp.push_back(temp[0]);
    cycle = temp;

    cout << "YES" << endl;
    cout << cycle.size() << endl;
    for (int i = 0; i < cycle.size(); ++i) cout << cycle[i]+1 << " ";

    return 0;
}