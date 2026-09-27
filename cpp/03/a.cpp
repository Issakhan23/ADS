#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& a, int target) {
    int lIdx = 0;
    int rIdx = a.size() - 1;
    while (lIdx <= rIdx) {
        int mid = lIdx + (rIdx - lIdx)/2;
        if(a[mid] == target) return mid;
        else if(a[mid] < target) lIdx = mid + 1;
        else rIdx = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int target;
    cin >> target;
    //sort(a.begin(), a.end());
    int idx = binarysearch(a, target);
    if (idx == -1) {
        cout << "No";
    } else {
        cout << "Yes";
    }



    return 0;
}