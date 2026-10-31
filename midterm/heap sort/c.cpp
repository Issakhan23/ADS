#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if (first != second) {
            pq.push(first - second);
        }
    }

    if (pq.empty()) {
        cout << 0;
    }
    else {
        cout << pq.top();
    }

    return 0;
}