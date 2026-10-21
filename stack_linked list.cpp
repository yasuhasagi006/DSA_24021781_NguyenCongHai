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

void chendau(Node* &head, Node* &tail, int x) {
    Node* newNode = taonode(x);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
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

void push(int x) {
    chendau(head, tail, x);
}

int pop() {
    if (isempty()) {
        return -1;
    }

    int x = head->data;
    xoadau(head, tail);
    return x;
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

int top() {
    if (isempty()) {
        return -1;
    }

    return head->data;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Size: " << size() << endl;
    cout << "Top: " << top() << endl;
    cout << "Pop: " << pop() << endl;
    cout << "Top sau pop: " << top() << endl;
    cout << "Size sau pop: " << size() << endl;
    cout << "Empty: " << isempty() << endl;

    while (!isempty()) {
        pop();
    }

    return 0;
}