#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> st;

    for (int i = 0; i < N; i++) {
        int age;
        cin >> age;

        
        while (!st.empty() && st.top() >= age) {
            st.pop();
        }

        if (st.empty()) {
            cout << -1;
        } else {
            cout << st.top();
        }

        if (i < N - 1) {
            cout << " ";
        }

        st.push(age);
    }

    return 0;
}
//Submit a solution for H-Nugman and Stack
//Time limit:	2 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem H: Nugman and Stack