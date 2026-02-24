#include <stdio.h>
#include <stdlib.h>

int main() {

    /* -------------------------------------------------------
     * DIFFERENCE BETWEEN malloc() AND calloc():
     *
     * 1. INITIALIZATION:
     *    - malloc(size) allocates raw memory — the contents
     *      are uninitialized (garbage values).
     *    - calloc(n, size) allocates memory for n elements
     *      and zero-initializes every byte automatically.
     *
     * 2. SIGNATURE / ARGUMENTS:
     *    - malloc takes a single argument: total bytes needed.
     *      e.g.  malloc(n * sizeof(int))
     *    - calloc takes two arguments: number of elements
     *      and size of each element.
     *      e.g.  calloc(n, sizeof(int))
     * ------------------------------------------------------- */

    
    int *pN = (int *)malloc(sizeof(int));
    if (pN == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return 1;
    }

    printf("Enter an integer N: ");
    scanf("%d", pN);
    int N = *pN;          
    printf("N = %d stored at address %p\n\n", *pN, (void *)pN);
    free(pN);             
    pN = NULL;

    int *arr = (int *)calloc(N, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "calloc failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = i * i;
    }

    int newSize = 2 * N;
    int *tmp = (int *)realloc(arr, newSize * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "realloc failed.\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    for (int i = N; i < newSize; i++) {
        arr[i] = i * i;
    }

    printf("Array of %d square numbers:\n", newSize);
    for (int i = 0; i < newSize; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;
    printf("\nMemory released. Program ended successfully.\n");

    return 0;
}