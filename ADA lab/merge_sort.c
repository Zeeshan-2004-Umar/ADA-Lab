// #include <stdio.h>
// #define max 20

// void simplemerge(int a[max], int low, int high, int mid) {
//     int j = mid + 1;
//     int i = low;
//     int k = 0;
//     int c[max];
//     while (i <= mid && j <= high) {
//         if (a[i] < a[j])
//             c[k++] = a[i++];
//         else
//             c[k++] = a[j++];
//     }
//     while (i <= mid) { c[k++] = a[i++]; }
//     while (j <= high) { c[k++] = a[j++]; }
//     for (k = 0; k <= high - low; k++) { a[low + k] = c[k]; }
// }

// void mergesort(int a[max], int low, int high) {
//     if (low < high) {
//         int mid = (low + high) / 2;
//         mergesort(a, low, mid);
//         mergesort(a, mid + 1, high);
//         simplemerge(a, low, high, mid);
//     }
// }

// int main() {
//     int n;
//     int a[max];
//     int k;
//     printf("Enter number of array elements: ");
//     scanf("%d", &n);
//     printf("Enter array elements: ");
//     for (k = 0; k < n; k++) { scanf("%d", &a[k]); }
//     mergesort(a, 0, n - 1);
//     printf("Sorted array elements: ");
//     for (k = 0; k < n; k++) { printf("%d ", a[k]); }
//     printf("\n");
//     return 0;
// }

#include <stdio.h>
#include <time.h> // Include the time.h library
#define max 20

void simplemerge(int a[max], int low, int high, int mid) {
    int j = mid + 1;
    int i = low;
    int k = 0;
    int c[max];
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid) { c[k++] = a[i++]; }
    while (j <= high) { c[k++] = a[j++]; }
    for (k = 0; k <= high - low; k++) { a[low + k] = c[k]; }
}

void mergesort(int a[max], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        simplemerge(a, low, high, mid);
    }
}

int main() {
    int n;
    int a[max];
    int k;
    printf("Enter number of array elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (k = 0; k < n; k++) { scanf("%d", &a[k]); }

    // Start timing
    clock_t start = clock();

    mergesort(a, 0, n - 1);

    // End timing
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array elements: ");
    for (k = 0; k < n; k++) { printf("%d ", a[k]); }
    printf("\n");

    printf("Time taken to sort the array: %f seconds\n", time_taken);

    return 0;
}

