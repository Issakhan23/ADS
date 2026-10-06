#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k; 

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            long long x;
            cin >> x;

            if (pq.size() < k) {
                pq.push(x);
                sum += x;
            } else if (x > pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(x);
                sum += x;
            }
        } else if (cmd == "print") {
            cout << sum << endl;
        }
    }

    return 0;
}