void quickSort (vector<int>& a, int l, int r) {
    int i = l, j = r;
    int p = a[l + (r - l)/2];
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {


    quickSort(a, 0, s.length()-1);
}