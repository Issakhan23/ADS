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
    int n;
    cin >> n;

    HashTable ht(s.size());
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        long long key = l * (s.size() + 1) + r;
        string res = ht.search(key);
        if(res != "") {
            cout << res << endl;
        } else {
            string sub = s.substr(l - 1, r - l + 1);
            int c = 0;
            size_t p = s.find(sub, 0);
            while (p != string::npos) {
                c++;
                p = s.find(sub, p+1);
            }
            res = to_string(c);
            ht.insert(key, res);
            cout << res << endl;
        }
    }


    return 0;
}