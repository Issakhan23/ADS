#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> d(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        t[i]--;
    }

    vector<bool> act(n, false);
    vector<long long> ans(n);

    for (int k = 0; k < n; ++k) {
        int h = t[k];
        act[h] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][h]+d[h][j]);
            }
        }
        long long mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (act[i] && act[j]) mx = max(mx, d[i][j]);
            }
        }
        ans[k] = mx;
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << endl; 

    return 0;
}