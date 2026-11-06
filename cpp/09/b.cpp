#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getLPS(string pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
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

int kmp(string t, string p) {
    int n = t.size(), m = p.size();
    vector<int> lps = getLPS(p);

    int i = 0, j = 0, cnt = 0;

    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m) {
            cnt++;
            j = lps[j-1];
        }
    }
    return cnt;
}

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;

    int c = kmp(b, a);
    if (c >= n) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}