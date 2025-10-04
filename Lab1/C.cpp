#include <iostream>
#include <string>
using namespace std;

string process(const string& s) {
    string result;
    for (char c : s) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string processed_s1 = process(s1);
    string processed_s2 = process(s2);

    if (processed_s1 == processed_s2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
