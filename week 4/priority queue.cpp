#include <iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int arr[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i) {
        swap(arr, largest, i);
        heapify(arr, n, largest);
    }
}

void push(int arr[], int &n, int x){
    int i = n;
    arr[n] = x;
    n++;
    while (i > 0 && arr[i] > arr[(i - 1)/2]){
        swap(arr, i, (i - 1)/2);
        i = (i - 1)/2;
    }
}

bool isempty(int arr[], int n){
    return n==0;
}


int top(int arr[], int n){
    if (!isempty(arr, n)){
    return arr[0];
    }
    return -1;
}

void pop(int arr[], int &n){
    if (n==0){
        return;
    }
    arr[0] = arr[n - 1];
    n--;
    if (n > 0){
        heapify(arr, n, 0);
    }
}

int size(int arr[], int n){
    return n;
}

int main(){
    int a[100];
    int n = 0;
    push(a, n, 10);
    push(a, n, 20);
    push(a, n, 5);
    push(a, n, 2);
    push(a, n, 1);
    push(a, n, 6);
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << top(a, n) << endl;
    cout << size(a, n)<< endl;
    pop(a, n);
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
