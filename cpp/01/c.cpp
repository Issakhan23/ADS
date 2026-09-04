#include <iostream>
#include <cmath>
using namespace std;

string isPrime(int a) {
    bool prime = true;
    if (a < 2) {
        prime = false;
    } else if (a == 2) {
        prime = true;
    } else {
        for(int i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                prime = false;
                break;
            } else {
                prime = true;
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
    int a;
    cin >> a;

    cout << isPrime(a);
    return 0;
}




//Submit a solution for C-Prime or Not
//Time limit:	1 s
//Real time limit:	5 s
//Memory limit:	256M
//Problem C: Prime or Not