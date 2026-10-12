#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct student {
    string last, first;
    double gpa;
};

double grade(string s) {
    if (s == "A+") return 4.00;
    if (s == "A") return 3.75;
    if (s == "B+") return 3.50;
    if (s == "B") return 3.00;
    if (s == "C+") return 2.50;
    if (s == "C") return 2.00;
    if (s == "D+") return 1.50;
    if (s == "D") return 1.00;
    return 0.00;
}

bool lS(student a, student b) {
    if (a.gpa != b.gpa) {
        return a.gpa < b.gpa;
    }
    if (a.last != b.last) {
        return a.last < b.last;
    }
    return a.first < b.first;
}

void quickSort(vector<student>& s, int l, int r) {
    if (l >= r) return;
    student p = s[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (lS(s[i], p)) i++;
        while (lS(p, s[j])) j--;
        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(s, l, j);
    if (i < r) quickSort(s, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<student> s(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> s[i].last >> s[i].first >> m;
        double t = 0;
        int cred = 0;

        for (int j = 0; j < m; ++j) {
            string mark;
            int c;
            cin >> mark >> c;

            t += grade(mark) * c;
            cred += c;
        }
        s[i].gpa = t/cred;
    }
    quickSort(s, 0, n-1);
    cout << fixed << setprecision(3);
    for (int i = 0; i < n; ++i) {
        cout << s[i].last << " " << s[i].first << " " << s[i].gpa << endl;
    }
}