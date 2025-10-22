#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n; 
    cin >> n;
    map<string, string> mp;

    for (int i = 0; i < n; i++) {
        string oldN, newN;
        cin >> oldN >> newN;

        string orig = oldN;
        for (auto it : mp) {
            if (it.second == oldN) {
                orig = it.first;
                break;
            }
        }
        mp[orig] = newN;
    }

    cout << mp.size() << '\n';
    for (auto it : mp)
        cout << it.first << " " << it.second << '\n';
}
