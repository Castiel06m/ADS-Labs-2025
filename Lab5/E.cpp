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
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void unheapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[smallest])
            smallest = l;

        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            unheapify(smallest);
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

    T getMin() {
        if (size == 0) {
            return -1;
        }
        return heap[0];
    }

    T extractMin() {
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

    int n, k;
    cin >> n >> k;

    PriorityQueue<long long> pq(k);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long x;
            cin >> x;

            if (pq.getSize() < k) {
                pq.insert(x);
                sum += x;
            } else if (x > pq.getMin()) {
                sum -= pq.getMin();
                pq.extractMin();
                pq.insert(x);
                sum += x;
            }
        } 
        else if (command == "print") {
            cout << sum << endl;
        }
    }

    return 0;
}
