#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int busquedaSecuencia(int *array, int tam, int elem) {
    for (int i = 0; i < tam; i++) {
        if (array[i] == elem) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int busquedaBinaria(int *array, int tam, int elem) {
    int left = 0, right = tam - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == elem) {
            return mid;  // Element found
        }
        if (array[mid] < elem) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Element not found
}

void ordenacionDirecta(int *array, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int *array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void mergeSort(int *array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}


// Include algorithm function declarations
int main() {
    int n = 2147483;  // Adjust the size for practical purposes in a testing environment
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Initialize the array with random values
    for (int j = 0; j < n; j++) {
        array[j] = rand() % n;
    }

    clock_t t0, t1;
    double tiempo;

    // Sequential Search
    t0 = clock();
    busquedaSecuencia(array, n, -1);
    t1 = clock();
    tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Secuencial Search for size %d: %f segundos\n", n, tiempo);

    // Binary Search (Array needs to be sorted)
    qsort(array, n, sizeof(int), compare);
    t0 = clock();
    busquedaBinaria(array, n, -1);
    t1 = clock();
    tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Binary Search for size %d: %f segundos\n", n, tiempo);

    // Direct Sorting
    // Re-initialize the array with random values
    for (int j = 0; j < n; j++) {
        array[j] = rand() % n;
    }
    t0 = clock();
    ordenacionDirecta(array, n);
    t1 = clock();
    tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Direct Sorting for size %d: %f segundos\n", n, tiempo);

    // Re-initialize the array with random values
    for (int j = 0; j < n; j++) {
        array[j] = rand() % n;
    }

    // Merge Sort
    t0 = clock();
    mergeSort(array, 0, n - 1);
    t1 = clock();
    tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Merge Sort for size %d: %f segundos\n", n, tiempo);

    free(array);

    return 0;
}

