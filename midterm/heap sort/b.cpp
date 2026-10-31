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

    bool isHeap = true;

    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[i] > a[left]) {
            isHeap = false;
        }

        if (right < n && a[i] > a[right]) {
            isHeap = false;
        }
    }

    if (isHeap) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}