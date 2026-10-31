#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_row(int n, vector<vector<int>>& v, int m){
    int row, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        int max_val = max(v[mid][0], v[mid][m - 1]);
        int min_val = min(v[mid][0], v[mid][m - 1]);
        if(n >= min_val && n <= max_val){
            return mid;
        }
        if(n > max_val){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}

int binary_col(int n, int row, vector<vector<int>>& v, int m){
    int col, l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[row][mid] == n){
            return mid;
        }
        if(row % 2 == 0){
            if(v[row][mid] > n){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        else{
            if(v[row][mid] < n){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int x, t, n, m;
    cin >> t;
    vector<int> v;
    for(int i = 0; i < t; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> n >> m;
    vector<vector<int>> v1(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v1[i][j];
        }
    }
    for(int i = 0; i < v.size(); i++){
        int row = binary_row(v[i], v1, m);
        if(row == -1){
            cout << -1 << endl;
        }
        else{
            int col = binary_col(v[i], row, v1, m);
            if(col == -1){
                cout << -1 << endl;
            }
            else{
                cout << row << " " << col << endl;
            }
        }
    }
}
