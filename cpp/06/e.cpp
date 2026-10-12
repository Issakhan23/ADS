#include <iostream>

using namespace std;

void quickSort(int v[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int p = v[l + (r - l) / 2];
    while (i <= j) {
        while (i <= r && v[i] > p) i++;
        while (j >= l && v[j] < p) j--;

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
    int n, m;
    cin >> n >> m;
    int v[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        int col[100];
        for (int i = 0; i < n; ++i) {
            col[i] = v[i][j];
        }
        quickSort(col, 0, n-1);
        for (int i = 0; i < n; ++i) {
            v[i][j] = col[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}