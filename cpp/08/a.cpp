#include <iostream> 
#include <vector>
#include <string>
#include <set>

using namespace std;

string HashTable (string& s) {
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h + (c - 47) * p) % 1e9 + 7;
        p = p * 11 % (1e9 + 7);
    }
    return to_string(h);
}

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