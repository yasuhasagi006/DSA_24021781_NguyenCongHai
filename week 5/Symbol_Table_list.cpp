
#include <iostream>
#include <cstring>
using namespace std;

struct Symbol {
    char name[50];
    int value;
};

const int MAX = 100;

bool isempty(int n) {
    return n == 0;
}

int size(int n) {
    return n;
}

int search(Symbol arr[], int n, const char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(Symbol arr[], int &n, const char name[], int value) {
    if (n >= MAX) {
        cout << "Symbol Table đã đầy!\n";
        return;
    }

    if (search(arr, n, name) != -1) {
        cout << "Symbol đã tồn tại!\n";
        return;
    }

    strcpy(arr[n].name, name);
    arr[n].value = value;
    n++;
}

void update(Symbol arr[], int n, const char name[], int value) {
    int pos = search(arr, n, name);

    if (pos == -1) {
        cout << "Không tìm thấy Symbol!\n";
        return;
    }

    arr[pos].value = value;
}

void remove(Symbol arr[], int &n, const char name[]) {
    int pos = search(arr, n, name);

    if (pos == -1) {
        cout << "Không tìm thấy Symbol!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

void display(Symbol arr[], int n) {
    if (isempty(n)) {
        cout << "Symbol Table trống!\n";
        return;
    }

    cout << "\nNAME\tVALUE\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << "\t"
             << arr[i].value << endl;
    }
}

int main() {
    Symbol arr[MAX];
    int n = 0;

    insert(arr, n, "x", 10);
    insert(arr, n, "y", 20);
    insert(arr, n, "total", 30);

    display(arr, n);

    cout << "\nSearch x: "
         << search(arr, n, "x") << endl;

    update(arr, n, "x", 100);

    remove(arr, n, "y");

    cout << "\nSau cập nhật và xóa:\n";
    display(arr, n);

    cout << "\nSize: " << size(n);

    return 0;
}
