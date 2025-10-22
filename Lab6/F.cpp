#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string last;
    string first;
    double gpa;
};

void MySwap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

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

int partition(Student arr[], int low, int high) {
    Student pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            MySwap(arr[i], arr[j]);
        }
    }
    MySwap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {
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

    quickSort(arr, 0, n - 1);

    cout << fixed << setprecision(3); 

    for (int i = 0; i < n; i++) {
        cout << arr[i].last << " " << arr[i].first << " " << arr[i].gpa << endl;
    }

    return 0;
}
