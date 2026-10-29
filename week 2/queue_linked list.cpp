
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* taonode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void chencuoi(Node* &head, Node* &tail, int x) {
    Node* newNode = taonode(x);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void xoadau(Node* &head, Node* &tail) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}

bool isempty() {
    return head == nullptr;
}

void enqueue(int x) {
    chencuoi(head, tail, x);
}

int dequeue() {
    if (isempty()) {
        return -1;
    }

    int x = head->data;
    xoadau(head, tail);
    return x;
}

int peek() {
    if (isempty()) {
        return -1;
    }

    return head->data;
}

int size() {
    int dem = 0;
    Node* temp = head;

    while (temp != nullptr) {
        dem++;
        temp = temp->next;
    }

    return dem;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Size: " << size() << endl;
    cout << "Peek: " << peek() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Peek sau dequeue: " << peek() << endl;
    cout << "Size sau dequeue: " << size() << endl;
    cout << "Empty: " << isempty() << endl;

    while (!isempty()) {
        dequeue();
    }

    return 0;
}

