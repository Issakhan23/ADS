//a
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
                len = lps[len - 1];
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
        while (j > 0 && c != b[j]) j = lps[j - 1];
        if (c == b[j]) j++;
        if (j == m) return i-m+1;
    }
    return -1;
}



//b
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
                len = lps[len - 1];
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
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
            if (j == m) {
                cnt++;
                j = lps[j - 1];
            }
        }
    }
    return cnt;
}



//c
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
                len = lps[len - 1];
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
    int i = 0, j = 0;

    while (i < n) {
        while (j > 0 && a[i] != b[j]) j = lps[j - 1];
        if (j == m) return i - m + 1;
        i++;
    }
    return -1;
}



//d
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

int getmatch(string p, string city) {
    for (char& c : p) c = tolower(c);
    for (char& c : city) c = tolower(c);

    string s = city + '#' + p;
    vector<int> pi = getlps(s);
    return pi.back();
}



//e
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




//f
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




//g
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




//h







//a2
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

//b2
int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;

    int c = kmp(b, a);
    if (c >= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

//c2
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

//d2
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
        s[i] = getmatch(p, cities[i]);
        m = max(m, s[i]);
    }

    vector<string> ans;
    if (m > 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == m) ans.push_back(cities[i]);
        }
    }

    cout << ans.size() << endl;
    for (string city : ans) cout << city << endl;

    return 0;
}

//e2
int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();

        vector<int> pi = getlps(s);
        int l = pi[n - 1];

        long long ans = n + (k - 1) * (n - 1);
        cout << ans << endl;
    }

    return 0;
}

//f2
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
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

//g2
int main() {
    string s;
    cin >> s;

    vector<int> pi = getlps(s);
    int n = s.size();
    int ans = n - pi[n - 1];
    cout << ans << endl;

    return 0;
}

//h2
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
    for (int i = 1; 2 * i < n; ++i) {
        int p = 2*i - pi[2*i - 1];
        if (i % p == 0) ans++;
    }
    cout << ans << endl;

    return 0;
}