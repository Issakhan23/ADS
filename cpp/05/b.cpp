#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long> pq;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pq.push(v[i]);
    }

    while (pq.size() > 1) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();

        if (x != y) {
            pq.push(x - y);
        }
    }

    if (pq.empty()) {
        cout << 0;
    } else {
        cout << pq.top();
    }

    return 0;
}