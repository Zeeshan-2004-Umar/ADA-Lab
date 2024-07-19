#include <stdio.h>
#include <stdlib.h>

void Insert(int A[], int n) {
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n) {
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1) {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else
            break;
    }
    return val;
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *H = (int *)malloc((n + 1) * sizeof(int));
    if (H == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    H[0] = 0; // First element is dummy to use 1-based indexing

    printf("Enter the elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    for (i = 2; i <= n; i++) {
        Insert(H, i);
    }

    for (i = n; i > 1; i--) {
        Delete(H, i);
    }

    printf("Sorted elements: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    free(H);
    return 0;
}

