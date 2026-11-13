#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int l = 2*max(a, b);

    vector<int> d(l+1, -1);
    vector<int> p(l+1, -1);
    queue<int> q;

    q.push(a);
    d[a] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == b) break;

        int next = x*2;

        if (next <= l && d[next] == -1) {
            d[next] = d[x] + 1;
            p[next] = x;
            q.push(next);
        }

        next = x - 1;

        if (next >= 1 && d[next] == -1) {
            d[next] = d[x] + 1;
            p[next] = x;
            q.push(next);
        }
    }

    vector<int> path;
    int cur = b;

    while(cur != a && cur != -1) {
        path.push_back(cur);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
    cout << d[b] << endl;
    for (int i = 0; i < path.size(); ++i) cout << path[i] << " ";


    return 0;
}