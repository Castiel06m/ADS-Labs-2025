#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int value) {
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

    void insert(int value) {
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

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Delete2nd(){
        Node* current = head;
        while (current != nullptr && current->next != nullptr){
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current = current->next;
        }
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }



    
};

int main(){

    int n; cin >> n;

    LinkedList list;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        list.insert(val);
    }

    list.Delete2nd();
    list.print();
    

    return 0;
}