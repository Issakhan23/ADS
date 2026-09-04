#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string isPrime(long long a) {
    bool prime = true;
    if (a < 2) {
        prime = false;
    } else if (a == 2) {
        prime = true;
    } else {
        for(long long i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                prime = false;
                break;
            } 
        }
    }
    if (prime == true) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    long long n;
    cin >> n;
    if (isPrime(n) == "YES") {
        cout << n;
    } else {
        vector<long long> v;

        for (long long i = 2; i * i <= n; ) {
            if (n % i == 0) {
                v.push_back(i);
                n /= i;
            } else if (n == 1) {
                break;
            } else {
                ++i;
            }
        }
        if (n > 1) {
            v.push_back(n);
        }

        for (long long i: v) {
            cout << i << " ";
        }
    }
    return 0;
}


//Submit a solution for E-Prime Factorization
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem E: Prime Factorization