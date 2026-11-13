#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }

    int ans = 0;
    for (int i = 1; 2*i < n; ++i) {
        int p = 2*i - pi[2*i - 1];
        if (i % p == 0) ans++;
    } 

    cout << ans << endl;

    return 0
}