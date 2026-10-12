#include <iostream>

using namespace std;

void quickSort(string& s, int left, int right) {
    int i = left;
    int j = right;
    char pivot = s[(left + right)/2];

    while (i <= j) {
        while (s[i] < pivot) i++;
        while (s[j] > pivot) j--;
        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(s, left, j);
    if (i < right) quickSort(s, i, right);
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string vowels = "", consonants = "";

    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels += c;
        } else {
            consonants += c;
        }
    }

    quickSort(vowels, 0, vowels.size()-1);
    quickSort(consonants, 0, consonants.size()-1);
    cout << vowels << consonants << endl;

    return 0;
}