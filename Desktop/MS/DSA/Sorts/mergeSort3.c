#include<stdio.h>

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub - lb + 1];

    while (i <= mid && j <= ub) {
        if (a[j] > a[i]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= ub) {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int l = lb; l <= ub; l++) {
        a[l] = b[l - lb];
    }
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[10] = {10, 1, 7, 6, 22, 1, 33, 6, 0, 1};
    int lb = 0;
    int ub = 9;
    printf("The given array is: ");
    for (int i = 0; i <= ub; i++) {
        printf("%d ", a[i]);
    }
    mergeSort(a, lb, ub);
    printf("\nThe sorted array is: ");
    for (int i = 0; i <= ub; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
