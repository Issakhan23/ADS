#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
    }
    for(int i = 0; i < n; i++){
        int l = i + 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            int total = sum[mid] - sum[i];
            if(total >= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(sum[l] - sum[i] >= k){
            if(ans != 0){
                ans = min(ans, l - i);
            }
            else{
                ans = l - i;
            }
        }
    }
    cout << ans;
}
