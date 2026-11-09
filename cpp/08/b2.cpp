#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class HashTable {
private:
    int cap;
    vector<list<pair<int, string>>> table;
    list<pair<int, string>> :: iterator it;
    
    int hash(int key) {return key%cap;}
public:
    HashTable(int cap): cap(cap) {table.resize(cap);}

    void insert(int key, string val) {
        int keyIdx = hash(key);
        table[keyIdx].push_back({key, val});
    }

    bool search(int key) {
        int keyIdx = hash(key);
        for (it = table[keyIdx].begin(); it != table[keyIdx].end(); ++it) {
            if (it->first == key) return true;
            return false;
        }
    }
};

int main() {
    string c, s, t;
    cin >> c >> s >> t;
    int n = c.size(), k = s.size(), m = t.size();

    HashTable ht(n);
    for (int i = 0; i + m <= n; ++i) {
        if (c.compare(i, m, t) == 0) ht.insert(i, "found");
    }

    int cnt = 0;
    for (int i = 0; i + m <= n; ++i) {
        if (s.compare(i, m, t) == 0 && ht.search(i)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}