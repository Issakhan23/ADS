
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

bool compare(Student a, Student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }

    return a.name < b.name;
}

void quickSort(vector<Student>& a, int l, int r) {
    int i = l;
    int j = r;

    Student p = a[l + (r - l) / 2];

    while (i <= j) {
        while (compare(a[i], p)) {
            i++;
        }

        while (compare(p, a[j])) {
            j--;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) {
        quickSort(a, l, j);
    }

    if (i < r) {
        quickSort(a, i, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Student> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].score;
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].name << " " << a[i].score << endl;
    }

    return 0;
}
