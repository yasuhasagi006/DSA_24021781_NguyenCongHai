#include <iostream>
using namespace std;

int a[100];
int n = 0;

bool isempty() {
    return n == 0;
}

void push(int x) {
    if (n >= 100) {
        return;
    }

    a[n] = x;
    n++;
}

int pop() {
    if (isempty()) {
        return -1;
    }

    n--;
    return a[n];
}

int size() {
    return n;
}

int top() {
    if (isempty()) {
        return -1;
    }

    return a[n - 1];
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

    return 0;
}
