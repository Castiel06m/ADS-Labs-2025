#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s; 
    cin >> s;  // Read input string

    // Stack holds pairs: (character, isBalanced)
    // isBalanced = true means substring represented is balanced
    stack<pair<char, bool>> st;

    for (char c : s) {
        // Push new character as not balanced (false)
        st.push({c, false});

        bool reduced; // Flag to track if we made a reduction
        do {
            reduced = false;

            // Try to reduce top 3 elements in stack if possible
            if (st.size() >= 3) {
                // Get top three elements
                auto top1 = st.top(); st.pop();
                auto top2 = st.top(); st.pop();
                auto top3 = st.top(); st.pop();

                // Check if top3.char == top1.char AND middle substring is balanced
                // Pattern: x s x with s balanced means this whole substring is balanced
                if (top3.first == top1.first && top2.second) {
                    st.push({top3.first, true});  // Push combined balanced substring
                    reduced = true;
                } else {
                    // Can't reduce, push back elements in original order
                    st.push(top3);
                    st.push(top2);
                    st.push(top1);
                }
            }

            // If no reduction yet, try reducing pairs or concatenations
            if (!reduced && st.size() >= 2) {
                auto top1 = st.top(); st.pop();
                auto top2 = st.top(); st.pop();

                // Case 1: Two identical chars, both not balanced
                // This means substring "xx" with empty middle, so balanced
                if (top1.first == top2.first && !top1.second && !top2.second) {
                    st.push({top1.first, true});  // Combine to balanced
                    reduced = true;

                // Case 2: Two adjacent balanced substrings
                // Concatenation of balanced substrings is balanced
                } else if (top1.second && top2.second) {
                    st.push({top2.first, true});  // Merge balanced substrings
                    reduced = true;

                } else {
                    // Cannot reduce, push back
                    st.push(top2);
                    st.push(top1);
                }
            }
        } while (reduced); // Repeat until no more reductions possible
    }

    // After processing whole string:
    // If exactly one balanced substring remains, print YES
    if (st.size() == 1 && st.top().second) {
        cout << "YES\n";
    } 
    // Empty string is balanced
    else if (st.empty()) {
        cout << "YES\n";
    } 
    // Otherwise, not balanced
    else {
        cout << "NO\n";
    }

    return 0;
}
