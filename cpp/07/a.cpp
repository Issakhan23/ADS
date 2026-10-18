#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void merge(vector<string>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {L[i] = arr[l+i];}
    for (int i = 0; i < n2; ++i) {R[i] = arr[mid + i + 1];}
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].length() <= R[j].length()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }

}

void mergeSort(vector<string>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    int n;
    cin >> n;

    string line, word = "";
    getline(cin, line);

    while (n--) {
        getline(cin, line);
        vector<string> arr;
        for (int i = 0; i <= line.length(); ++i) {
            if (i == line.length() || line[i] == ' ') {
                if (word != "") {
                    arr.push_back(word);
                    word = "";
                }
            } else {
                word += line[i];
            }
        }

        mergeSort(arr, 0, arr.size()-1);

        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}