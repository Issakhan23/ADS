#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getlps(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string t, pat;
    cin >> t >> pat;

    vector<int> pi = getlps(pat);
    vector<int> ans;

    int j = 0, m = pat.size();
    for (int i = 0; i < t.size(); ++i) {
        while (j > 0 && t[i] != pat[j]) j = pi[j - 1];
        if (t[i] == pat[j]) j++;
        if (j == m) {
            ans.push_back(i - m + 2);
            j = pi[j - 1];
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}