#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<string> poem;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        poem.push_back(word);
    }

    k = k % n;

    for (int i = 0; i < k; ++i) {
        poem.push_back(poem.front());
        poem.pop_front();
    }

    for (const string& word : poem) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
