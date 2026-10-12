#include <iostream>
#include <string>

using namespace std;

void quickSort(string& s, int l, int r) {
    if (l >= r) return;
    char p = s[l + (r-l)/2];
    int i = l, j = r;
    while(i <= j) {
        while (s[i] < p) i++;
        while (p < s[j]) j--;
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
    string s;
    cin >> s;
    quickSort(s, 0, s.length()-1);
    cout << s << endl;

    return 0;
}