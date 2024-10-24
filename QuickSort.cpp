// Quicksort algorithm
#include <iostream>
using namespace std;

void swap(int a[], int low, int high) {
    int t;
    t = a[low];
    a[low] = a[high];
    a[high] = t;
}

void QuickSort(int a[], int low, int high) {
    int pivot, i, j;
    if (low < high) {
        pivot = a[low];
        i = low;
        j = high+1;

        do {
            do{i++;}while (a[i] < pivot);
            do{j--;}while (a[j] > pivot);

            if (i <j) {
                swap(a, i, j);
                
            }
        } while (i <j);
    if(i>j)
    {
        swap(a,low,j);
    }

            QuickSort(a, low, j-1);
 
            QuickSort(a, j+1, high);
    }
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1);

    cout << "Sorted array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
