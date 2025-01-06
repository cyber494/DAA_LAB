#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int lo, int mid, int hi) {
   int p1 = lo;
   int p2 = mid + 1;
   int k = 0;
   int temp[hi-lo+1];
   while(p1<=mid && p2<=hi){
        if(arr[p1]<=arr[p2]){
            temp[k] = arr[p1];
            k++;
            p1++;
        }else{
            temp[k] = arr[p2];
            k++;
            p2++;
        }
   }
    while(p1<=mid){
         temp[k] = arr[p1];
         k++;
         p1++;
    }
    while(p2<=hi){
         temp[k] = arr[p2];
         k++;
         p2++;
    }
    for(int i=0;i<hi-lo+1;i++){
        arr[lo+i] = temp[i];
    }
}

void mergeSort(int arr[], int lo, int hi) {
    if(lo==hi){
        return;
    }
    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is\n");
    printArray(arr, arr_size);

    return 0;
}
// output:
// Given array is
// 12 11 13 5 6 7 

// Sorted array is
// 5 6 7 11 12 13 