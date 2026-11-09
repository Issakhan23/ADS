

int main() {
    int n;
    cin >> n;

    vector<string> t(2*n);
    for (auto& s : t) cin >> s;

    set<string> a(t.begin(), t.end());
    int pr = 0;

    for (auto& s : t) {
        if (pr < n && a.count(HashTable(s))) {
            cout << "Hash of string \"" << s << "\" is " << HashTable(s) << endl;
            pr++;
        }
    }



    return 0;
}