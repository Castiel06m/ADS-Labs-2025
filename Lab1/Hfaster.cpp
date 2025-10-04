#include <iostream>
using namespace std;

bool isPrime(int a) {
    if (a <= 1) return false;
    if (a <= 3) return true;
    if (a % 2 == 0 || a % 3 == 0) return false;

    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int a;
    cin >> a;
    cout << (isPrime(a) ? "YES" : "NO") << endl;
    return 0;
}
