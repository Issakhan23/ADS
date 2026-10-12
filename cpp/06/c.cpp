#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& v, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int p = v[l + (r - l) / 2];
    while (i <= j) {
        while (v[i] < p) i++;
        while (v[j] > p) j--;

        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(v, l, j);
    if (i < r) quickSort(v, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    quickSort(v, 0, n-1);
    int mindif = v[1] - v[0];

    for (int i = 1; i < n - 1; ++i) {
        int dif = v[i+1] - v[i];
        if (dif < mindif) mindif = dif;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (v[i+1] - v[i] == mindif) {
            cout << v[i] << " " << v[i+1] << endl;
        }
    }

    return 0;
}