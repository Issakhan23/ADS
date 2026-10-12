#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct date {
    int day, month, year;
};

bool smaller (date a, date b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

void quickSort(vector<date>& d, int l, int r) {
    if (l >= r) return;
    date p = d[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (smaller(d[i], p)) i++;
        while (smaller(p, d[j])) j--;
        if (i <= j) {
            swap(d[i], d[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(d, l, j);
    if (i < r) quickSort(d, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<date> d(n);
    for (int i = 0; i < n; ++i) {
        char dash1, dash2;
        cin >> d[i].day >> dash1 >> d[i].month >> dash2 >> d[i].year;
    }
    quickSort(d, 0, n-1);

    for (int i = 0; i < n; i++) {
        if (d[i].day < 10) 
            cout << '0';
        cout << d[i].day << '-';

        if (d[i].month < 10) 
            cout << '0';
        cout << d[i].month << '-';

        cout << d[i].year << endl;
    }

    return 0;
}