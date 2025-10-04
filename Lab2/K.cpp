#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T* data;
    int size;
    int head;
    int tail;
    bool full;

public:
    Queue(int GivenSize)
    {
        size = GivenSize * 2;
        data = new T[size];
        head = 0;
        tail = 0;
        full = false;
    }

    ~Queue()
    {
        delete[] data;
    }

    bool empty() const
    {
        return (!full && head == tail);
    }

    bool isFull() const
    {
        return full;
    }

    void enqueue(T value)
    {
        if (full)
        {

            return;
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        if (tail == head)
            full = true;
    }

    T getTop() const
    {
        if (empty())
        {
            return T(); 
        }
        return data[head];
    }

    void dequeue()
    {
        if (empty())
        {
        
            return;
        }
        head = (head + 1) % size;
        full = false;
    }
};

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int num;
        cin >> num;

        int freq[26] = {0};
        Queue<char> q(num);

        for (int i = 0; i < num; i++)
        {
            char ch;
            cin >> ch;
            freq[ch - 'a']++;

            q.enqueue(ch);

            while (!q.empty() && freq[q.getTop() - 'a'] > 1)
            {
                q.dequeue();
            }

            if (q.empty())
                cout << -1 << " ";
            else
                cout << q.getTop() << " ";
        }
        cout << "\n";
    }

    return 0;
}
