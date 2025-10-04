#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[(low + high) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(arr, low, j);
    quickSort(arr, i, high);
}

int lowbound(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int upbound(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int count(int arr[], int n, int l, int r) {
    int leftIndex = lowbound(arr, n, l);
    int rightIndex = upbound(arr, n, r);
    return rightIndex - leftIndex;
}

int main() {
    int n, q;
    cin >> n >> q;
    int a[100000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count1 = count(a, n, l1, r1);
        int count2 = count(a, n, l2, r2);
        int ol, orr;
        if (l1 > l2) {
            ol = l1;
        } else {
            ol = l2;
        }
        if (r1 < r2) {
            orr = r1;
        } else {
            orr = r2;
        }
        int overlap = 0;
        if (ol <= orr) {
            overlap = count(a, n, ol, orr);
        }
        cout << (count1 + count2 - overlap) << "\n";
    }
    
    return 0;
}
