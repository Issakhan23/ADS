
#include <iostream>
#include <vector>

using namespace std;

long long binaryS(long long m) {
    long long l = 0;
    long long r = 1000000000;
    long long ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (mid == 0 || mid <= m / mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        long long m;
        cin >> m;

        cout << binaryS(m) << endl;
    }

    return 0;
}
