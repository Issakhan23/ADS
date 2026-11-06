#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getLPS(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {j = pi[j - 1];}
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int getMatch(string p, string city) {
    for (char& c : p) {c = tolower(c);}
    for (char& c : city) {c = tolower(c);}
    string s = city + "#" + p;
    vector<int> pi = getLPS(s);
    return pi.back();
}

int main() {
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector<string> cities(n);
    vector<int> s(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
        s[i] = getMatch(p, cities[i]);
        m = max(m, s[i]);
    }
    vector<string> ans;
    if (m > 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == m) ans.push_back(cities[i]);
        }
    }
    cout << ans.size() << endl;
    for (string city : ans) {
        cout << city << endl;
    }

    return 0;
}