#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  

    unordered_map<int, int> freq;  

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        freq[value]++;  
    }

    int maxFreq = 0;
    for (const auto& entry : freq) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;  
        }
    }

    vector<int> modes;
    for (const auto& entry : freq) {
        if (entry.second == maxFreq) {
            modes.push_back(entry.first); 
        }
    }

    sort(modes.rbegin(), modes.rend());

    for (int mode : modes) {
        cout << mode << " ";  
    }


    return 0;
}
