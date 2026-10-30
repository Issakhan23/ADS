int binarysearch(vector<int>& a, int t) {
    int l = 0;
    int r = a.size()-1;
    while(l <= r) {
        int m = l + (r - l)/2;
        if(a[m] == t) return m;
        else if (a[m] < t) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int idx = binarysearch(a, t);
    if (idx == -1) {
        cout << "no";
    } else {
        cout << "yes";
    }
    return 0;
}