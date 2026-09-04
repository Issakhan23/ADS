#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
//Submit a solution for H-Nugman and Stack
//Time limit:	2 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem H: Nugman and Stack