#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int count[26] = {0};
        vector<char> order;
        
        for (char l : a) {
            int index = l - 'a';
            count[index]++;

            if (count[index] == 1) {
                order.push_back(l);
            }
            string answer = "-1";

            for (char x : order) {
                int index_x = x - 'a';

                if (count[index_x] == 1) {
                    answer = x;
                    break;
                }
            }
            cout << answer << " ";
        }
        cout << endl;
    }

    return 0;
}