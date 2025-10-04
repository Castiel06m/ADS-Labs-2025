#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (head == nullptr) return head;
    if (p == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }
    if (curr->next == nullptr) {
        return head;
    }
    Node* toDelete = curr->next;
    curr->next = toDelete->next;
    delete toDelete;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    if (head == nullptr) return head;

    Node* dummy = new Node(0, head);
    Node* prevP1 = dummy;
    for (int i = 0; i < p1 && prevP1->next != nullptr; i++) {
        prevP1 = prevP1->next;
    }
    if (prevP1->next == nullptr) {
        delete dummy;
        return head; 
    }
    Node* nodeToMove = prevP1->next;
    prevP1->next = nodeToMove->next;

    Node* prevP2 = dummy;
    for (int i = 0; i < p2 && prevP2->next != nullptr; i++) {
        prevP2 = prevP2->next;
    }
    nodeToMove->next = prevP2->next;
    prevP2->next = nodeToMove;

    head = dummy->next;
    delete dummy;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }
    x = x % len;
    if (x == 0) return head;

    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }
    x = x % len;
    if (x == 0) return head;

    return cyclic_left(head, len - x);
}

int main() {
    Node* head = nullptr;

    while (true) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}
