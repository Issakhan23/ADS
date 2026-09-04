#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x) {
    if (x < 2)
        return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main() {
    int a, c = 0, n = 1;
    cin >> a;

    while(c < a) {
        ++n;
        if (isPrime(n)) {
            ++c;
        }
    }
    cout << n << endl;
    return 0;
}


//Submit a solution for D-Prime Numbers
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem D: Prime Numbers