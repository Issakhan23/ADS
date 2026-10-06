#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pq.push(v[i]);
    }

    int op = 0;
    while (pq.top() < k) {
        if (pq.size() < 2) {
            cout << -1;
            return 0;
        }
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();

        long long t = x + 2 * y;
        pq.push(t);
        op++;
    }
    cout << op << endl;

    return 0;
}