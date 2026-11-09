int main() {
    long long n;
    cin >> n;
    int k = 128;
    HashTable ht(k);
    for (int i = 0; i < k; ++i) {ht.insert(i, string(1, i+'a'));}

    long long prev = 0, j = 1;
    string res = "";

    for (long long i = 0; i < n; ++i) {
        long long p;
        cin >> p;
        long long dif = p - prev;
        prev = p;
        int t = dif / j;
        res += ht.search(t);
        j*=2;
    }
    cout << res << endl;

    return 0;
}