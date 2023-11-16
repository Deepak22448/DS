#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int idx = low, pivot = arr[high];

    for (int i = low; i <= high; i++)
    {
        int currentElem = arr[i];

        if (pivot > currentElem)
            swap(arr, idx++, i);
    }

    swap(arr, idx, high);

    return idx;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivoteIdx = partition(arr, low, high);

    quickSort(arr, low, pivoteIdx - 1);
    quickSort(arr, pivoteIdx + 1, high);
}

void printArr(int arr[])
{
    for (int i = 0; i < MAX_LEN; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    printf("---- QUICK SORT ----\n");
    int arr[MAX_LEN] = {90, 4, 2, 2, 1, 5, 0, 1, 3, 99};
    printf("[UNSORTED ARRAY] : ");
    printArr(arr);

    int low = 0, high = MAX_LEN - 1;
    quickSort(arr, low, high);
    printf("[SORTED ARRAY] : ");
    printArr(arr);

    return 0;
}
