#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

void merge(int arr[], int low, int mid, int high)
{
    int idx1 = low, idx2 = mid + 1;
    int temp[high - low + 1];
    int j = 0;

    while (idx1 <= mid && idx2 <= high)
    {
        if (arr[idx1] <= arr[idx2])
            temp[j++] = arr[idx1++];
        else
            temp[j++] = arr[idx2++];
    }

    while (idx1 <= mid)
        temp[j++] = arr[idx1++];

    while (idx2 <= high)
        temp[j++] = arr[idx2++];

    for (int i = low, j = 0; i <= high && j <= high - low; i++, j++)
        arr[i] = temp[j];
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void printArr(int arr[])
{
    for (int i = 0; i < MAX_LEN; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[MAX_LEN] = {90, 4, 2, 2, 1, 5, 0, 1, 3, 99};
    printf("[UNSORTED ARRAY] : ");
    printArr(arr);

    int low = 0, high = MAX_LEN - 1;
    mergeSort(arr, low, high);
    printf("[SORTED ARRAY] : ");
    printArr(arr);

    return 0;
}
