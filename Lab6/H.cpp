#include <iostream>
using namespace std;

char Solution(char arr[], int n, char target) {
    int low = 0, high = n - 1;
    char result = arr[0]; 

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > target) {
            result = arr[mid];
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    char target;
    cin >> target;

    cout << Solution(arr, n, target) << endl;

    return 0;
}
