#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};


class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

    void insert(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void shift(int k, int n) {
        if (!head || !head->next || k % n == 0)
            return;

        k = k % n;

        Node* current = head;
        int count = 1;
        while (count < k && current != nullptr) {
            current = current->next;
            count++;
        }

        if (!current || !current->next)
            return;

        Node* new_head = current->next;
        current->next = nullptr;
        Node* tail = new_head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;
        head = new_head;
    }
};

int main(){

    int n, k;
    cin >> n >> k;

    LinkedList poem;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        poem.insert(word);
    }

    poem.shift(k, n);
    poem.print();

    return 0;
}