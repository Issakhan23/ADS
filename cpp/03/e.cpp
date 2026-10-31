#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_l(int n, vector<int>& v){
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

int binary_r(int n, vector<int>& v){
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
    int n, q, a, l1, l2, r1, r2, ans;
    cin >> n >> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        if(l2 <= r1){
            int right = max(r1, r2), left = l1;
            ans = binary_r(right, v) - binary_l(left, v);
        }
        else{
            ans = binary_r(r1, v) - binary_l(l1, v) - binary_l(l2, v) + binary_r(r2, v);
        }
        cout << ans << endl;
    }
}
