#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }

    int target;
    cin >> target; 

    int min_diff = abs(arr[0] - target); 
    int min_index = 0;

    for (int i = 1; i < n; ++i) {
        int diff = abs(arr[i] - target);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }

    cout << min_index << endl;

    return 0;
}
