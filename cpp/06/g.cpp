#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct user {
    string oldName, newName;
};

void quickSort(vector<user>& u, int l, int r) {
    if (l >= r) return;
    string p = u[l + (r - l) / 2].oldName;
    int i = l, j = r;
    while (i <= j) {
        while (u[i].oldName < p) i++;
        while (u[j].oldName > p) j--;
        if (i <= j) {
            swap(u[i], u[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(u, l, j);
    if (i < r) quickSort(u, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<user> u;
    for (int i = 0; i < n; ++i) {
        string oldName, newName;
        cin >> oldName >> newName;
        bool find = false;
        for (int j = 0; j < u.size(); ++j) {
            if (u[j].newName == oldName) {
                u[j].newName = newName;
                find = true;
                break;
            }
        }
        if (!find) {
            user us;
            us.oldName = oldName;
            us.newName = newName;
            u.push_back(us);
        }
    }

    quickSort(u, 0, u.size()-1);

    cout << u.size() << endl;

    for (int i = 0; i < u.size(); ++i) {
        cout << u[i].oldName << " " << u[i].newName << endl;
    }

    return 0;
}