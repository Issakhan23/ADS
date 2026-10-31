
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int grade;
};

void merge(vector<Student>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Student> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = a[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].grade <= R[j].grade) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Student>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

int main() {
    int n;
    cin >> n;

    vector<Student> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].grade;
    }

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].name << endl;
    }

    return 0;
}
