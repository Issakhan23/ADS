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

int kmp(string t, string pat) {
    int n = t.size(), m = pat.size();

    vector<int> lps = getLPS(pat);
    int i = 0, j = 0;

    while (i < n) {
        while (j > 0 && t[i] != pat[j]) {
            j = lps[j-1];
        }
        if (t[i] == pat[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;
        }
        i++;
    }
    return -1;
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();

    string t = b+b;
    t.pop_back();
    int ans = kmp(t, a);
    cout << ans << endl;

    return 0;
}