#include <iostream>
#include <string>
using namespace std;

string f(string s) {
    string c;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == '#') {
            if (!c.empty()) {
                c.pop_back();
            }
        } else {
            c.push_back(s[i]);
        }
    }
    return c;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string a = f(s1);
    string b = f(s2);

    if (a == b) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}


//Submit a solution for G-Balanced Sequence of Letters
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem G: Balanced Sequence of Letters