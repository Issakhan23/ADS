#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (operation == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            }
            else {
                cout << "EMPTY" << endl;
            }
        }
    }

    return 0;
}