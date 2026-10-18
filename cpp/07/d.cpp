#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {L[i] = arr[l + i];}
    for (int i = 0; i < n2; ++i) {R[i] = arr[mid + i + 1];}

    int i = 0, j = 0, k = l;
    long long count = 0;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            count += n1 - i;
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
    return count;
}

long long mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    long long count = 0;
    count += mergeSort(arr, l, mid);
    count += mergeSort(arr, mid + 1, r);
    count += merge(arr, l, mid, r);
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << mergeSort(arr, 0, n-1);

    return 0;
}