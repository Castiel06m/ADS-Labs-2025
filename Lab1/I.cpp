#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    queue<int> qS, qK;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') qS.push(i);
        else qK.push(i);
    }

    while (!qS.empty() && !qK.empty()) {
        int s_idx = qS.front(); qS.pop();
        int k_idx = qK.front(); qK.pop();

        if (s_idx < k_idx) {
            // S acts first, kicks K
            qS.push(s_idx + n);
        } else {
            // K acts first, kicks S
            qK.push(k_idx + n);
        }
    }

    if (qS.empty())
        cout << "KATSURAGI" << endl;
    else
        cout << "SAKAYANAGI" << endl;

    return 0;
}
