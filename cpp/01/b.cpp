#include <iostream>
#include <cmath>
using namespace std;


int main() {
    long long a, n, m;
    cin >> a >> n >> m;
    a %= m;
    long long c = 1 % m;

    while (n > 0) {
        if (n % 2 == 1)
            c = (c * a) % m;

        a = (a * a) % m;
        n /= 2;
    }

    cout << c << endl;
    return 0;
}
//Submit a solution for B-Binary Exponentiation
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem B: Binary Exponentiation