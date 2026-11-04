#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        int min_index = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i){
            swap(a[min_index], a[i]);
        }
    }
}

void bubble_sort(int a[], int n){
    for (int i=0; i<n - 1; i++){
        for (int j=i+1;j<n;j++){
            if (a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

void insertion_sort(int a[], int n){
    for (int i=1; i<n; i++){
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main(){
    int a[5] = {0, 1, 6, 5, 4};
    int b[5] = {3, 56, 41, 22, 54};
    int c[5] = {5, 53, 36, 18, 12};
    selection_sort(a, 5);
    for (int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    bubble_sort(b, 5);
    for (int j = 0; j < 5; j++){
        cout << b[j] << " ";
    }
    cout << endl;
    insertion_sort(c, 5);
    for (int k = 0; k < 5; k++){
        cout << c[k] << " ";
    }
    return 0;
}