#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> boris, nursik;
    int card;

    for (int i = 0; i < 5; ++i) {
        cin >> card;
        boris.push(card);
    }

    
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        nursik.push(card);
    }

    int moves = 0;
    const int MAX_MOVES = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < MAX_MOVES) {
        int b = boris.front(); boris.pop();
        int n = nursik.front(); nursik.pop();

        // Determine winner (handle special case: 0 beats 9)
        bool borisWins = (b == 0 && n == 9) || (b > n && !(b == 9 && n == 0));

        if (borisWins) {
            // Boris takes both: his card first, then Nursik's
            boris.push(b);
            boris.push(n);
        } else {
            // Nursik takes both: Boris's card first, then Nursik's
            nursik.push(b);
            nursik.push(n);
        }

        ++moves;
    }

    if (moves >= MAX_MOVES) {
        cout << "blin nichya\n";
    } else if (boris.empty()) {
        cout << "Nursik " << moves << "\n";
    } else {
        cout << "Boris " << moves << "\n";
    }

    return 0;
}
