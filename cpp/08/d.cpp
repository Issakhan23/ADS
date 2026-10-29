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
    int hash(int key) {
        return key % cap;
    }
public:
    HashTable(int cap): cap(cap) {
        table.resize(cap);
    }
    void insert(int key, string val) {
        int keyIdx = hash(key);
        table[keyIdx].push_back({key, val});
    }
    string search(int key) {
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
    long long n;
    cin >> n;
    int k = 128;

    HashTable ht(k);
    for (int i = 0; i < k; ++i) {
        ht.insert(i, string(1, i + 'a'));
    }
    long long prev = 0;
    string res = "";
    long long j = 1;
    for (long long i = 0; i < n; ++i) {
        long long p;
        cin >> p;
        long long dif = p - prev;
        prev = p;
        int t = dif / j;
        res += ht.search(t);
        j *= 2;
    }
    cout << res << endl;

    return 0;
}