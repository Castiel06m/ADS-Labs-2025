#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void printForward() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertAtPosition(T value, int pos) {
        Node<T>* newNode = new Node<T>(value);
        if (pos == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr) { 
                tail = newNode;
            }
            return;
        }

        Node<T>* curr = head;
        int currentIndex = 0;
        while (curr != nullptr && currentIndex < pos) {
            curr = curr->next;
            currentIndex++;
        }

        if (curr == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            Node<T>* prevNode = curr->prev;
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = curr;
            curr->prev = newNode;
        }
    }

    ~LinkedList() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    
    int n;
    cin >> n;

    LinkedList<int> dll;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        dll.insertTail(val);
    }

    int data, pos;
    cin >> data >> pos;

    dll.insertAtPosition(data, pos);

    dll.printForward();
    return 0;
}
