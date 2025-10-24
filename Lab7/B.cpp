#include <iostream>
using namespace std;

void mergeArrayki(int arr1[], int n, int arr2[], int m, int res[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) res[k++] = arr1[i++];
        else res[k++] = arr2[j++];
    }
    while (i < n) res[k++] = arr1[i++];
    while (j < m) res[k++] = arr2[j++];
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    int resultik[n + m];
    mergeArrayki(a, n, b, m, resultik);

    for (int i = 0; i < n + m; i++)
        cout << resultik[i] << " ";
    return 0;
}
