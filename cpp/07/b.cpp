#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {L[i] = arr[l+i];}
    for (int i = 0; i < n2; ++i) {R[i] = arr[mid + i + 1];}
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    mergeSort(arr1, 0, n-1);
    mergeSort(arr2, 0, m-1);

    vector<int> marr(n+m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            marr[k] = arr1[i];
            i++;
        } else {
            marr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        marr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m) {
        marr[k] = arr2[j];
        j++;
        k++;
    }

    for (int i = 0; i < n + m; ++i) {
        cout << marr[i] << " ";
    }
    cout << endl;

    return 0;
}