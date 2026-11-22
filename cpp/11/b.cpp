#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    long long sum = 0;
    int mn;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        if (i == 0 || v[i] < mn) mn = v[i];
    }
    long long ans = sum + (n - 2)*mn;
    cout << ans << endl;

    return 0;
}