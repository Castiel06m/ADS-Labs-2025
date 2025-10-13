#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    T* heap;
    int capacity;
    int size;

    int parent(int i){
        return (i-1)/2;
    }
        
    int left(int i){
        return i*2 + 1;
    }
        
    int right(int i){
        return i*2 + 2;
    }
    

    void heapify(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void unheapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;

        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            unheapify(largest);
        }
    }

public:
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new T[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void insert(T value) {
        if (size == capacity) {
            return;
        }
        heap[size] = value;
        size++;
        heapify(size - 1);
    }

    T getMax() {
        if (size == 0) {
            return -1;
        }
        return heap[0];
    }

    T extractMax() {
        if (size == 0) {
            return -1;
        }
        T root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        unheapify(0);
        return root;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {

    int n, x;
    cin >> n >> x;

    PriorityQueue<long long> pq(n);

    for (int i = 0; i < n; i++) {
        long long seats;
        cin >> seats;
        pq.insert(seats);
    }

    long long total = 0;

    for (int i = 0; i < x; i++) {
        long long top = pq.extractMax(); 
        total += top;                    
        top--;                           
        if (top > 0) 
            pq.insert(top);     
    }

    cout << total << endl;

    return 0;
}
