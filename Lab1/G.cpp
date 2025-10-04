#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    vector<int> superprimes;

    int num = 2;
    while (superprimes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num);
            int index = primes.size(); 
            if (isPrime(index)) {
                superprimes.push_back(num);
            }
        }
        num++;
    }

    cout << superprimes[n - 1] << endl;

    return 0;
}
