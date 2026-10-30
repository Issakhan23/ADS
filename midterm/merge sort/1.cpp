void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {L[i] = a[l + i];}
    for (int i = 0; i < n2; ++i) {R[i] = a[m + i + 1];}

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }

    while (i < n1) {
        a[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        a[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l)/2;

    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

int main() {



    mergeSort(a, 0, n-1);
}