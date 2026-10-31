#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        int left = 0;
        int right = n - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (a[mid] >= x) {
                answer = mid + 1;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}