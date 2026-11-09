int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a.size(), y = b.size(), z = c.size();
    HashTable ht(x);

    for (int i = 0; i + z <= x; ++i) {
        if (a.compare(i, z, c) == 0) ht.insert(i, "found");
    }

    int cnt = 0;
    for (int i = 0; i + z <= y; ++i) {
        if (b.compare(i, z, c) == 0 && ht.search(i)) cnt++;
    }

    cout << cnt << endl;


    return 0;
}