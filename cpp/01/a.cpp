#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main() {
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}





//Submit a solution for A-Greatest Common Divisor
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem A: Greatest Common Divisor