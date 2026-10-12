#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& a, int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right)/2];
    while (i <= j) {
        while (i <= right && a[i] < pivot) i++;
        while (j >= left && a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < k; ++j) cin >> b[j];

    if (n > 1) quickSort(a, 0, n-1);
    if (k > 1) quickSort(b, 0, k-1);

    int i = 0, j = 0;

    while (i < n && j < k) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;

    return 0;
}