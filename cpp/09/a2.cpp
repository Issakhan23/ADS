#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getlps(string p) {
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmp(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> lps = getlps(b);
    int j = 0;
    for (int i = 0; i < n + m - 1; ++i) {
        char c = a[i%n];
        while (j > 0 && c != b[j]) {j = lps[j-1];}
        if (c == b[j]) j++;
        if (j == m) return i-m+1;
    }
    return -1;
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    int p = kmp(a, b);
    if (p == -1) {
        cout << -1 << endl;
    } else {
        int ans = (p + m + n - 1)/n;
        cout << ans << endl;
    }

    return 0;
}