#include <iostream>

using namespace std;

void quickSort(int a[], int low, int high)
{
    if (low >= high) {
        return;
    }
    int pivot = a[(low + high) / 2];
    int left = low;
    int right = high;
    while (left <= right) {
        while (a[left] < pivot) {
            left++;
        }
        while (a[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    quickSort(a, low, pivot-1);
    quickSort(a, pivot+1, high);
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
