#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class HashTable {
private:
    int cap;
    vector<list<pair<long long, string>>> table;
    list<pair<long long, string>> :: iterator it;
    int hash(long long key) {
        return key % cap;
    }
public:
    HashTable(int cap): cap(cap) {
        table.resize(cap);
    }
    void insert(long long key, string val) {
        int keyIdx = hash(key);
        table[keyIdx].push_back({key, val});
    }
    string search(long long key, string p) {
        int keyIdx = hash(key);
        for (it = table[keyIdx].begin(); it != table[keyIdx].end(); ++it) {
            if (it -> first == key && it -> second == p) {
                return it -> second;
            }
        }
        return "";
    }
};


long long getHash(string s) {
    long long key = 0;
    for (char co : s) {
        key = key * 31 + (co - 'a' + 1);
    }
    return key;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<string> p(n);
        vector<int> fr(n, 0);
        int maxlen = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i].length() > maxlen) maxlen = p[i].length();
        }
        string t;
        cin >> t;
        HashTable ht(2*n + 1);
        for (int i = 0; i < n; ++i) {
            ht.insert(getHash(p[i]), p[i]);
        }
        for (int i = 0; i < n; ++i) {
            fr[i] = 0;
            for (int j = 0; j + p[i].length() <= t.length(); j++) {
                if (t.substr(j, p[i].length()) == p[i]) {
                    fr[i]++;
                }
            }
        }
    
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (fr[i] > m) m = fr[i];
        }
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (fr[i] == m) c++;
        }
        cout << m << endl;
        for (int i = 0; i < n; ++i) {
            if (fr[i] == m) cout << p[i] << endl;
        }
    }

    return 0;
}