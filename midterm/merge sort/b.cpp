#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < n) {
        result.push_back(a[i]);
        i++;
    }

    while (j < m) {
        result.push_back(b[j]);
        j++;
    }

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}