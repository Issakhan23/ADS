#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getLPS(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();
        vector<int> pi = getLPS(s);
        int l = pi[n-1];
        long long ans = n + (k - 1) * (n - l);
        cout << ans << endl;
    }

    return 0;
}