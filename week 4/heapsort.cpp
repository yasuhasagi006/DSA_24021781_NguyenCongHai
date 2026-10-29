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

void heapsort(int arr[], int n){
    for (int i = n/2 - 1; i>=0 ; i--){
        heapify(arr, n, i);
    }
    for (int j = n-1;j >= 0; j--){
        swap(arr, 0, j);
        heapify(arr, j, 0);
    }
}

int main(){
    int a[5] = {2, 36, 18, 55, 4};
    heapsort(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
