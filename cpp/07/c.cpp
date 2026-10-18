#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int>& row) {
    int s = 0;
    for (int x : row) {
        s += x;
    }
    return s;
}

bool worked(vector<int>& a, vector<int>& b) {
    int sa = sum(a);
    int sb = sum(b);

    if (sa != sb) return sa > sb;
    return a<=b;
}

void merge(vector<vector<int>>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<vector<int>> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {L[i] = arr[l + i];}
    for (int i = 0; i < n2; ++i) {R[i] = arr[mid + i + 1];}

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (worked(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}