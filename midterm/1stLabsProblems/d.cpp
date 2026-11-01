#include <iostream>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        deque<int> d;

        for (int i = N; i >= 1; i--) {
            d.push_front(i);

            int k = i % d.size();

            
            for (int j = 0; j < k; j++) {
                d.push_front(d.back());
                d.pop_back();
            }
        }

        for (int i = 0; i < N; i++) {
            cout << d[i];
            if (i != N - 1)
                cout << " ";
        }

        cout << '\n';
    }

    return 0;
}