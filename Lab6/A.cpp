#include <iostream>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    char s[n];
    cin >> s;

    char vowels[n];
    char consonants[n];
    int vCount = 0, cCount = 0;

    for (int i = 0; i < n; i++) {
        if (isVowel(s[i]))
            vowels[vCount++] = s[i];
        else
            consonants[cCount++] = s[i];
    }

    if (vCount > 0) quickSort(vowels, 0, vCount - 1);
    if (cCount > 0) quickSort(consonants, 0, cCount - 1);

    for (int i = 0; i < vCount; i++)
        cout << vowels[i];
    for (int i = 0; i < cCount; i++)
        cout << consonants[i];
    cout << endl;

    return 0;
}
