#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string last;
    string first;
    double gpa;
};

double MyGPA(string grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A")  return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B")  return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C")  return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D")  return 1.00;
    return 0.00; // ф-ка 
}

bool compare(Student a, Student b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* L = new Student[n1];
    Student* R = new Student[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
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

void mergeSort(Student arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}



int main(){

    int n;
    cin >> n;
    Student arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].last >> arr[i].first;
        int subjects;
        cin >> subjects;

        double sum = 0.0, CredSum = 0.0;
        for (int j = 0; j < subjects; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            sum += MyGPA(grade) * credit;
            CredSum += credit;
        }
        arr[i].gpa = sum / CredSum;
    }

    mergeSort(arr, 0, n - 1);

    cout << fixed << setprecision(3); 

    for (int i = 0; i < n; i++) {
        cout << arr[i].last << " " << arr[i].first << " " << arr[i].gpa << endl;
    }
    return 0;
}