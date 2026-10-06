#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<long long> pq;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pq.push(v[i]);
    }

    long long ans = 0;

    for (int i = 0; i < k; ++i) {
        long long s = pq.top();
        pq.pop();
        ans += s;
        s--;
        if (s > 0) {
            pq.push(s);
        }
    }
    cout << ans;

    return 0;
}