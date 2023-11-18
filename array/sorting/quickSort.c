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

int partitionPosition(int arr[], int l, int h)
{
    int i = l + 1, j = h, pivot = arr[l];

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= j)
        {
            i++;
        }

        while (arr[j] > pivot && i < j)
        {
            j--;
        }

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    int temp = arr[j];
    arr[j] = pivot;
    arr[l] = temp;
    return j;
}

void quickSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int part_pos = partitionPosition(arr, l, r);

        quickSort(arr, l, part_pos);
        quickSort(arr, part_pos + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int size = 5;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }

    printArr(arr, size);

    quickSort(arr, 0, size - 1);

    printArr(arr, size);

    return 0;
}
