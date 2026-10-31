#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary(int n, vector<int>& v){
    int l = 0, r = v.size();
    while(l < r){
        int mid = l + (r - l) / 2;
        if(v[mid] > n){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int n, q, p, ans, total;
    cin >> n;
    vector<int> v(n);
    vector<int> sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> q;
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + v[i];
    }
    for(int i = 0; i < q; i++){
        cin >> p;
        ans = binary(p, v);
        total = sum[ans];
        cout << ans << " " << total << endl;
    }
}
