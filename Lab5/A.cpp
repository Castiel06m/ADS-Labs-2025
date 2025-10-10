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

    const int MAX_SIZE = 400000;
    PriorityQueue<long long> pq(MAX_SIZE);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long temp; cin >> temp;
        pq.insert(temp);
    }


    long long cnt = 0;
    while (pq.getSize() > 1) {
        long long first = pq.extractMin();
        long long second = pq.extractMin();
        long long merged = first + second;
        cnt += merged;
        pq.insert(merged);
    }

    cout << cnt << endl;
    return 0;
}
