#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> res;
    string s, p = "";
    for  (int i = 0; i < N; ++i) {
        cin >> s;
        if (s != p) {
            res.push_back(s);
            p = s;
        }
    }
    cout << res.size() << endl;
    for (string s : res) {
        cout << s << endl;
    }

    return 0;
}