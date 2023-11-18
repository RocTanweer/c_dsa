#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = 0;

    int tempArrSize = r - l + 1;

    int temp[tempArrSize];

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m)
    {
        temp[k++] = arr[i++];
    }

    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    k = 0;

    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[k++];
    }
    printArr(temp, tempArrSize);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(int argc, char const *argv[])
{
    int size = 10;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }

    printArr(arr, size);

    mergeSort(arr, 0, 9);

    printArr(arr, size);

    return 0;
}
