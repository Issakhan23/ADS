#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, l = 1, r = 1;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        r = max(r, v[i]);
    }
    while(l < r){
        int mid = l + (r - l) / 2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (v[i] + mid - 1) / mid;
        }
        if(ans <= k){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}
