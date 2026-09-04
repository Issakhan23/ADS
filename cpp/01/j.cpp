#include <iostream>
#include <deque>
using namespace std;

bool borisWins(int a, int b) {
    
    if (a == 0 && b == 9)
        return true;

    if (a == 9 && b == 0)
        return false;

    return a > b;
}

int main() {
    deque<int> boris;
    deque<int> nursik;

    
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        boris.push_back(x);
    }

    
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        nursik.push_back(x);
    }

    int c = 0;

    while (!boris.empty() && !nursik.empty()) {
        int b = boris.front();
        int n = nursik.front();

        boris.pop_front();
        nursik.pop_front();

        c++;

        if (borisWins(b, n)) {
            boris.push_back(b);
            boris.push_back(n);
        }
        else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
    }

    if (boris.empty()) {
        cout << "Nursik " << c;
    }
    else {
        cout << "Boris " << c;
    }

    return 0;
}
// Submit a solution for J-Boris vs Nursik
// Time limit:	1 s
// Real time limit:	5 s
// Memory limit:	256M
// Problem J: Boris vs Nursik