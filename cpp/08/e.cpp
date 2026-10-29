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
        int res = key % cap;
        if (res < 0) {res += cap;}
        return res;
    }
public:
    HashTable(int cap): cap(cap) {
        table.resize(cap);
    }
    void insert(long long key, string val) {
        int keyIdx = hash(key);
        table[keyIdx].push_back({key, val});
    }
    string search (long long key) {
        int keyIdx = hash(key);
        for (it = table[keyIdx].begin(); it != table[keyIdx].end(); ++it) {
            if (it -> first == key) {
                return it -> second;
            }
        }
        return "";
    }
};

int main() {
    string s;
    cin >> s;
    int base = 31;
    int n = s.size();

    vector<unsigned long long> p(n+1, 1), h(n+1, 0);
    for (int i = 0; i < n; ++i) {
        p[i+1] = p[i]*base;
        h[i+1] = h[i]*base + (s[i] - 'a' + 1);
    }
    int c = 0;
    for (int j = 1; j <= n; ++j) {
        HashTable ht(n);
        for (int k = 0; k + j <= n; ++k) {
            long long key = h[k + j] - h[k] * p[j];
            if (ht.search(key) == "") {
                ht.insert(key, "x");
                c++;
            }
        }
    }
    cout << c << endl;


    return 0;
}