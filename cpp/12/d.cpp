#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<long long> d(n, 1e18);
    vector<bool> worked(n, false);

    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!worked[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        worked[v] = true;
        for (int j = 0; j < n; ++j) {
            if (!worked[j]) {
                long long h = abs(x[v] - x[j]) + abs(y[v] - y[j]);
                d[j] = min(d[j], max(d[v], h));
            }
        }
    }
    cout << d[n - 1] << endl;

    return 0;
}