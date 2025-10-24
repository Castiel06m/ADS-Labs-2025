#include <iostream>
using namespace std;

struct Row {
    int arr[1000];
    int sum;
};

bool compare(Row a, Row b){
    if (a.sum != b.sum) return a.sum > b.sum;
    for (int i = 0; ; i++){
        if (a.arr[i] < b.arr[i]) return true;
        if (a.arr[i] > b.arr[i]) return false;
        // если оба равны продолжаем дальше
    }
}

void merge(Row *arr, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;

    
    Row* left = new Row[left_len];
    Row* right = new Row[right_len];

    for (int i = 0; i < left_len; i++)
        left[i] = arr[beg + i];
    for (int i = 0; i < right_len; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = beg;
    while (k <= end){
        if (i < left_len && (j >= right_len || compare(left[i], right[j]))){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    delete[] left;
    delete[] right;
}

void merge_sort_rec(Row *arr, int beg, int end){
    if (beg < end){
        int mid = (beg + end) / 2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(Row *arr, int len){
    merge_sort_rec(arr, 0, len - 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    Row rows[10000];

    for(int i = 0; i < n; i++){
        rows[i].sum = 0;
        for(int j = 0; j < m; j++){
            cin >> rows[i].arr[j];
            rows[i].sum += rows[i].arr[j];
        }
    }

    merge_sort(rows, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << rows[i].arr[j] << " ";
        cout << endl;
    }

    return 0;
}
