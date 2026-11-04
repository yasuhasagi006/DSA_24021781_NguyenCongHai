#include <iostream>
using namespace std;

int partition(int a[], int thap, int cao) {
    int pivot = a[cao];
    int i = (thap - 1);

    for (int j = thap; j <= cao - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[cao]);
    return (i + 1);
}

void quickSort(int a[], int thap, int cao) {
    if (thap < cao) {
        int pi = partition(a, thap, cao);
        quickSort(a, thap, pi - 1);
        quickSort(a, pi + 1, cao);
    }
}

int main()
{
    int a[6] = {6, 18, 36, 12, 3, 34};
    int n = 6;
    quickSort(a, 0, n - 1);
    for (int i = 0; i< n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}