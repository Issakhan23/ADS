#include <iostream>
#include <vector>
#include<iomanip>
#include <algorithm>
using namespace std;

double binary(vector<long long>& v, long long k){
    double l = 0;
    double r = *max_element(v.begin(), v.end());
    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;
        long long sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += (long long)(v[i] / mid);
        }
        if(sum >= k){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

int main(){
    long long n, k;
    double r;
    cin >> n >> k;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    double ans = binary(v, k);
    cout << fixed << setprecision(9) << ans;
}
