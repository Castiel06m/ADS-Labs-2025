#include <iostream>
using namespace std;

const int MAX_N = 100000;
int a[MAX_N];

int findMax(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    return maxVal;
}

long long findSum(int a[], int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (long long)a[i];
    }
    return total;
}

bool valid(int a[], int n, int k, long long maxSum) {
    int count = 1;
    long long currSum = 0;
    for (int i = 0; i < n; ++i) {
        long long val = (long long)a[i];
        if (val > maxSum) return false;
        if (currSum + val > maxSum) {
            count++;
            currSum = val;
        } else {
            currSum += val;
        }
    }
    return count <= k;
}

long long miniMaxSum(int a[], int n, int k) {
    long long l = (long long)findMax(a, n);
    long long r = findSum(a, n);
    long long answer = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (valid(a, n, k, mid)) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << miniMaxSum(a, n, k) << endl;
    return 0;
}
