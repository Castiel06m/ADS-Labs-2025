#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n; 
    cin >> n;
    stack<string> st;
    string name;

    for (int i = 0; i < n; ++i) {
        cin >> name;
        if (st.empty() || st.top() != name) {
            st.push(name);
        }
    }

    cout << "All in all: " << st.size() << "\n";
    cout << "Students:\n";

    while (!st.empty()) {
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}
