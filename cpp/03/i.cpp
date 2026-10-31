#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, k;
    long long l = 0, r = 0;
    cin >> n >> k;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        l = max(l, v[i]);
        r += v[i];
    }
    while(l < r){
        long long mid = l + (r - l) / 2;
        long long k1 = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + v[i] <= mid){
                sum += v[i];
            }
            else{
                k1++;
                sum = v[i];
            }
        }
        if(k1 <= k){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}
