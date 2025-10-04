#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    const int LIMIT = 9000;  
    vector<bool> isPrime(LIMIT + 1, true);
    isPrime[0] = isPrime[1] = false;

    
    for (int i = 2; i * i <= LIMIT; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    
    int count = 0;
    for (int i = 2; i <= LIMIT; ++i) {
        if (isPrime[i]) {
            ++count;
            if (count == N) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
