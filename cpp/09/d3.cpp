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

int getmatch(string a, string b) {
    for (char& c : a) c = tolower(c);
    for (char& c : b) c = tolower(c);

    string s = b + '#' + a;
    vector<int> pi = getlps(s);
    return pi.back();
}

int main() {
    string p;
    int n, m = 0;
    cin >> p >> n;
    vector<int> s(n);
    vector<string> cities(n), ans;

    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
        s[i] = getmatch(p, cities[i]);
        m = max(m, s[i]);
    }

    if (m > 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == m) ans.push_back(cities[i]);
        }
    }

    cout << ans.size() << endl;
    for (string city : ans) cout << city << endl;

    return 0;
}