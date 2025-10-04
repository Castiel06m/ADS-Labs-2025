#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> construct_deck(int n) {
    deque<int> deck;


    for (int i = n; i >= 1; --i) {

        deck.push_front(i);

        for (int j = 0; j < i; ++j) {
            if (!deck.empty()) {
                deck.push_front(deck.back());
                deck.pop_back();
            }
        }
    }

    return vector<int>(deck.begin(), deck.end());
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> result = construct_deck(n);
        for (int card : result) {
            cout << card << " ";
        }
        cout << "\n";
    }
    return 0;
}
