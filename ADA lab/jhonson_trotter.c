#include <stdio.h>
#include <stdbool.h>

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int searchIndex(int a[], bool dir[], int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if ((dir[a[i] - 1] && i != n - 1 && a[i] > a[i + 1]) ||
            (!dir[a[i] - 1] && i != 0 && a[i] > a[i - 1])) {
            if (index == -1 || a[i] > a[index])
                index = i;
        }
    }
    return index;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseDirections(int a[], bool dir[], int largest, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > largest)
            dir[a[i] - 1] = !dir[a[i] - 1];
    }
}

void johnsonTrotter(int n) {
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = false;
    }

    printPermutation(a, n);

    int index;
    while ((index = searchIndex(a, dir, n)) != -1) {
        int largest = a[index];

        if (dir[a[index] - 1])
            swap(&a[index], &a[index + 1]);
        else
            swap(&a[index], &a[index - 1]);

        reverseDirections(a, dir, largest, n);

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
