#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];

            if (a[i][j] == 2) {
                q.push({i, j});
                b[i][j] = 0;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans = 0;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (a[nx][ny] == 1) {
                a[nx][ny] = 2;
                b[nx][ny] = b[x][y] + 1;
                ans = max(ans, b[nx][ny]);
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                cout << -1 << endl; 
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}