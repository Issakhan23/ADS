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

    void insert(int key, string value) {
        int keyIdx = hash(key);
        table[keyIdx].push_back({key, value});
    }
    bool search(int key) {
        int keyIdx = hash(key);
        for(it = table[keyIdx].begin();it != table[keyIdx].end(); ++it) {
            if (it -> first == key) {
                return true;
            } else {
                return false;
            }
        }
    }
};