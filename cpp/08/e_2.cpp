int main() {
    string s;
    cin >> s;
    int n = s.size(), b = 31;

    vector<long long> p(n+1, 1), h(n+1, 0);
    for (int i = 0; i < n; ++i) {
        p[i+1] = p[i]*b;
        h[i+1] = h[i]*b + (s[i] - 'a' + 1);
    }

    int c = 0;
    for (int i = 1; i <= n; ++i) {
        HashTable ht(n);
        for (int j = 0; i + j <= n; ++j) {
            long long key = h[i+j] - h[j]*p[i];
            if (ht.search(key) == "") {
                ht.insert(key, "x");
                c++;
            }
        }
    }

    cout << c << endl;

    return 0;
}