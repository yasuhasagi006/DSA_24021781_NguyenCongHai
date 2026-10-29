#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taonode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void duyetxuoi(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void duyetnguoc(Node* head) {
    if (head == nullptr){
        return;
    }
    duyetnguoc(head->next);
    cout << head->data << " ";
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

void chencuoi(Node* &head, Node* &tail, int x) {
    Node* newNode = taonode(x);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void chenvitrik(Node* &head, Node* &tail, int x, int k) {
    if (k < 0){
        return;
    }
    if (k == 0) {
        chendau(head, tail, x);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr){
        return;
    }
    if (temp == tail) {
        chencuoi(head, tail, x);
        return;
    }
    Node* newNode = taonode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void xoadau(Node* &head, Node* &tail) {
    if (head == nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

void xoacuoi(Node* &head, Node* &tail) {
    if (head == nullptr){
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void xoavitrik(Node* &head, Node* &tail, int k) {
    if (head == nullptr || k < 0){
        return;
    }
    if (k == 0) {
        xoadau(head, tail);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr){
        return;
    }
    if (temp->next == tail) {
        xoacuoi(head, tail);
        return;
    }
    Node* p = temp->next;
    temp->next = p->next;
    delete p;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    chendau(head, tail, 32);
    chencuoi(head, tail, 50);    
    chendau(head, tail, 10);      
    chenvitrik(head, tail, 99, 1); 
    xoadau(head, tail); 
    xoacuoi(head, tail);
    xoavitrik(head, tail, 1); 
    cout << "Duyet xuoi: ";
    duyetxuoi(head);
    cout << endl;
    cout << "Duyet nguoc: ";
    duyetnguoc(head);
    return 0;
}
