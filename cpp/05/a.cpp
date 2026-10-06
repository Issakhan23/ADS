#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pq.push(v[i]);
    }

    long long ans;

    while (pq.size() > 1) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        long long s = x + y;
        ans += s;
        pq.push(s);
    }

    cout << ans - 1 << endl;


    return 0;
}