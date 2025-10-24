#include <iostream>
#include <string>
using namespace std;

void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string *L = new string[n1];
    string *R = new string[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size()) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string arr[1000];
        int n = 0;
        string s;
        getline(cin, s);

        string w = "";
        for (char c : s) {
            if (c == ' ') {
                if (w != "") {
                    arr[n++] = w;
                    w = "";
                }
            } else {
                w += c;
            }
        }
        if (w != "") arr[n++] = w;

        mergeSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
