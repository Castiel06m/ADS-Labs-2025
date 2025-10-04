#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> dq;
    string sss;
    int x;

    while (cin >> sss) {
        if (sss == "!") {
            break;
        } else if (sss == "+") {
            cin >> x;
            dq.push_front(x);
        } else if (sss == "-") {
            cin >> x;
            dq.push_back(x);
        } else if (sss == "*") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else if (dq.size() == 1) {
                cout << dq.front() * 2 << endl;
                dq.pop_front();
            } else {
                int sum = dq.front() + dq.back();
                cout << sum << endl;
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    return 0;
}
