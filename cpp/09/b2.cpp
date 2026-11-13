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

    int i = 0, j = 0, cnt = 0;

    while (i < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (j != 0) j = lps[j - 1];
            i++;
        }
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        }
    }
    return cnt;
}

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;

    int c = kmp(b, a);
    if (c >= n) cout << "YES" << endl;
    cout << "NO" << endl;

    return 0;
}