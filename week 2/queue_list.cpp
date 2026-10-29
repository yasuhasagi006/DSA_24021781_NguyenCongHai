
#include <iostream>
using namespace std;

int a[100];
int n = 0;

bool isempty() {
    return n == 0;
}

void enqueue(int x) {
    if (n >= 100) {
        return;
    }

    a[n] = x;
    n++;
}

int dequeue() {
    if (isempty()) {
        return -1;
    }

    int x = a[0];

    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;
    return x;
}

int peek() {
    if (isempty()) {
        return -1;
    }

    return a[0];
}

int size() {
    return n;
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

    return 0;
}
