#include <iostream>

using namespace std;

void quickSort(char a[], int l, int r) {
    if (l >= r) return;
    char p = a[l + (r - l)/2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } 
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
} 

int main () {
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    char k;
    cin >> k;

    quickSort(a, 0, n-1);

    for (int i = 0; i < n; ++i) {
        if (a[i] > k) {
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << a[0] << endl;

    return 0;
}