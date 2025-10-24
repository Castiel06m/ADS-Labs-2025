#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){

    int n, m; cin >> n >> m;

    int arr1[n];
    int arr2[m];

    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int j = 0; j < m; j++) cin >> arr2[j];

    mergeSort(arr1, 0, n-1);
    mergeSort(arr2, 0, m-1);

    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) i++;
        else j++;
    }

    return 0;
}