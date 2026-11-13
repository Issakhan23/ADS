#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int start, finish;
    cin >> start >> finish;

    start--;
    finish--;
    vector<int> d(n, -1);
    queue<int> q;

    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1 && d[j] == -1) {
                d[j] = d[i] + 1;
                q.push(j);
            }
        }
    }

    cout << d[finish] << endl;

    return 0;
}