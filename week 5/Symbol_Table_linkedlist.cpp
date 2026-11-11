
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char name[50];
    int value;
    Node* next;
};

bool isempty(Node* head) {
    return head == NULL;
}

int size(Node* head) {
    int count = 0;
    Node* p = head;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

Node* search(Node* head, const char name[]) {
    Node* p = head;

    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void insert(Node* &head, const char name[], int value) {
    if (search(head, name) != NULL) {
        cout << "Symbol đã tồn tại!\n";
        return;
    }

    Node* newNode = new Node;

    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

void update(Node* head, const char name[], int value) {
    Node* p = search(head, name);

    if (p == NULL) {
        cout << "Không tìm thấy Symbol!\n";
        return;
    }

    p->value = value;
}

void remove(Node* &head, const char name[]) {
    if (head == NULL) {
        return;
    }

    Node* p = head;
    if (strcmp(head->name, name) == 0) {
        head = head->next;
        delete p;
        return;
    }
    while (p->next != NULL &&
           strcmp(p->next->name, name) != 0) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Không tìm thấy Symbol!\n";
        return;
    }
    Node* temp = p->next;
    p->next = temp->next;

    delete temp;
}

void display(Node* head) {
    if (isempty(head)) {
        cout << "Symbol Table trống!\n";
        return;
    }

    cout << "\nNAME\tVALUE\n";

    Node* p = head;

    while (p != NULL) {
        cout << p->name << "\t"
             << p->value << endl;

        p = p->next;
    }
}

void clear(Node* &head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    insert(head, "x", 10);
    insert(head, "y", 20);
    insert(head, "total", 30);

    display(head);

    Node* p = search(head, "x");

    if (p != NULL) {
        cout << "\nTìm x: " << p->value << endl;
    }

    update(head, "x", 100);

    remove(head, "y");

    cout << "\nSau cập nhật và xóa:\n";
    display(head);

    cout << "\nSize: " << size(head);

    clear(head);

    return 0;
}
