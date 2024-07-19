// #include <stdio.h>
// #include<stdlib.h>
// void swap(int *x,int *y)
// {
//  int temp=*x;
//  *x=*y;
//  *y=temp;
// }
// int partition(int A[],int l,int h)
// {
//  int pivot=A[l];
//  int i=l,j=h;

//  do
//  {
//  do{i++;}while(A[i]<=pivot);
//  do{j--;}while(A[j]>pivot);

//  if(i<j)swap(&A[i],&A[j]);
//  }while(i<j);

//  swap(&A[l],&A[j]);
//  return j;
// }
// void QuickSort(int A[],int l,int h)
// {
//  int j;

//  if(l<h)
//  {
//  j=partition(A,l,h);
//  QuickSort(A,l,j);
//  QuickSort(A,j+1,h);
//  }
// }
// int main()
// {
//  int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
// QuickSort(A,0,n);

//  for(i=0;i<10;i++)
//  printf("%d ",A[i]);
//  printf("\n");

//  return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        do { i++; } while (A[i] <= pivot);
        do { j--; } while (A[j] > pivot);

        if (i < j) swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h) {
    int j;

    if (l < h) {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main() {
    int n, i;

    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int *A = (int *)malloc((n + 1) * sizeof(int)); // Allocate memory dynamically
    if (A == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    A[n] = __INT_MAX__; // Sentinel value

    // Start timing
    clock_t start = clock();

    QuickSort(A, 0, n);

    // End timing
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Time taken to sort the array: %f seconds\n", time_taken);

    free(A); // Free allocated memory
    return 0;
}
