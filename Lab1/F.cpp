#include <iostream>
using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num; ++i)
        if (num % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    int num = 1;

    while (count < n) {
        num++;
        if (isPrime(num)) {
            count++;
        }
    }

    cout << num << endl;

    return 0;
}
