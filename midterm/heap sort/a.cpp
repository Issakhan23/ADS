
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }

    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
