#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(max(x2, y2));
    }
    sort(v.begin(), v.end());
    cout << v[k - 1];
}
