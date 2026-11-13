#include <iostream> 
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<bool>> worked(n, vector<bool>(m, false));
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, islands = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1' && !worked[i][j]) {
                islands++;
                queue<pair<int, int>> q;
                worked[i][j] = true;
                q.push({i, j});

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1' && !worked[nx][ny]) {
                            worked[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << islands << endl;

    return 0;
}