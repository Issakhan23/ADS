#include <iostream>
#include <vector>
using namespace std;

int binary(int n, vector<int>& v){
    int l = 0, r = v.size();
    while(l < r){
        int mid = l + (r - l) / 2;
        if(v[mid] >= n){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int n, m, x, ans;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i != 0){
            v[i] += v[i - 1];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        ans = binary(x, v);
        cout << ans + 1 << endl;
    }
}
