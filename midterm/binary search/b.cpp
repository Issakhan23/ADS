#include <iostream> 
#include <vector>

using namespace std;

bool binaryS(vector<int>& a, int k) {
    int l = 0;
    int r = a.size()-1;

    while (l <= r) {
        int m = l + (r - l)/2;
        if (a[m] == k) return true;
        else if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        int k;
        cin >> k;

        if (binaryS(a, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}