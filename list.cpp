#include <iostream>
using namespace std;

 int a[100];
 int n = 0;

void duyetxuoi() {
    for (int i = 0; i<n; i++) {
        if (i == n-1) {
            cout << a[i] << endl;
        }
        else {
            cout << a[i] << ", ";
        }
    }
}

void duyetnguoc() {
     for (int i = n-1; i>=0; i--) {
        if (i == 0) {
            cout << a[i] << endl;
        }
        else {
            cout << a[i] << ", ";
        }
    }
}

void chendau(int x) {
    if (n>=100) {
        return;
    }
    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = x;
    n++;
}

void chencuoi(int x) {
    a[n] = x;
    n++;
}

void chenvitrik(int x, int k) {
    if (n >= 100 || k > n || k < 0) {
        return;
    }
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
}

void xoadau(){
    if (n <= 0) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void xoacuoi() {
    if (n <= 0) {
        return;
    }
    n--;
}

void xoavitrik(int k) {
    if (n == 0 || k >= n || k < 0) {
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

int main()
{
    xoadau();
    xoacuoi();
    xoavitrik(26);
    chendau(32);
    chencuoi(32);
    chenvitrik(18, 36);
    duyetxuoi();
    duyetnguoc();
    
}